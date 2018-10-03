#ifndef Funcion_H_INCLUDED
#define Funcion_H_INCLUDED
//prototipos de funciones y estructuras

typedef struct{
int codigoJuego;
char descripcion[51];
int importe;
int isEmpty;
}eJuegos;

typedef struct{
int codigoCliente;
char apellido[51];
char nombre[51];
char domicilio[51];
char telefono;
int isEmpty;
}eClientes;

typedef struct{
int dia,mes,anio;
}eFecha;

typedef struct{
int CodigoAlquiler;
int CodigoJuego;
int CodigoCliente;
int isEmpty;
eFecha fecha;
}eAlquileres;

//------- juegos funciones-------
void initJuegos(eJuegos*juegos,int len);

void altaJuegos(eJuegos*juegos,int len);

int obtenerEspacioLibre(eJuegos*juegos,int len);

void BajaJuegos(eJuegos*juegos,int len,int idBajar);

void ModificarJuego(eJuegos*juegos,int len,int idModificar);

int sortEmployees(eJuegos* list, int len);


//-------clientes funciones------
void initClientes(eClientes*clientes,int len);

void altaClientes(eClientes*clientes,int len);

int obtenerEspacioLibreClientes(eClientes*clientes,int len);

void ModificarCliente(eClientes*clientes,int len,int idModificar);

void BajaClientes(eClientes*clientes,int len,int idBajar);

void listarClientes(eClientes* clientes,int len);

int sortClientes(eClientes* list, int len);


//-------

















#endif
