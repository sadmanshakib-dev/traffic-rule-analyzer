#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
int yyparse();
void print_summary();

int main(int argc, char *argv[])
{
    /* ===== CHECK INPUT ARGUMENT ===== */

    if (argc < 2)
    {
        printf("Usage: traffic.exe <input_file>\n");
        return 1;
    }

    /* ===== RESET REPORT FILE ===== */

    FILE *report = fopen("report.txt", "w");

    if (report == NULL)
    {
        printf("Error: Cannot initialize report file\n");
        return 1;
    }

    /* ===== CLEAN REPORT HEADER ===== */

    fprintf(report, "========================================\n");
    fprintf(report, "        TRAFFIC RULE ANALYZER REPORT\n");
    fprintf(report, "========================================\n\n");

    fclose(report);

    printf("=== Traffic Rule Analyzer ===\n");
    printf("Report file initialized\n\n");

    /* ===== OPEN INPUT FILE ===== */

    yyin = fopen(argv[1], "r");

    if (yyin == NULL)
    {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    /* ===== START PARSING ===== */

    yyparse();

    fclose(yyin);

    /* ===== PRINT FINAL SUMMARY ===== */

    print_summary();

    printf("\nProgram Finished.\n");

    return 0;
}