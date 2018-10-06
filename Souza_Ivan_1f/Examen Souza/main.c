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



    //--------------ZONA DE PRUEBAS-------------------
    printf("\nAltas\n");
    altaJuegos(juegos,LEN);
    altaJuegos(juegos,LEN);
    altaJuegos(juegos,LEN);
    altaJuegos(juegos,LEN);

    listarJuego(juegos,LEN);




    //HASTA AHORA VALIDE ALTA DE JUEGOS, Y DE CLIENTES
    //ALTA, BAJA, MODIFICACION DE JUEGO VALIDADAS



    //FALTA VALIDAR BAJA Y MODIFICACION DE JUEGOS Y CLIENTES




}











