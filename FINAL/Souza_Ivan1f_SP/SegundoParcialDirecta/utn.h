#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

struct S_Envios
{
    int idEnvio;
    char nombreProducto[100];
    int kmRecorridos;
    int tipoEntrega;
    int costoEnvio;
};

typedef struct S_Envios eEnvios;

eEnvios*envios_newParametros(char*idAux,char* nombreAux,char*kmRecorridos,char*tipoEntrega);

eEnvios* envios_new();

int envios_setId(eEnvios* this,int id);

int envios_setNombre(eEnvios* this,char* nombre);

int envios_SetIdCamion(eEnvios* this,int idCamion);

int envios_setZonaDestino(eEnvios* this,char* zonaDestino);

int envios_kmRecorrido(eEnvios* this,int km);

int envios_TipoEntrega(eEnvios* this,int tipo);

void envios_ListarEnvios (LinkedList*this);

#endif // PARSER_H_INCLUDED
