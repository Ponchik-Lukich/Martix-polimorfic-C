#include "Matrix_complex.h"
#include <stdlib.h>
#include <stdio.h>

typemeta *init_typemeta_complex() {
    typemeta *res = calloc(1, sizeof(typemeta));
    res->size = sizeof(complex);
    res->mult = mult_complex;
    res->sum = sum_complex;
    res->print_EL = print_EL_complex;
    return res;
}

void print_EL_complex(void *m) {
    printf("%f+%f*i ", ((complex *) m)->real, ((complex *) m)->imag);
}

void *mult_complex(void *a, void *b) {
    complex *res = calloc(1, sizeof(complex));
    ((complex *) res)->real =
            ((complex *) a)->real * ((complex *) b)->real - ((complex *) a)->imag * ((complex *) b)->imag;
    ((complex *) res)->imag =
            ((complex *) a)->imag * ((complex *) b)->real + ((complex *) a)->imag * ((complex *) b)->real;
    return res;

}

void *sum_complex(void *a, void *b) {
    complex *res = calloc(1, sizeof(complex));
    ((complex *) res)->real = ((complex *) a)->real + ((complex *) b)->real;
    ((complex *) res)->imag = ((complex *) a)->imag + ((complex *) b)->imag;
    return res;

}

matrixmeta *init_matrixmeta_complex() {
    matrixmeta *res = calloc(1, sizeof(matrixmeta));
    res->get_ij = get_ij;
    res->sum = sum;
    res->init = init;
    res->compare = compare;
    res->trans = trans;
    res->mult = mult;
    res->set_ij = set_ij;
    res->print = print;
    res->delete = delete;
    res->type_m = init_typemeta_complex();
    res->set_from_arr = init_from_arr;
    return res;
}