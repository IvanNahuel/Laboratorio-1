#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "LinkedList.c"
#include "Parser.h"

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);
char * NombreArchivo();

int main()
{
    char*pFile;

    LinkedList* listaEmpleados;        // Definir lista de empleados
    listaEmpleados = ll_newLinkedList();            // Crear lista empleados


    Empleado*auxEmploy;



    pFile = NombreArchivo();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)     ///si se pudo leer los datos
    {

        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");

        //podemos ir recorriendo la lista

        //al_map(listaEmpleados,em_calcularSueldo);


        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");

    }
    else
    {
        printf("Error leyando empleados\n");
    }
return 0;
}




int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    return 1;
}

char * NombreArchivo()
{
    char*Auxiliar;
    printf("\nIngrese nombre del archivo\n");
    fflush(stdin);
    gets(Auxiliar);

    return Auxiliar;
}

