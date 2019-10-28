#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"



int main()
{

    int i;
    char pathArchivo[]="data.csv";

    archivo_CrearArchivoTxt(pathArchivo);

    archivo_MostrarArchivoTxt(pathArchivo);

    return 0;
}
