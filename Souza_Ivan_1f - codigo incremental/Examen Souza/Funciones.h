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
/** \brief inicializa en el array de juegos, en espacios vacios
 * \param eJuegos*juegos
 * \param int len
 * \return sin retorno
 */
void initJuegos(eJuegos*juegos,int len);

/** \brief mediante un indice de espacio vacio, obtenido por otra funcion llena los campos correspondiente de la struc
 *tura juegos
 * \param eJuegos*juegos
 * \param int len
 * \param int* codigoJuegoCont
 * \return sin retorno
 */
void altaJuegos(eJuegos*juegos,int len,int* codigoJuegoCont);

/** \brief mediante un entero pasado por parametro, se realiza una baja logica de un campo determinado de la structura
 *juegos en el indice pasado por parametro
 * \param eJuegos*juegos
 * \param int len
 * \param int idBajar
 * \return sin retorno
 */
void BajaJuegos(eJuegos*juegos,int len,int idBajar);

/** \brief pide el ingreso de un entero (mediante otra funcion) y se podra modificar en esa posicion ingresada,en la structura
 *juegos
 * \param eJuegos*juegos
 * \param int len
 * \return sin retorno
 */
void ModificarJuego(eJuegos*juegos,int len);

 /** \brief busca en el array de juegos un indice libre y lo retorna
 * \param eJuegos*juegos
 * \param int len
 * \return entero que representa el indice vacio
 */
int obtenerEspacioLibre(eJuegos*juegos,int len);

/** \brief pide el ingreso de un entero (mediante otra funcion) ese entero representa el codigo de el juego y retorna
 *en la posicion en la que se encuentre ese codigo
 * \param eJuegos*juegos
 * \param int len
 * \return entero que representa un indice
 */
int BuscarPorId(eJuegos*juegos,int len);

/** \brief pide a una funcion que genere un ordenamiento, y lista los juegos de la structura Juegos, solo los espacios
 *que fueron cargados
 * \param eJuegos*juegos
 * \param int len
 * \return sin retorno
 */
void listarJuego(eJuegos* juego,int len);

/** \brief mediante el metodo de burbujeo swapea las structuras en base a que si el importe es mayor a otro(ascendente)
 * \param eJuegos*juegos
 * \param int len
 * \return 0
 */
int sortEmployees(eJuegos* list, int len);



//-------clientes funciones------

/** \brief inicializa en el array de clientes, en espacios vacios
 * \param eClientes*clientes
 * \param int len
 * \return sin retorno
 */
void initClientes(eClientes*clientes,int len);

/** \brief mediante un indice de espacio vacio, obtenido por otra funcion llena los campos correspondiente de la struc
 *tura clientes
 * \param eClientes*clientes
 * \param int len
 * \param int *PCodigoCliente
 * \return sin retorno
 */
void altaClientes(eClientes*clientes,int len,int *PCodigoCliente);

 /** \brief busca en el array de clientes un indice libre y lo retorna
 * \param eClientes*clientes
 * \param int len
 * \return entero que representa el indice vacio
 */
int obtenerEspacioLibreClientes(eClientes*clientes,int len);

/** \brief pide el ingreso de un entero (mediante otra funcion) y se podra modificar en esa posicion ingresada,en la structura
 *clientes
 * \param eClientes
 * \param int len
 * \return sin retorno
 */
void ModificarCliente(eClientes*clientes,int len);

/** \brief pide el ingreso de un entero (mediante otra funcion) ese entero representa el codigo de el cliente y retorna
 *en la posicion en la que se encuentre ese codigo
 * \param eClientes*clientes
 * \param int len
 * \return entero que representa un indice
 */
int buscarClientePorID(eClientes*clientes,int len);

/** \brief mediante un entero pasado por parametro, se realiza una baja logica de un campo determinado de la structura
 *clientes en el indice pasado por parametro
 * \param eClientes*clientes
 * \param int len
 * \param int idBajar
 * \return sin retorno
 */
void BajaClientes(eClientes*clientes,int len,int idBajar);

/** \brief pide a una funcion que genere un ordenamiento, y lista los clientes de la structura clientes, solo los espacios
 *que fueron cargados
 * \param eClientes* clientes
 * \param int len
 * \return sin retorno
 */
void listarClientes(eClientes* clientes,int len);

/** \brief mediante el metodo de burbujeo swapea las structuras haciendo que las ordene alfabeticamente, mediante apellido
 *y nombre
 * \param eClientes* list
 * \param int len
 * \return 0
 */
int sortClientes(eClientes* list, int len);

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
