#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;
    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"generate", required_argument, 0, 'g'},
        {"sort", no_argument, 0, 's'},
        {"type", required_argument, 0, 't'},
        {"out", required_argument, 0, 'o'},
        {"in", required_argument, 0, 'i'},
        {"print", no_argument, 0, 'P'},
        {0, 0, 0, 0} // Завершающий элемент
    };
    int crutch_1 = 0;
    char outfile[50];
    char infile[50];    

    while ((opt = getopt_long(argc, argv, "hgstoiP:", long_options, NULL)) != -1) {
        switch (opt)
        {
        case 'o':
            crutch_1 = 1;
            snprintf(outfile, 50, optarg);
            break;
        case 'i':
            crutch_1 = 1;
            snprintf(infile, 50, optarg);
        default:
            snprintf(outfile, 50, "NO_FILE");
            snprintf(infile, 50, "NO_FILE");
            break;
        }
    }    


    while ((opt = getopt_long(argc, argv, "hgstoiP:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printf("A program running with the  --generate N  or  -g  N flag generates random data (number of N lines).\n");
                printf("If the  --out=output.csv  or  -o output.csv  flag is specified, the output is performed in the appropriate file in the format of comma-separated values (CSV).\n");
                printf("A program running with the  --sort  or  -s  flag reads the data and sorts it and outputs the sorted.\n");
                printf("If the  --in=data.csv  or  -i data.csv  flag is specified, input is performed from the corresponding file.\n");
                printf("sort in ascending order if the --type=asc or -t A flag is specified. If the --type=desc or -t D flag is specified, the sorting is performed in descending order.\n");
                printf("A program running with the  --print  or  -P  flag reads the data and outputs it in a fixed-width table format.\n");
                break;
            case 'g':
                system("./vector.c");
                break;
            default:
                printf("Please enter something(i recommenden -h).\n");
        }
    }
    return 0;
}
