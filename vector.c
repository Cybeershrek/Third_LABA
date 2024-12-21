#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Universal.h"

int N;
char outfile[50];
int crutch_1;

typedef struct {
    char developer[50];
    char microrion[100];
    char type[50];
    int foundation;
    bool eliva;
    bool garb;
    int count_flat;
    int count_floors;
    int aver_S_flats;
} House;

typedef struct {
    House* data;
    size_t size;
    size_t content;
} Vector;

void init_vec(Vector* vec) {
    vec->data = malloc(sizeof(House) * 10);
    vec->size = 0;
    vec->content = 10;
}

void push_back(Vector* vec, House r) {
    if (vec->size == vec->content) {
        vec->content *= 2;
        vec->data = realloc(vec->data, sizeof(House) * vec->content);
    }
    vec->data[vec->size++] = r;
}

void clear_vec(Vector* vec) {
    free(vec->data);
    vec->size = 0;
    vec->content = 0;
}

void gener(Vector* vec) {
    const char* developers[] = {"GruppaPIK", "ZILART", "MrGroup", "Donstroi"};
    const char* microrions[] = {"Zaton", "Odentsovo", "Arbat", "Ganchjoy"};
    const char* types[] = {"panel", "brick", "monolithic"};

    for (int i = 0; i < N; i++) {
        House r = {0};
        snprintf(r.developer, 50, "%s", developers[rand() % 4]);
        snprintf(r.microrion, 100, "%s", microrions[rand() % 4]);
        snprintf(r.type, 50, "%s", types[rand() % 3]);
        r.foundation = 1970 + rand() % 100;
        r.count_flat = 1 + rand() % 100;
        r.count_floors = r.count_flat * (rand() % 20);
        if (r.count_flat > 5) {
            r.eliva = 1;
            r.garb = 1;
        } else {
            r.eliva = 0;
            r.garb = 0;
        }
        r.aver_S_flats = 5 + (rand() % 100);
        push_back(vec, r);
    }
}

void print_houses(Vector* vec) {
    printf("Builder  Neighborhood  Type  Build  Year  Has Elevatorn  Has Trash Chute  Num Apartments  Num Floors  Avg Area\n");
    for (size_t i = 0; i < vec->size; i++) {
        House r = vec->data[i];
        printf("\"%s\"  ", r.developer);
        printf("\"%s\"  ", r.microrion);
        printf("\"%s\"  ", r.type);
        printf("%d  ", r.foundation);
        printf("%d  ", r.eliva);
        printf("%d  ", r.garb);
        printf("%d  ", r.count_flat);
        printf("%d  ", r.count_floors);
        printf("%d\n", r.aver_S_flats);
    }
}

void export_houses(Vector* vec) {
    FILE *file = fopen(outfile, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (size_t i = 0; i < vec->size; i++) {
        House r = vec->data[i];
        fprintf(file, "\"%s\",\"%s\",\"%s\",%d,%d,%d,%d,%d,%d\n",
                r.developer,
                r.microrion,
                r.type,
                r.foundation,
                r.eliva,
                r.garb,
                r.count_flat,
                r.count_floors,
                r.aver_S_flats);
    }

    fclose(file);
}

int main() {
    Vector vec;
    init_vec(&vec);
    gener(&vec);
    if (crutch_1 == 0){
        print_houses(&vec);
    } else{
        export_houses(&vec);
    }
    clear_vec(&vec);
    return 0;
}
