#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "LinkedList.c"
#include "Parser.h"
#include "utn.h"

char * NombreArchivo();

int main()
{
    char*archivo;
    archivo = NombreArchivo();

    LinkedList*listaEnvios;
    listaEnvios = ll_newLinkedList();


    parser_envios("DATA_2F",listaEnvios);

}


char * NombreArchivo()
{
    char*Auxiliar;
    printf("\nIngrese nombre del archivo\n");
    fflush(stdin);
    gets(Auxiliar);

    return Auxiliar;
}
