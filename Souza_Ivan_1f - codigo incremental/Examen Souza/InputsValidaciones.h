#ifndef InputsValidaciones_H_INCLUDED
#define InputsValidaciones_H_INCLUDED
/** \brief Pide un entero, y valida si es un dia valido, ya sea mayor a 0 y menor a 31
 * \param sin parametros
 * \return devuelve el dia validado
 */
int DiaValidar();
/** \brief Pide un entero, y valida si es un mes valido, ya sea mayor a 0 y menor a 12
 * \param sin parametros
 * \return devuelve el mes validado
 */
int MesValidar();
/** \brief Pide un entero, y valida si es un año valido, ya sea mayor a 0 y menor a 2019
 * \param sin parametros
 * \return devuelve el dia validado
 */
int AnioValidar();

/** \brief Pide un entero, y valida si es un importe valido, ya sea mayor 0
 * \param sin parametros
 * \return devuelve el importe validado
 */
int ImporteValidado();

/** \brief pide un entero y con ese entero verifica que exista un codigo de juego, si existe
 *lo devuelve como parametro, si no, vuelve a pedir
 * \param eJuegos*juegos
 * \param int len
 * \return devuelve el entero verificado
 */

int ValidarExistenciaDeCodigoDeJuego(eJuegos*juegos,int len);

/** \brief pide un entero y con ese entero verifica que exista un codigo de cliente, si existe
 *lo devuelve como parametro, si no, vuelve a pedir
 * \param eJuegos*juegos
 * \param int len
 * \return devuelve el entero verificado
 */

int ValidarExistenciaDeCodigoDeCliente(eClientes*clientes,int len);

/** \brief pide el ingreso de una cadena de caracteres y verifica con un entero pasado por parametro, que esa cadena
 *no supere el maximo permitido
 * \param eClientes*clientes
 * \param  int len
 * \return no devuelve nada
 */

void validarChares(char*retornoParam,int caracterMaximo,char* cadenaMensaje,char* cadenaError);

/** \brief pide el ingreso de un numero telefonico y verifica que realmente sea un numero, y que sea menor a 21
 * \param char* pCadena
 * \return no devuelve nada
 */

void ValidarNumeroTelefonico(char* pCadena);

















#endif
