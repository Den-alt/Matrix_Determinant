#include <stdio.h>
#include "Headers/inform.h"

int main()
{
    int matrix_size = 0, isFile = 0;
    double **Matrix;
    printf("Scan matrix from console enter - 0\nScan matrix from file enter - 1\n");
    scanf("%d",&isFile);
    getchar();
    if (isFile == 0)
    {
        printf("Your choose - scan matrix from console.\n");
        Matrix = ScanMatrix(&matrix_size);
        Matrix = PrintMatrix(Matrix, matrix_size);
        FreeMemory(Matrix, matrix_size);
    } else
    {
        printf("Your choose - scan matrix from file.\n");
        Matrix = FileScanMatrix(&matrix_size);
        if (Matrix == NULL)
            CloseFiles();
        else
        {
            Matrix = PrintMatrix(Matrix, matrix_size);
            FreeMemory(Matrix, matrix_size);
            CloseFiles();
        }
    }
    return 0;
}
