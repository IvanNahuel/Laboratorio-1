#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"

eEnvios*envios_newParametros(char*idAux,char* nombreAux,char*idCamion,char*zonaDestino,char*kmRecorridos,char*tipoEntrega)
{

    eEnvios*Envios = envios_new();
    int id;
    int idCamionAux;
    int kmRecorridosAux;
    int tipoEntregaAux;

    id = atoi(idAux);
    idCamionAux = atoi(idCamion);
    kmRecorridosAux = atoi(kmRecorridos);
    tipoEntregaAux = atoi(tipoEntrega);

    if (Envios!=NULL)
    {
        //sets
        envios_setId(Envios,id);
        envios_setNombre(Envios,nombreAux);
        envios_SetIdCamion(Envios,idCamionAux);
        envios_setZonaDestino(Envios,zonaDestino);
        envios_kmRecorrido(Envios,kmRecorridosAux);
        envios_TipoEntrega(Envios,tipoEntregaAux);

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
            this->id = nextId;
            retorno = 1;
        }
        else if(id > nextId)
        {
            nextId = id;
            this->id = nextId;
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

int envios_SetIdCamion(eEnvios* this,int idCamion)
{
    int retorno = 0;

    if(this != NULL && idCamion > 0)
    {
        this->idCamion = idCamion;
        retorno = 1;
    }
    return retorno;
}

int envios_setZonaDestino(eEnvios* this,char* zonaDestino)
{
    int retorno = 0;
    if(this != NULL && zonaDestino[0] != '\0')
    {
        strncpy(this->zonaDestino, zonaDestino, sizeof(this->zonaDestino));
        retorno = 1;
    }
    return retorno;
}

int envios_kmRecorrido(eEnvios* this,int km)
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
    printf("\n1-Cargar Archivos");
    printf("\n2-Imprimir Envios");
    printf("\n3-Calcular Costos");
    printf("\n4-Generar archivo de Costos segun la zona");
    printf("\n5-Imprimir Lista de zonas");
    printf("\n6-Salir");

    printf("\nIngrese la opcion deseada: ");
    scanf("%d",&respuesta);
    while(respuesta<0 || respuesta>6)
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
        printf("\n%20s     %d      %10s",auxEnvios->nombreProducto,auxEnvios->idCamion,auxEnvios->zonaDestino);
    }
}
int envios_CostosEntregas(int numero)
{
    int retorno;
    if (numero==0)      //NORMAL
    {
        retorno = 250;
    }
    else if (numero ==1)
    {
        retorno =420;
    }
    else
    {
        retorno =75;
    }
    return retorno;
}

//aca le pasamos la lista que sera
void envios_calcularCostos (void*e)
{
    eEnvios*this2 = (eEnvios*)e;        //apunta al alemento que esta en la lista
    int costosAux;

    if (this2!=NULL)
    {
        if (this2->kmRecorridos<50)
        {
            //si los kilometros rrecorridos son menores a 50 multiplicar por 100 los kilometros
            costosAux = this2->kmRecorridos*100;
            costosAux = costosAux + envios_CostosEntregas(this2->tipoEntrega);
            this2->costoEnvio = costosAux;
            //FALTA SETTEAR
        }
        else
        {
            costosAux = this2->kmRecorridos*50;
            costosAux = costosAux + envios_CostosEntregas(this2->tipoEntrega);
            this2->costoEnvio = costosAux;
            //FALTA SETTEAR
        }
    }

    //ll_set(this,indice,this2);      //seteo
}







