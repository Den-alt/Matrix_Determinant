#include <stdio.h>
#include <string.h>
#include "../Headers/inform.h"

#define SIZE 200
FILE *fp = NULL;               //Pointer to stream

//Open file stream
//Parameters: pointer to the path of the user file
//Return: 0 - successful, -1 - error
int PrepareFile()
{
    char UserFile[SIZE], * filename;
    printf("Please, enter a full path to your file\n");
    gets(UserFile);
#if defined __linux__ || defined __gnu_linux__
    filename = strrchr(UserFile, '/');
#elif defined _WIN32 || defined _WIN64
    filename = strrchr(UserFile, '\\');
#endif
    printf("File name: %s\nOpening file...\n",filename+1);
    fp = fopen(UserFile,"r");           //Open user file for reading
    if (fp == NULL)
    {
        printf("Wrong input, file not found\n");
        return -1;
    }
    printf("File opened successfully\n");
    return 0;
}
//Close all files opened in program
void CloseFiles()
{
    if (fp != NULL)
        fclose(fp);
}
