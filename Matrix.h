typedef struct typemeta typemeta;
typedef struct matrixmeta matrixmeta;
typedef struct Matrix Matrix;


struct typemeta {
    int size;

    void (*print_EL)(void *);

    void *(*mult)(void *, void *);

    void *(*sum)(void *, void *);

};

struct matrixmeta {
    typemeta *type_m;

    Matrix *(*init)(int, int, matrixmeta *);

    int (*compare)(Matrix *, Matrix *);

    void (*delete)(Matrix *);

    void *(*get_ij)(int, int, Matrix *);

    void (*print)(Matrix *);

    void (*set_ij)(int, int, void *, Matrix *);

    Matrix *(*set_from_arr)(int, int, void *, matrixmeta *);

    Matrix *(*sum)(Matrix *, Matrix *);

    Matrix *(*mult)(Matrix *, Matrix *);

    Matrix *(*trans)(Matrix *);
};

struct Matrix {
    matrixmeta *meta;
    int width;
    int height;
    void *data;

};

Matrix *init(int, int, matrixmeta *);

void delete(Matrix *);

void *get_ij(int, int, Matrix *);

void print(Matrix *);

void set_ij(int, int, void *, Matrix *);

int compare(Matrix *a, Matrix *b);

Matrix *init_from_arr(int width, int height, void *data, matrixmeta *meta);

Matrix *sum(Matrix *, Matrix *);

Matrix *mult(Matrix *, Matrix *);

Matrix *trans(Matrix *);

