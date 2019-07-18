#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "LinkedList.c"
#include "Parser.h"
#include "Parser.c"
#include "utn.h"

int main()
{
    char*archivo;

    LinkedList*listaEnvios;
    listaEnvios = ll_newLinkedList();
    int respuesta;

    do
    {
        respuesta = ImprimirMenu();
        switch (respuesta)
        {
        case 1:
            //printf("ssa");
            parser_envios("data_final2.csv",listaEnvios);
            break;
        case 2:
            envios_ListarEnvios(listaEnvios);
            break;
        case 3:

            ll_map(listaEnvios,calcularCosto( ));

            break;
        case 4:
            //SALIR
            break;
        }
    }
    while (respuesta!=4);
}

char * NombreArchivo()
{
    char*Auxiliar;
    printf("\nIngrese nombre del archivo\n");
    fflush(stdin);
    gets(Auxiliar);

    return Auxiliar;
}

