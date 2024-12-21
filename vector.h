#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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



#endif