#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

struct S_Envios
{
    int id;
    char nombreProducto[100];
    int idCamion;
    char zonaDestino[100];
    int kmRecorridos;
    int tipoEntrega;
};

typedef struct S_Envios eEnvios;

eEnvios*envios_newParametros(char*idAux,char* nombreAux,char*idCamion,char*zonaDestino,char*kmRecorridos,char*tipoEntrega);

eEnvios* envios_new();

int envios_setId(eEnvios* this,int id);

int envios_setNombre(eEnvios* this,char* nombre);

int envios_SetIdCamion(eEnvios* this,int idCamion);

int envios_setZonaDestino(eEnvios* this,char* zonaDestino);

int envios_kmRecorrido(eEnvios* this,int km);

int envios_TipoEntrega(eEnvios* this,int tipo);

#endif // PARSER_H_INCLUDED
