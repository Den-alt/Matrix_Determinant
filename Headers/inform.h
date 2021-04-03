#ifndef MATRIX_DETERMINANT_INFORM_H
#define MATRIX_DETERMINANT_INFORM_H

// Path to demo file:
// ../matrix_data.txt
/*
 1 2 1 3
 2 1 4 1
 3 3 2 -1
 4 2 2 -1
  */

//interact.c
double** ScanMatrix(int *);
double** FileScanMatrix(int *);
double** PrintMatrix(double **,int);
void FreeMemory(double **,int);

//file.c
int PrepareFile();
void CloseFiles();

//calculus.c
double Decomposition(double **, int);

#endif //MATRIX_DETERMINANT_INFORM_H
