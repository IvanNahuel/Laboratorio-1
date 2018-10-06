#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#include "InputsValidaciones.h"
#define LEN 1000

int main()
{


    eJuegos juegos[LEN];
    eClientes clientes[LEN];
    eAlquileres alquileres[LEN];

    initJuegos(juegos,LEN);
    initClientes(clientes,LEN);
    initAlquileres(alquileres,LEN);

    //harcodeo
        juegos[0].codigoJuego=0;

        strcpy(juegos[0].descripcion,"Call of duty");

        juegos[0].importe = 15;

        juegos[0].isEmpty=0;


        juegos[1].codigoJuego=1;

        strcpy(juegos[1].descripcion,"Halo 5");

        juegos[1].importe = 150;

        juegos[1].isEmpty=0;

        listarJuego(juegos,LEN);



    //--------------ZONA DE PRUEBAS-------------------


    //ALTA, BAJA, MODIFICACION  Y LISTADO DE JUEGO VALIDADAS
    //ALTA, BAJA, MODIFICACION  Y LISTADO DE CLIENTES VALIDADAS

    //FALTA VALIDAR EL ALTA DE ALQUILERES <-----(TENER EN CUENTA QUE DEBE EXISTIR UN CODIGO DE *JUEGO* Y DE *CLIENTE* ) *******

    //UNA VEZ VALIDADO TODO, SE COMIENZA A ARMAR EL SISTEMA, CON SU RESPECTIVA INTERFAZ#########



}











