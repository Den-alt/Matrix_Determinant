#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Headers/inform.h"

//Create dynamic matrix and get data from console
//Parameters: pointer to real matrix size
//Return: pointer to matrix
double** ScanMatrix(int * MatrixSize)
{
    double **pMatrix;
    printf("Enter a number of elements in row:\n");
    if (scanf("%d", MatrixSize) == 0)                               //Get size of Matrix
    {
        printf("Error, size of the matrix is undefined\n");
        return NULL;
    }
    printf("Your matrix is %dx%d\n", *MatrixSize, *MatrixSize);
    pMatrix = (double **)malloc(*MatrixSize * sizeof (double*));            //Allocate memory for matrix
    if (!pMatrix)
        return NULL;
    for (int i = 0; i < *MatrixSize; ++i)
    {
        pMatrix[i] = (double *)malloc(*MatrixSize * sizeof (double));       //Allocate memory for columns
        if (!*(pMatrix+i))
        {
            FreeMemory(pMatrix,i);
            return NULL;
        }
        printf("Write elements of the %d row:\n", i+1);
        for (int j = 0; j < *MatrixSize; ++j)                                   //Get values
        {
            printf("\tElement №%d:\t", j+1);
            scanf("%lf", &pMatrix[i][j]);
        }
    }
    return pMatrix;
}
//Create dynamic matrix and get data from file
//Parameters: pointer to real matrix size
//Return: pointer to matrix
double** FileScanMatrix(int *MatrixSize)
{
    double **pMatrix, *TempData, temp;
    extern FILE *fp;
    if (PrepareFile()!=0)                                               //If file hasn't opened successfully stop program with an error
        return NULL;
    *MatrixSize = 0;
    TempData = (double *)malloc(sizeof(double ));                       //Temporary array for all numbers from file
    if (!TempData)
    {
        printf("Not enough memory!\n");
        return NULL;
    }
    do {                                                                //Get values to temp array
        if (fscanf(fp,"%lf",&temp) != 1)
        {
            if(feof(fp))
                break;
            else
            {
                fscanf(fp,"%*s");
                continue;
            }
        }
        (*MatrixSize)++;
        TempData = (double *)realloc(TempData,(*MatrixSize)*sizeof(double ));
        if (!TempData)
        {
            printf("Not enough memory!\n");
            return NULL;
        }
        TempData[(*MatrixSize)-1] = temp;
    } while (1);
    *MatrixSize = (int)sqrt(*MatrixSize);                                //Calc a number of rows and columns
    pMatrix = (double **)malloc((*MatrixSize)*sizeof (double *));    //Init memory for array of the pointers to rows of the matrix
    if (!pMatrix)
    {
        printf("Not enough memory!\n");
        return NULL;
    }
    for (int i = 0; i < *MatrixSize; ++i)                                   //Init memory for elements in rows
    {
        pMatrix[i] = (double *)malloc((*MatrixSize)*sizeof (double ));
        if (!*(pMatrix+i))
        {
            printf("Not enough memory!\n");
            FreeMemory(pMatrix, i);
            return NULL;
        }
    }
    for (int i = 0, t = 0; i < *MatrixSize; ++i)                           //Exchange of values
        for (int j = 0; j < *MatrixSize; ++j, t++)
            pMatrix[i][j] = TempData[t];
    free(TempData);
    return pMatrix;
}
//Print matrix to console
//Parameters: pointers to matrix and real matrix size
//Return: pointer to start of the matrix
double** PrintMatrix(double **matrix,int size)
{
    printf("\nMatrix:\n");
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            printf("%10.2lf", matrix[i][j]);
        printf("\n");
    }
    return matrix;
}
//Free all used dynamic memory
//Parameters: pointers to matrix and real matrix size
void FreeMemory(double **matrix,int size)
{
    if (size != 0)
    {
        for (double ** p = matrix; p < matrix+size; p++)        //Clear memory of the rows
            free(*p);
        free(matrix);                                           //Delete the array of pointers
    }
}
