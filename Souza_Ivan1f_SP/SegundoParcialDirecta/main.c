#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "LinkedList.c"
#include "Parser.h"
#include "utn.h"

char * NombreArchivo();

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
            //archivo = NombreArchivo();
            printf("ssa");
            parser_envios("data.csv",listaEnvios);
            break;
        case 2:
            envios_ListarEnvios(listaEnvios);
            break;
        case 3:
            int j;



            break;
        case 4:
            break;
        case 5:
            break;
        }
    }
    while (respuesta!=6);






}
char * NombreArchivo()
{
    char*Auxiliar;
    printf("\nIngrese nombre del archivo\n");
    fflush(stdin);
    gets(Auxiliar);

    return Auxiliar;
}
