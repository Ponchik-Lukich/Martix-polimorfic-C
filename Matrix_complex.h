
typedef struct {
    float real;
    float imag;
} complex;

void print_EL_complex(void *);

void *mult_complex(void *, void *);

void *sum_complex(void *, void *);

typemeta *init_typemeta_complex();

matrixmeta *init_matrixmeta_complex();
