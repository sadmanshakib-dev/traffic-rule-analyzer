%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule_engine.h"

void yyerror(const char *s);
int yylex();

/* Global Variables */

char vehicle_type[20];
char plate_number[20];

int speed = 0;
int limit = 0;

char signal_status[10] = "";
char seatbelt_status[10] = "";
int fine = 0;

char zone_type[20] = "";
char helmet_status[10] = "";
char time_type[10] = "";
char alcohol_status[10] = "";
%}

%union {
    int num;
    char* str;
}

%token CASE VEHICLE SPEED LIMIT SIGNAL SEATBELT
%token CAR BIKE TRUCK
%token RED GREEN
%token ON OFF
%token LBRACE RBRACE

%token <num> NUMBER

%token ZONE
%token SCHOOL HIGHWAY
%token HELMET
%token TIME
%token DAY NIGHT
%token ALCOHOL
%token YES NO

/* NEW TOKENS */

%token PLATE
%token <str> PLATENUM

%%

program:
      program case_block
    | case_block
    ;

case_block:

      CASE LBRACE statements RBRACE
      {
        evaluate_case();

        /* Reset variables */

        fine = 0;
        speed = 0;
        limit = 0;

        strcpy(vehicle_type, "");
        strcpy(plate_number, "");

        strcpy(signal_status, "");
        strcpy(seatbelt_status, "");
        strcpy(helmet_status, "");
        strcpy(time_type, "");
        strcpy(zone_type, "");
        strcpy(alcohol_status, "");
      }

    /* ===== Cleaner Error Recovery ===== */

    | CASE LBRACE error RBRACE
      {
        printf("\nSyntax Error: Invalid rule format inside CASE block\n");
        printf("Hint: Check missing keywords or numbers\n");
        printf("Skipping this case...\n\n");

        fine = 0;
        speed = 0;
        limit = 0;

        strcpy(vehicle_type, "");
        strcpy(plate_number, "");

        strcpy(signal_status, "");
        strcpy(seatbelt_status, "");
        strcpy(helmet_status, "");
        strcpy(time_type, "");
        strcpy(zone_type, "");
        strcpy(alcohol_status, "");

        yyerrok;
      }
    ;

statements:
      statements statement
    | statement
    ;

statement:

      VEHICLE CAR   { strcpy(vehicle_type, "CAR"); }
    | VEHICLE BIKE  { strcpy(vehicle_type, "BIKE"); }
    | VEHICLE TRUCK { strcpy(vehicle_type, "TRUCK"); }

    /* PLATE RULE */

    | PLATE PLATENUM
      {
        strcpy(plate_number, $2);
        free($2);
      }

    | SPEED NUMBER  { speed = $2; }
    | LIMIT NUMBER  { limit = $2; }

    | SIGNAL RED    { strcpy(signal_status, "RED"); }
    | SIGNAL GREEN  { strcpy(signal_status, "GREEN"); }

    | SEATBELT ON   { strcpy(seatbelt_status, "ON"); }
    | SEATBELT OFF  { strcpy(seatbelt_status, "OFF"); }

    | ZONE SCHOOL   { strcpy(zone_type, "SCHOOL"); }
    | ZONE HIGHWAY  { strcpy(zone_type, "HIGHWAY"); }

    | HELMET ON     { strcpy(helmet_status, "ON"); }
    | HELMET OFF    { strcpy(helmet_status, "OFF"); }

    | TIME DAY      { strcpy(time_type, "DAY"); }
    | TIME NIGHT    { strcpy(time_type, "NIGHT"); }

    | ALCOHOL YES   { strcpy(alcohol_status, "YES"); }
    | ALCOHOL NO    { strcpy(alcohol_status, "NO"); }
    ;

%%

void yyerror(const char *s)
{
    printf("\nSyntax Error: Invalid Traffic Rule Syntax\n");
}