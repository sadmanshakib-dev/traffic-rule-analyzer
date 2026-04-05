#include <stdio.h>
#include <string.h>
#include "rule_engine.h"

static int case_number = 1;
static int total_cases = 0;
static int total_fine_collected = 0;

/* STORE ALL PREVIOUS PLATES */
static char plate_history[100][20];
static int plate_count = 0;

/* PREVIOUS CASE STORAGE (duplicate detection) */
static char previous_plate[20] = "";
static int previous_speed = -1;
static int previous_limit = -1;

void print_summary() {
printf("\n====== FINAL SUMMARY ======\n");
printf("Total Cases: %d\n", total_cases);
printf("Total Fine Collected: %d\n", total_fine_collected);
printf("===========================\n");
}

void evaluate_case() {

FILE *report = fopen("report.txt", "a");
if(report == NULL){
    printf("Error opening report file\n");
    return;
}

printf("\n--- Traffic Report (Case %d) ---\n", case_number);

fprintf(report,"\n====================================\n");
fprintf(report,"Case ID : %d\n", case_number);
fprintf(report,"------------------------------------\n");

/* DUPLICATE CASE */

if(
    strcmp(previous_plate, plate_number) == 0 &&
    previous_speed == speed &&
    previous_limit == limit
  )
{
    printf("Duplicate Case Detected\n");
    printf("Case Skipped\n");

    fprintf(report,"Duplicate Case Detected\n");
    fprintf(report,"Case Skipped\n");
    fprintf(report,"------------------------------------\n");

    fclose(report);
    case_number++;
    return;
}

/* INPUT VALIDATION */

if(strlen(vehicle_type) == 0){

    printf("Error: Vehicle type missing\n");

    fprintf(report,"Error: Vehicle type missing\n");
    fprintf(report,"Case Skipped\n");
    fprintf(report,"------------------------------------\n");

    fclose(report);
    case_number++;
    return;
}

if(strlen(plate_number) == 0){

    printf("Error: Plate number missing\n");

    fprintf(report,"Error: Plate number missing\n");
    fprintf(report,"Case Skipped\n");
    fprintf(report,"------------------------------------\n");

    fclose(report);
    case_number++;
    return;
}

if(limit <= 0){

    printf("Error: Invalid speed limit\n");

    fprintf(report,"Error: Invalid speed limit\n");
    fprintf(report,"Case Skipped\n");
    fprintf(report,"------------------------------------\n");

    fclose(report);
    case_number++;
    return;
}

if(speed < 0){

    printf("Error: Speed cannot be negative\n");

    fprintf(report,"Error: Speed cannot be negative\n");
    fprintf(report,"Case Skipped\n");
    fprintf(report,"------------------------------------\n");

    fclose(report);
    case_number++;
    return;
}

/* BASIC INFO */

printf("Vehicle : %s\n", vehicle_type);
printf("Plate   : %s\n", plate_number);
printf("Speed   : %d\n", speed);
printf("Limit   : %d\n", limit);

fprintf(report,"Vehicle : %s\n", vehicle_type);
fprintf(report,"Plate   : %s\n\n", plate_number);

fprintf(report,"Speed   : %d km/h\n", speed);
fprintf(report,"Limit   : %d km/h\n\n", limit);

fprintf(report,"Violations\n");
fprintf(report,"----------\n");

int diff = speed - limit;
int fine = 0;

/* SPEED RULE */

if(diff > 0){

    int speed_fine;

    if(diff <= 10)
        speed_fine = 1000;
    else if(diff <= 20)
        speed_fine = 2000;
    else
        speed_fine = 4000;

    if(strcmp(zone_type,"SCHOOL")==0){

        speed_fine *= 2;

        printf("Violation: Over Speed in School Zone (%d km/h over) - Fine: %d BDT\n", diff, speed_fine);
        fprintf(report,"Over Speed in School Zone (%d km/h over) - Fine: %d BDT\n", diff, speed_fine);

    }
    else if(strcmp(zone_type,"HIGHWAY")==0){

        speed_fine = speed_fine * 0.75;

        printf("Violation: Over Speed on Highway (%d km/h over) - Fine: %d BDT\n", diff, speed_fine);
        fprintf(report,"Over Speed on Highway (%d km/h over) - Fine: %d BDT\n", diff, speed_fine);

    }
    else{

        printf("Violation: Over Speed (%d km/h over) - Fine: %d BDT\n", diff, speed_fine);
        fprintf(report,"Over Speed (%d km/h over) - Fine: %d BDT\n", diff, speed_fine);

    }

    fine += speed_fine;
}

/* NIGHT RULE */

if(strcmp(time_type,"NIGHT")==0){

    printf("Violation: Night Driving Extra Charge - Fine: 1000 BDT\n");
    fprintf(report,"Night Driving Extra Charge - Fine: 1000 BDT\n");

    fine += 1000;
}

/* ALCOHOL */

if(strcmp(alcohol_status,"YES")==0){

    printf("Violation: Drunk Driving - Fine: 5000 BDT\n");
    fprintf(report,"Drunk Driving - Fine: 5000 BDT\n");

    fine += 5000;
}

/* SIGNAL */

if(strcmp(signal_status,"RED")==0){

    printf("Violation: Red Signal Jump - Fine: 2000 BDT\n");
    fprintf(report,"Red Signal Jump - Fine: 2000 BDT\n");

    fine += 2000;
}

/* SEATBELT */

if(strcmp(vehicle_type,"CAR")==0 && strcmp(seatbelt_status,"OFF")==0){

    printf("Violation: No Seatbelt - Fine: 2000 BDT\n");
    fprintf(report,"No Seatbelt - Fine: 2000 BDT\n");

    fine += 2000;
}

/* HELMET */

if(strcmp(vehicle_type,"BIKE")==0 && strcmp(helmet_status,"OFF")==0){

    printf("Violation: No Helmet - Fine: 1500 BDT\n");
    fprintf(report,"No Helmet - Fine: 1500 BDT\n");

    fine += 1500;
}

/* ===== REPEAT OFFENDER CHECK ===== */

int repeat = 0;

for(int i=0;i<plate_count;i++){
    if(strcmp(plate_history[i], plate_number)==0){
        repeat = 1;
        break;
    }
}

if(repeat){

    printf("Repeat Offender: Fine Increased by 50%%\n");
    fprintf(report,"Repeat Offender (Fine +50%%)\n");

    fine = fine * 1.5;
}

/* SAVE PLATE INTO HISTORY */

strcpy(plate_history[plate_count], plate_number);
plate_count++;

/* LICENSE RULE */

if(fine > 8000){

    printf("License Suspended\n");
    fprintf(report,"License Suspended\n");
}

printf("Total Fine : %d\n", fine);

fprintf(report,"\nTotal Fine : %d BDT\n", fine);
fprintf(report,"------------------------------------\n");

total_cases++;
total_fine_collected += fine;

/* SAVE PREVIOUS CASE */

strcpy(previous_plate, plate_number);
previous_speed = speed;
previous_limit = limit;

fclose(report);

case_number++;

}