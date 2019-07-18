#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"

eEnvios*envios_newParametros(char*idAux,char* nombreAux,char*kmRecorridos,char*tipoEntrega)
{

    eEnvios*Envios = envios_new();
    int id;

    int kmRecorridosAux;
    int tipoEntregaAux;

    id = atoi(idAux);
    kmRecorridosAux = atoi(kmRecorridos);
    tipoEntregaAux = atoi(tipoEntrega);

    if (Envios!=NULL)
    {
        //sets
        envios_setId(Envios,id);
        envios_setNombre(Envios,nombreAux);
        envios_TipoEntrega(Envios,tipoEntregaAux);
        envios_SetkmRecorrido(Envios,kmRecorridosAux);

    }
    return Envios;
}

eEnvios* envios_new()
{
    eEnvios*this = malloc (sizeof(eEnvios));
    return this;
}

int envios_setId(eEnvios* this,int id)
{
    int retorno = 0;
    static int nextId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            nextId++;
            this->idEnvio = nextId;
            retorno = 1;
        }
        else if(id > nextId)
        {
            nextId = id;
            this->idEnvio = nextId;
            retorno = 1;
        }
    }
    return retorno;
}

int envios_setNombre(eEnvios* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombreProducto, nombre, sizeof(this->nombreProducto));
        retorno = 1;
    }
    return retorno;
}

int envios_SetkmRecorrido(eEnvios* this,int km)
{
    int retorno = 0;

    if(this != NULL && km > 0)
    {
        this->kmRecorridos = km;
        retorno = 1;
    }
    return retorno;
}


int envios_TipoEntrega(eEnvios* this,int tipo)
{
    int retorno = 0;

    if(this != NULL && tipo > 0)
    {
        this->tipoEntrega = tipo;
        retorno = 1;
    }
    return retorno;
}
int ImprimirMenu()
{
    int respuesta;
    printf("\n1-Cargar Archivo");
    printf("\n2-Imprimir Envio");
    printf("\n3-Generar archivo de costo");
    printf("\n4-Salir");

    printf("\nIngrese la opcion deseada: ");
    scanf("%d",&respuesta);
    while(respuesta<0 || respuesta>5)
    {
        printf("\nError Ingrese la opcion deseada: ");
        scanf("%d",&respuesta);
    }
    return respuesta;
}

void envios_ListarEnvios (LinkedList*this)
{
    eEnvios*auxEnvios;
    int i;
    int cant;
    cant = ll_len(this);

    for (i=0; i<cant; i++)
    {
        auxEnvios = ll_get(this,i);
        printf("\n%d     %20s",auxEnvios->idEnvio,auxEnvios->nombreProducto);
    }
}

void calcularCosto (void*e)
{
    eEnvios*this = (eEnvios*)e;
    int totalCosto=0;

    FILE*pFile;

    if (this!=NULL)
    {
        if (this->kmRecorridos<50)
        {
            totalCosto=67;
        }
        else
        {
            totalCosto=80;
        }
        if (this->tipoEntrega==1)
        {
            totalCosto+=330;
        }
        else if (this->tipoEntrega==2)
        {
            totalCosto+=560;
        }
        else
        {
            totalCosto+=80;
        }
        controller_loadFromText(this);
    }
}

int controller_loadFromText(eEnvios* pArchivoQuemador)
{
    FILE*f;
    f=fopen("ArchivoNuevo.cvs","w");

    if (f!=NULL)
    {
        return 1;
    }
    fwrite(pArchivoQuemador,sizeof(eEnvios),1,f);
    fclose(f);
    return 0;
}





