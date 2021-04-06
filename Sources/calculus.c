#include <stdio.h>
#include <stdlib.h>
#include "../Headers/inform.h"

//Decompose matrix and calc the determinant
//Parameters: matrix and number of the elements
//Return: determinant
double Decomposition(double **matrix, int size)
{
    double result = 0;
    if(size == 2)                                                   //if matrix is 2x2 - calculate determinant by formula
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    else if (size < 2)                                             //If something went wrong
        return matrix[0][0];
    else                                                          //If the matrix needs to be further decomposed
    {
        double ** minor;
        minor = (double **)calloc(size - 1, sizeof (double *));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size-1; ++j)
            {
                minor[j]=(double *)calloc(size-1, sizeof (double ));
                if (!*(minor+j))
                {
                    printf("Not enough memory! The result is wrong!\n");
                    FreeMemory(minor, j);
                    return 0;
                }
                double *p = &matrix[j+1][0];
                for (int k = 0; k < size - 1; ++k, p++)
                {
                    if (k == i)
                        p++;
                    minor[j][k] = *p;
                }
            }
            if ( ((i+1) & 1) == 0)                                  //Check the power of multiplier (-1)
                result += -matrix[0][i] * Decomposition(minor, size - 1);
            else
                result += matrix[0][i] * Decomposition(minor, size - 1);
        }
        FreeMemory(minor, size-1);
    }
    return result;
}