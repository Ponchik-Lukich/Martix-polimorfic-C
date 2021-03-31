#include <stdio.h>
#include <stdlib.h>
#include "../Matrix.c"
#include "../Matrix_complex.c"
#include "../Matrix_float.c"

void test1() {
    int width_1 = 2, width_2 = 2, height_1 = 2, height_2 = 2;
    float testIn_1[4] = {1.0, 2.0, 3.0, 4.0};
    float testIn_2[4] = {4.0, 3.0, 2.0, 1.0};
    float testOut[4] = {5.0, 5.0, 5.0, 5.0};
    matrixmeta *matrixmeta_float_1 = init_matrixmeta_float();
    Matrix *a = matrixmeta_float_1->set_from_arr(height_1, width_1, testIn_1, matrixmeta_float_1);
    Matrix *b = matrixmeta_float_1->set_from_arr(height_2, width_2, testIn_2, matrixmeta_float_1);
    Matrix *t = matrixmeta_float_1->set_from_arr(2, 2, testOut, matrixmeta_float_1);
    Matrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_1: pass\n");
    } else {
        printf("\ntest_1: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_1);
}

void test2() {
    int width_1 = 2, width_2 = 2, height_1 = 3, height_2 = 3;
    complex testIn_1[12] = {99.0, 1.0, 88.0, 2.0, 77.0, 3.0, 66.0, 4.0, 55.0, 5.0, 44.0, 4.0};
    complex testIn_2[12] = {33.0, 3.0, 22.0, 2.0, 11.0, 1.0, 0.0, 0.0, -11.0, -1.0, -22.0, -2.0};
    complex testOut[12] = {132.0, 4.0, 110.0, 4.0, 88.0, 4.0, 66.0, 4.0, 44.0, 4.0, 22.0, 2.0};
    matrixmeta *matrixmeta_complex_1 = init_matrixmeta_complex();
    Matrix *a = matrixmeta_complex_1->set_from_arr(height_1, width_1, testIn_1, matrixmeta_complex_1);
    Matrix *b = matrixmeta_complex_1->set_from_arr(height_2, width_2, testIn_2, matrixmeta_complex_1);
    Matrix *t = matrixmeta_complex_1->set_from_arr(3, 2, testOut, matrixmeta_complex_1);
    Matrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_2: pass\n");
    } else {
        printf("\ntest_2: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_complex_1);
}

void test3() {
    int width_1 = 3, width_2 = 4, height_1 = 3, height_2 = 3;
    float testIn_1[9] = {2.0, -1.0, -3.0, 4.5, -1.5, -6.0, 1.5, 5.0, -8.0};
    float testIn_2[12] = {1.0, 3.0, 2.0, 5.0, -2.0, -1.0, 1.0, 5.0, 1.0, 2.0, 2.0, 5.0};
    float testOut[12] = {1.0, 1.0, -3.0, -10.0, 1.5, 3.0, -4.5, -15.0, -16.5, -16.5, -8.0, -7.5};
    matrixmeta *matrixmeta_float_2 = init_matrixmeta_float();
    Matrix *a = matrixmeta_float_2->set_from_arr(height_1, width_1, testIn_1, matrixmeta_float_2);
    Matrix *b = matrixmeta_float_2->set_from_arr(height_2, width_2, testIn_2, matrixmeta_float_2);
    Matrix *t = matrixmeta_float_2->set_from_arr(3, 4, testOut, matrixmeta_float_2);
    Matrix *c = a->meta->mult(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_3: pass\n");
    } else {
        printf("\ntest_3: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_2);
}

void test4() {
    int width_1 = 3, width_2 = 1, height_1 = 2, height_2 = 3;
    complex testIn_1[12] = {1.0, 2.0, 2.0, 1.0, 1.0, 3.0, 2.0, 0.0, 4.0, 2.0, 2.0, 5.0};
    complex testIn_2[6] = {2.0, 2.0, 1.0, 4.0, 2.0, 2.0};
    complex testOut[4] = {-8.0, 22.0, -6.0, 24.0};
    matrixmeta *matrixmeta_complex_2 = init_matrixmeta_complex();
    Matrix *a = matrixmeta_complex_2->set_from_arr(height_1, width_1, testIn_1, matrixmeta_complex_2);
    Matrix *b = matrixmeta_complex_2->set_from_arr(height_2, width_2, testIn_2, matrixmeta_complex_2);
    Matrix *t = matrixmeta_complex_2->set_from_arr(2, 1, testOut, matrixmeta_complex_2);
    Matrix *c = a->meta->mult(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_4: pass\n");
    } else {
        printf("\ntest_4: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_complex_2);
}

void test5() {
    int width_1 = 3, width_2 = 1, height_1 = 2, height_2 = 3;
    float testIn_1[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    float testIn_2[3] = {111.0, 121.0, 131.0};
    float testOut[6] = {1.0, 4.0, 2.0, 5.0, 3.0, 6.0};
    float testOut_2[3] = {111.0, 121.0, 131.0};
    matrixmeta *matrixmeta_float_3 = init_matrixmeta_float();
    Matrix *a = matrixmeta_float_3->set_from_arr(height_1, width_1, testIn_1, matrixmeta_float_3);
    Matrix *b = matrixmeta_float_3->set_from_arr(height_2, width_2, testIn_2, matrixmeta_float_3);
    Matrix *t = matrixmeta_float_3->set_from_arr(3, 2, testOut, matrixmeta_float_3);
    Matrix *d = matrixmeta_float_3->set_from_arr(1, 3, testOut_2, matrixmeta_float_3);
    Matrix *c = a->meta->trans(a);
    Matrix *k = a->meta->trans(b);
    int Y = t->meta->compare(t, c);
    int Y_1 = t->meta->compare(k, d);
    if (Y == 1 && Y_1 == 1) {
        printf("\ntest_5: pass\n");
    } else {
        printf("\ntest_5: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    d->meta->delete(d);
    k->meta->delete(k);
    free(matrixmeta_float_3);
}

void test6() {
    int width_1 = 2, height_1 = 3;
    complex testIn_1[12] = {228.0, 1488.0, 665.0, 22.0, 11.0, 44.0, 332.0, 898.0, 600.0, 212.0, 545.0, 32.0};
    complex testOut[12] = {228.0, 1488.0, 11.0, 44.0, 600.0, 212.0, 665.0, 22.0, 332.0, 898.0, 545.0, 32.0};
    matrixmeta *matrixmeta_complex_3 = init_matrixmeta_complex();
    Matrix *a = matrixmeta_complex_3->set_from_arr(height_1, width_1, testIn_1, matrixmeta_complex_3);
    Matrix *t = matrixmeta_complex_3->set_from_arr(2, 3, testOut, matrixmeta_complex_3);
    Matrix *c = a->meta->trans(a);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_6: pass\n");
    } else {
        printf("\ntest_6: fail\n");
    }
    a->meta->delete(a);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_complex_3);
}

void test7() {
    int width_1 = 1, height_1 = 3;
    complex testIn_1[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    complex testOut[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    matrixmeta *matrixmeta_complex_4 = init_matrixmeta_complex();
    Matrix *a = matrixmeta_complex_4->set_from_arr(height_1, width_1, testIn_1, matrixmeta_complex_4);
    Matrix *t = matrixmeta_complex_4->set_from_arr(width_1, height_1, testOut, matrixmeta_complex_4);
    Matrix *c = a->meta->trans(a);
    int Y = t->meta->compare(c, t);
    if (Y == 1) {
        printf("\ntest_7: pass\n");
    } else {
        printf("\ntest_7: fail\n");
    }
    a->meta->delete(a);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_complex_4);
}

void test8() {
    int width_1 = 3, width_2 = 3, height_1 = 3, height_2 = 3;
    float testIn_1[9] = {1.34, 2.73, 3.441, 4.99, 6.776, 8.89, 99.34, 66.11, 1.999};
    float testIn_2[9] = {4.66, 3.77, 2.559, 1.01, 6.224, 7.11, 323.66, 1.89, 321.0};
    float testOut[9] = {6.0, 6.5, 6.0, 6.0, 13.0, 16.0, 423.0, 68.0, 322.999};
    matrixmeta *matrixmeta_float_4 = init_matrixmeta_float();
    Matrix *a = matrixmeta_float_4->set_from_arr(height_1, width_1, testIn_1, matrixmeta_float_4);
    Matrix *b = matrixmeta_float_4->set_from_arr(height_2, width_2, testIn_2, matrixmeta_float_4);
    Matrix *t = matrixmeta_float_4->set_from_arr(3, 3, testOut, matrixmeta_float_4);
    Matrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_8: pass\n");
    } else {
        printf("\ntest_8: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    c->meta->delete(c);
    t->meta->delete(t);
    free(matrixmeta_float_4);
}

void test9() {
    int width_1 = 4, width_2 = 2, height_1 = 4, height_2 = 4;
    float testIn_1[16] = {1.5, 1.5, 1.5, 1.5, 2, 2, 2, 2, 3, 3, 3, 3, 4.5, 4.5, 4.5, 4.5};
    float testIn_2[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    float testOut[8] = {24.0, 30.0, 32.0, 40.0, 48.0, 60.0, 72.0, 90.0};
    matrixmeta *matrixmeta_float_5 = init_matrixmeta_float();
    Matrix *a = matrixmeta_float_5->set_from_arr(height_1, width_1, testIn_1, matrixmeta_float_5);
    Matrix *b = matrixmeta_float_5->set_from_arr(height_2, width_2, testIn_2, matrixmeta_float_5);
    Matrix *t = matrixmeta_float_5->set_from_arr(4, 2, testOut, matrixmeta_float_5);
    Matrix *c = a->meta->mult(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_9: pass\n");
    } else {
        printf("\ntest_9: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    c->meta->delete(c);
    t->meta->delete(t);
    free(matrixmeta_float_5);
}

void test10() {
    int width_1 = 1, width_2 = 1, height_1 = 1, height_2 = 1;
    complex testIn_1[2] = {2.0, 2.0};
    complex testIn_2[2] = {9.0, 9.0};
    complex testOut[2] = {0.0, 36.0};
    matrixmeta *matrixmeta_complex_5 = init_matrixmeta_complex();
    Matrix *a = matrixmeta_complex_5->set_from_arr(height_1, width_1, testIn_1, matrixmeta_complex_5);
    Matrix *b = matrixmeta_complex_5->set_from_arr(height_2, width_2, testIn_2, matrixmeta_complex_5);
    Matrix *t = matrixmeta_complex_5->set_from_arr(1, 1, testOut, matrixmeta_complex_5);
    Matrix *c = a->meta->mult(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_10: pass\n");
    } else {
        printf("\ntest_10: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    c->meta->delete(c);
    t->meta->delete(t);
    free(matrixmeta_complex_5);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}