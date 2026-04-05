#ifndef RULE_ENGINE_H
#define RULE_ENGINE_H

#define MAX_STR 20
#define SMALL_STR 10

void evaluate_case(void);
void print_summary(void);

/* Shared Global Variables */
extern char vehicle_type[MAX_STR];
extern int speed;
extern int limit;
extern char signal_status[SMALL_STR];
extern char seatbelt_status[SMALL_STR];
extern int fine;
extern char zone_type[MAX_STR];
extern char helmet_status[SMALL_STR];
extern char time_type[SMALL_STR];
extern char alcohol_status[SMALL_STR];
extern char plate_number[20];
#endif