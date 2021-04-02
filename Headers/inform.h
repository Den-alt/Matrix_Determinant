#ifndef MATRIX_DETERMINANT_INFORM_H
#define MATRIX_DETERMINANT_INFORM_H

// Path to demo file:
// ../matrix_data.txt

//interact.c
double** ScanMatrix(int *);
double** FileScanMatrix(int *);
double** PrintMatrix(double **,int);
void FreeMemory(double **,int);

//file.c
int PrepareFile();
void CloseFiles();

#endif //MATRIX_DETERMINANT_INFORM_H
