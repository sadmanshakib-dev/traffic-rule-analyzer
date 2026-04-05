%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%%

[A-Za-z0-9]+(-[A-Za-z0-9]+)+    { yylval.str = strdup(yytext); return PLATENUM; }

[0-9]+                          { yylval.num = atoi(yytext); return NUMBER; }

[A-Za-z]+ {

    if(!strcasecmp(yytext,"CASE")) return CASE;
    if(!strcasecmp(yytext,"VEHICLE")) return VEHICLE;
    if(!strcasecmp(yytext,"SPEED")) return SPEED;
    if(!strcasecmp(yytext,"LIMIT")) return LIMIT;
    if(!strcasecmp(yytext,"SIGNAL")) return SIGNAL;
    if(!strcasecmp(yytext,"SEATBELT")) return SEATBELT;

    if(!strcasecmp(yytext,"CAR")) return CAR;
    if(!strcasecmp(yytext,"BIKE")) return BIKE;
    if(!strcasecmp(yytext,"TRUCK")) return TRUCK;

    if(!strcasecmp(yytext,"RED")) return RED;
    if(!strcasecmp(yytext,"GREEN")) return GREEN;

    if(!strcasecmp(yytext,"ON")) return ON;
    if(!strcasecmp(yytext,"OFF")) return OFF;

    if(!strcasecmp(yytext,"ZONE")) return ZONE;
    if(!strcasecmp(yytext,"SCHOOL")) return SCHOOL;
    if(!strcasecmp(yytext,"HIGHWAY")) return HIGHWAY;

    if(!strcasecmp(yytext,"HELMET")) return HELMET;

    if(!strcasecmp(yytext,"TIME")) return TIME;
    if(!strcasecmp(yytext,"DAY")) return DAY;
    if(!strcasecmp(yytext,"NIGHT")) return NIGHT;

    if(!strcasecmp(yytext,"ALCOHOL")) return ALCOHOL;
    if(!strcasecmp(yytext,"YES")) return YES;
    if(!strcasecmp(yytext,"NO")) return NO;

    if(!strcasecmp(yytext,"PLATE")) return PLATE;

    printf("Invalid Token: %s\n", yytext);
}

"{"                             { return LBRACE; }
"}"                             { return RBRACE; }

[ \t\r\n]+                      ;

.                               { printf("Invalid Token: %s\n", yytext); }

%%

int yywrap()
{
    return 1;
}