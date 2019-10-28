#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char name[50];
    char lastName[50];
    float salary;

}eDato;

int archivo_CrearArchivoTxt(char* path);
int archivo_DatosTxt(FILE* pFile);
int archivo_MostrarArchivoTxt(char*Path);
