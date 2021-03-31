#include "Matrix_float.h"
#include <stdlib.h>
#include <stdio.h>


typemeta *init_typemeta_float() {
    typemeta *res = calloc(1, sizeof(typemeta));
    res->size = sizeof(float);
    res->mult = mult_float;
    res->sum = sum_float;
    res->print_EL = print_EL_float;
    return res;
}


void print_EL_float(void *m) {
    printf("%f", *(float *) m);
}

void *mult_float(void *a, void *b) {
    float *res = calloc(1, sizeof(float));
    *res = *(float *) a * *(float *) b;
    return res;
}

void *sum_float(void *a, void *b) {
    float *res = calloc(1, sizeof(float));
    *res = *(float *) a + *(float *) b;
    return res;
}

matrixmeta *init_matrixmeta_float() {
    matrixmeta *res = calloc(1, sizeof(matrixmeta));
    res->get_ij = get_ij;
    res->sum = sum;
    res->init = init;
    res->trans = trans;
    res->mult = mult;
    res->compare = compare;
    res->set_ij = set_ij;
    res->print = print;
    res->delete = delete;
    res->type_m = init_typemeta_float();
    res->set_from_arr = init_from_arr;
    return res;
}
