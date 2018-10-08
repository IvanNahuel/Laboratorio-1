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
    HarcodeoDeAlgunasFunciones(juegos,clientes);


    int gestionRespuesta;       //determinara si elegira operar en juegos, clientes o alquileres
    int respuestaClientes;
    int respuestaJuegos;
    int respuestaAlquileres;

    int idABajar;
    int idABajarCliente;

    do{
        printf("\n                                GESTION                           ");

        //
        //
        //IMPORTANTE FALTA A LOS SWTICHS REPARTIR SUS CORRESPONDIENTES FUNCIONES, en casa caso su determinada funcion
        //
        //
        gestionRespuesta = ImprimirMenuPrincipalYObtenerRespuesta();
        switch(gestionRespuesta){
        case 1:
            system("cls");
                do{
            respuestaJuegos = ImprimirMenuJuegos();
                switch (respuestaJuegos){
                //alta
                //alta
                case 1:
                    system("cls");
                    altaJuegos(juegos,LEN);
                break;
                case 2:
                //modificar
                    system("cls");
                    ModificarJuego(juegos,LEN);

                break;
                case 3:
                    //pedir ir del juego a bajar
                    //system("cls");
                    idABajar = pedirIdABajar("\nIngrese codigo de juego a bajar: ","\nError reingrese un codigo de juego valido: ");
                    BajaJuegos(juegos,LEN,idABajar);

                //baja
                break;
                case 4:
                    system("cls");
                    listarJuego(juegos,LEN);
                //listar
                break;
                case 5:
                    system("cls");
                //ir al menu principal
                continue;
                break;
                }
                }while(respuestaJuegos!=5);
            break;
        case 2:
            system("cls");
            do{
            respuestaClientes = ImprimirMenuClientes();
                switch (respuestaClientes){
                case 1:
                system("cls");
                altaClientes(clientes,LEN);
                //alta
                break;
                case 2:
                system("cls");
                ModificarCliente(clientes,LEN);
                //modificar
                break;
                case 3:
                system("cls");
                idABajarCliente = pedirIdABajar("\nIngrese el id del cliente a bajar: ","\nError reingrese un id valido de cliente");
                BajaClientes(clientes,LEN,idABajarCliente);
                //baja
                break;
                case 4:
                system("cls");
                listarClientes(clientes,LEN);
                //listar
                break;
                case 5:
                system("cls");
                //ir al menu principal
                continue;
                break;
                }
            }while(respuestaClientes!=5);
            break;
        case 3:
            respuestaAlquileres = ImprimirMenuAlquileres();
            switch(respuestaAlquileres){
                case 1:
                    //da de alta a los nuevos alquileres
                break;

                case 2:
                continue;           //cortar el switch y que imprima el menu
                break;
        }
            break;
        case 4:
            //salir

            break;
        }

    }while(gestionRespuesta!=4);
}











