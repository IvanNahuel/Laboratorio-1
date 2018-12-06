#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "LinkedList.c"
#include "Parser.h"

char * NombreArchivo();

int main()
{
    char*pFile;

    LinkedList* listaVendedor;        // Definir lista de empleados
    listaVendedor = ll_newLinkedList();            // Crear lista empleados

    //pFile = NombreArchivo();

    // Leer empleados de archivo data.csv

    if(parser_parserVendedores("data.csv",listaVendedor)==1)     ///si se pudo leer los datos
    {




        /*
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
        */
    }
    else
    {
        printf("Error al leer archivos\n");
    }

    return 0;
}

/////////


char * NombreArchivo()
{
    char*Auxiliar;
    printf("\nIngrese nombre del archivo\n");
    fflush(stdin);
    gets(Auxiliar);

    return Auxiliar;
}

int ImprimirMenu()
{
    int respuesta;
    printf("\n1-Cargar Archivos");
    printf("\n2-Imprimir Vendedores");
    printf("\n3-Calcular Comisiones");
    printf("\n4-Generar archivo de comisiones para nivel");
    printf("\n5-salir");

    printf("\nIngrese la opcion deseada: ");
    scanf("%d",&respuesta);
    while(respuesta<0 || respuesta>5){
    printf("\nError Ingrese la opcion deseada: ");
    scanf("%d",&respuesta);
    }
return respuesta;
}


