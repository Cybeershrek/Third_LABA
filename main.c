#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>
#include "Universal.h"

char outfile[50];
char infile[50];
int crutch_1 = 0;
int crutch_2 = 0;
int N;

int main(int argc, char *argv[]) {
    int opt;
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"generate", required_argument, 0, 'g'},
        {"sort", no_argument, 0, 's'},
        {"type", required_argument, 0, 't'},
        {"out", required_argument, 0, 'o'},
        {"in", required_argument, 0, 'i'},
        {"print", no_argument, 0, 'p'},
        {0, 0, 0, 0} // Завершающий элемент
    };
    strcpy(outfile, "NO_FILE");
    strcpy(infile, "NO_FILE");
    while ((opt = getopt_long(argc, argv, "oihgstp:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'o':
                crutch_1 = 1;
                strcpy(outfile, optarg);
            break;
            case 'i':
                crutch_2 = 1;
                strcpy(infile, optarg);
                break;
            case 'h':
                printf("A program running with the  --generate N  or  -g  N flag generates random data (number of N lines).\n");
                printf("If the  --out=output.csv  or  -o output.csv  flag is specified, the output is performed in the appropriate file in the format of comma-separated values (CSV).\n");
                printf("A program running with the  --sort  or  -s  flag reads the data and sorts it and outputs the sorted.\n");
                printf("If the  --in=data.csv  or  -i data.csv  flag is specified, input is performed from the corresponding file.\n");
                printf("sort in ascending order if the --type=asc or -t A flag is specified. If the --type=desc or -t D flag is specified, the sorting is performed in descending order.\n");
                printf("A program running with the  --print  or  -p  flag reads the data and outputs it in a fixed-width table format.\n");
                break;
            case 'g':
                int N = atoi(optarg);
                system("C:\\Users\\Default\\PROGA\\Third_LABA\\vector.exe");
                break;
            default:
                printf("Please enter something(i recommenden -h).\n");
                break;
        }
    }
    return 0;
}
