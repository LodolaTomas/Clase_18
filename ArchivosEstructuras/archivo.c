#include "archivo.h"

int archivo_CrearArchivoTxt(char* path)
{
    int state=0;
    FILE* pArchivo;
    char miFormato[]="r";

    pArchivo=fopen(path,miFormato);

    if(pArchivo!=NULL)
    {

        state=archivo_DatosTxt(pArchivo);

    }
    return state;
}

int archivo_DatosTxt(FILE* pFile)
{
    int state;
    int counter=0;
    char id[10],name[51],lastName[51],salary[20];

    if(pFile!=NULL )
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,salary);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,salary);
            counter++;
        }

        fclose(pFile);
        printf("Se Cargaron: %d\n",counter);
        state=1;
    }

    return state;
}

int archivo_MostrarArchivoTxt(char* path)
{
    FILE* pArchivo;
    eDato auxiliar;
    int i;

    pArchivo=fopen(path,"rb");

    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            fread(&auxiliar,sizeof(eDato),1,pArchivo);

        }




        fclose(pArchivo);
    }

}
