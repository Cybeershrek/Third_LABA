#include <stdio.h>
#include <math.h>
#include "Universal.h"
#include "vector.h"

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


void comb_sort(Vector* vec) {
    if (vec->size <= 1 || vec->content < 6) {
        return; 
    }

    size_t gap = vec->size;
    double shrink_factor = 1.3;  
    bool swapped;

    do {
        gap = (size_t)(gap / shrink_factor);
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        for (size_t i = 0; i < vec->size - gap; ++i) {
            size_t j = i + gap;
            if (vec->data[i][4] > vec->data[j][4]) {
                for (size_t k = 0; k < vec->content; ++k) {
                    int temp = vec->data[i][k];
                    vec->data[i][k] = vec->data[j][k];
                    vec->data[j][k] = temp;
                }
                swapped = true;
            }
        }
    } while (gap > 1 || swapped);
}

int main() {
    comb_sort(&vec);

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < content; ++j) {
            printf("%d ", vec.data[i][j]);
        }
        printf("\n");
    }

    destroy_vector(&vec);

    return 0;
}
