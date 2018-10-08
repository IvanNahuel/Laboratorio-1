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
char telefono[21];
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

void altaJuegos(eJuegos*juegos,int len,int* codigoJuegoCont);

void BajaJuegos(eJuegos*juegos,int len,int idBajar);

void ModificarJuego(eJuegos*juegos,int len);

int BuscarPorId(eJuegos*juegos,int len);

void listarJuego(eJuegos* juego,int len);

int sortEmployees(eJuegos* list, int len);



//-------clientes funciones------
void initJuegos(eJuegos*juegos,int len);

void altaJuegos(eJuegos*juegos,int len,int* codigoJuegoCont);

int obtenerEspacioLibre(eJuegos*juegos,int len);

void BajaJuegos(eJuegos*juegos,int len,int idBajar);

void ModificarJuego(eJuegos*juegos,int len);

int BuscarPorId(eJuegos*juegos,int len);

void listarJuego(eJuegos* juego,int len);

int sortEmployees(eJuegos* list, int len);

//--------funciones alquileres------
 void initAlquileres(eAlquileres*alquileres,int len);

int obtenerEspacioLibreAlquileres(eAlquileres*alquileres,int len);

void altaAlquileres(eAlquileres*alquileres,int len,eJuegos*juegos,eClientes*clientes);

//----------Otras funciones-----

void HarcodeoDeAlgunasFunciones(eJuegos*juegos,eClientes*clientes,int* codigoJuegoCont,int* codigoClienteCont);

int ImprimirMenuPrincipalYObtenerRespuesta();

int ImprimirMenuAlquileres();

int ImprimirMenuClientes();

int ImprimirMenuJuegos();

int pedirIdAModificar(char*mensaje,char*mensajeError);

int pedirIdABajar(char*mensaje,char*mensajeError);

void ImprimirCartelDeFlags(char*pCadena);
























#endif
