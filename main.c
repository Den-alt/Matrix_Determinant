#include <stdio.h>
#include "Headers/inform.h"

int main()
{
    int matrix_size = 0;
    double **Matrix;
    Matrix = ScanMatrix(&matrix_size);
    Matrix = PrintMatrix(Matrix, matrix_size);
    FreeMemory(Matrix, matrix_size);
    return 0;
}
