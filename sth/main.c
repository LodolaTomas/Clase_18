#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int id;
    char nombre[50];
    char apellido[50];
    float salario;

}eEmpleado;

eEmpleado* new_Empleado();
eEmpleado* new_Empleado_Parameters(int legajo,char nomre[],char apellido[],float salario);
void delete_Empleado(eEmpleado* unEmpleado);
void empleado_SetId(eEmpleado* unEmpleado,int legajo);
int empleado_GetId(eEmpleado*unEmpleado);
void empleado_MostrarUnEmpleado(eEmpleado* unEmpleado);
void empleado_MostrarEmpleados(eEmpleado listaEmpleados,int tam);
void empleado_SetName(eEmpleado* unEmpleado,char name[]);
void empleado_GetName(eEmpleado*unEmpleado,char* name);
void empleado_SetLastName(eEmpleado* unEmpleado,char lastName[]);
void empleado_GetLastName(eEmpleado*unEmpleado,char* lastName);
void empleado_SetSalary(eEmpleado* unEmpleado,float salary);
float empleado_GetSalary(eEmpleado*unEmpleado);

int main()
{

    eEmpleado lista[50];

    eEmpleado* unEmpleado=new_Empleado();
    FILE* pArchivo;

    int i=0;
    char legajo[20];
    char nombre[50];
    char apellido[50];

    char sueldo[20];

    int id;
    int salary;

    pArchivo=fopen("datos.csv","r");
    if(pArchivo!=NULL)
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);//FALSA LECTURA
        printf("%5s %10s %20s %15s\n\n",legajo,nombre,apellido,sueldo);

        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

            id=atoi(legajo);
            salary=atof(sueldo);

            unEmpleado=new_Empleado_Parameters(id,nombre,apellido,salary);
            lista[i]=unEmpleado;
            i++;

        }
        fclose(pArchivo);
        free(unEmpleado);
        empleado_MostrarEmpleados(lista,50);
    }

    return 0;
}


eEmpleado* new_Empleado()
{
    eEmpleado* p;

    p=(void*)malloc(sizeof(eEmpleado));

    return p;
}

eEmpleado* new_Empleado_Parameters(int legajo,char nombre[],char apellido[],float salario)
{
    eEmpleado* p=new_Empleado();

    if(p!=NULL)
    {
        p->id=legajo;
        strcpy(p->nombre,nombre);
        strcpy(p->apellido,apellido);
        p->salario=salario;
    }
    return p;
}

void delete_Empleado(eEmpleado* unEmpleado)
{
    free(unEmpleado);

}

void empleado_SetId(eEmpleado* unEmpleado,int legajo)
{
    if(unEmpleado!=NULL && legajo>0)
    {
        unEmpleado->id=legajo;
    }
}
int empleado_GetId(eEmpleado*unEmpleado)
{
    int retorno;

    if(unEmpleado!=NULL)
    {
            retorno=unEmpleado->id;
    }
    return retorno;
}

void empleado_SetName(eEmpleado* unEmpleado,char name[])
{
    if(unEmpleado!=NULL&& name!='\0')
    {
        strcpy(unEmpleado->nombre,name);
    }
}
void empleado_GetName(eEmpleado*unEmpleado,char* name)
{

    if(unEmpleado!=NULL)
    {
        strcpy(name,unEmpleado->nombre);
    }

}
void empleado_SetLastName(eEmpleado* unEmpleado,char lastName[])
{
    if(unEmpleado!=NULL&& lastName!='\0')
    {
        strcpy(unEmpleado->apellido,lastName);
    }
}
void empleado_GetLastName(eEmpleado*unEmpleado,char*lastName)
{

    if(unEmpleado!=NULL)
    {
        strcpy(lastName,unEmpleado->apellido);
    }

}

void empleado_SetSalary(eEmpleado* unEmpleado,float salary)
{
    if(unEmpleado!=NULL&& salary>0)
    {
        unEmpleado->salario=salary;
    }
}
float empleado_GetSalary(eEmpleado*unEmpleado)
{
    float retorno;

    if(unEmpleado!=NULL)
    {
            retorno=unEmpleado->salario;
    }
    return retorno;
}
void empleado_MostrarUnEmpleado(eEmpleado* unEmpleado)
{
     int id=empleado_GetId(unEmpleado);
     char nombre[50];
     empleado_GetName(unEmpleado,nombre);
     char apellido[50];
     empleado_GetLastName(unEmpleado,apellido);
     float salario=empleado_GetSalary(unEmpleado);

     printf("%5d %10s %20s %15.2f\n",id,nombre,apellido,salario);
}
void empleado_MostrarEmpleados(eEmpleado listaEmpleados,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        empleado_MostrarUnEmpleado(listaEmpleados[i]);
    }
}
