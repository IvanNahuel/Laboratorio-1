#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#include "InputsValidaciones.h"
#define LEN 1000

int main()
{
    int gestionRespuesta;       //determinara si elegira operar en juegos, clientes o alquileres
    int respuestaClientes;
    int respuestaJuegos;
    int respuestaAlquileres;

    int idABajar;
    int idABajarCliente;

    int codigoJuegoCont=0;
    int *PcodigoJuegoCont;
    PcodigoJuegoCont=&codigoJuegoCont;

    int flagBajaModificarJuegos=0;
    int flagBajaModificarClientes=0;

    int codigoClienteCont=0;
    int* PcodigoClienteCont;
    PcodigoClienteCont = &codigoClienteCont;

    eJuegos juegos[LEN];
    eClientes clientes[LEN];
    eAlquileres alquileres[LEN];

    initJuegos(juegos,LEN);
    initClientes(clientes,LEN);
    initAlquileres(alquileres,LEN);

    HarcodeoDeAlgunasFunciones(juegos,clientes,PcodigoJuegoCont,PcodigoClienteCont);

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
                    altaJuegos(juegos,LEN,PcodigoJuegoCont);
                    flagBajaModificarJuegos=1;
                break;
                case 2:
                //modificar
                    if (flagBajaModificarJuegos){
                    system("cls");
                    ModificarJuego(juegos,LEN);
                    }else {
                    ImprimirCartelDeFlags("\nSe debera dar de alta por lo menos una vez antes de modificar juegos");
                    }
                break;
                case 3:
                    if (flagBajaModificarJuegos){
                    idABajar = pedirIdABajar("\nIngrese codigo de juego a bajar: ","\nError reingrese un codigo de juego valido: ");
                    BajaJuegos(juegos,LEN,idABajar);
                    }else {
                    ImprimirCartelDeFlags("\nSe debera dar de alta por lo menos una vez antes de bajar juegos");
                    }
                //baja
                break;
                case 4:
                    if (flagBajaModificarJuegos){
                    system("cls");
                    listarJuego(juegos,LEN);
                    }else {
                    ImprimirCartelDeFlags("\nSe debera dar de alta por lo menos una vez antes de listar los juegos");
                    }
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
                altaClientes(clientes,LEN,PcodigoClienteCont);
                flagBajaModificarClientes=1;
                //alta
                break;
                case 2:
                if (flagBajaModificarClientes){
                system("cls");
                ModificarCliente(clientes,LEN);
                }else {
                ImprimirCartelDeFlags("\nSe debera dar de alta por lo menos una vez antes de comenzar a bajar clientes");
                }
                //modificar
                break;
                case 3:
                if (flagBajaModificarClientes){
                system("cls");
                idABajarCliente = pedirIdABajar("\nIngrese el id del cliente a bajar: ","\nError reingrese un id valido de cliente");
                BajaClientes(clientes,LEN,idABajarCliente);
                }else {
                ImprimirCartelDeFlags("\nSe debera dar de alta por lo menos una vez antes de comenzar a modificar clientes");
                }

                //baja
                break;
                case 4:
                if (flagBajaModificarClientes){
                system("cls");
                listarClientes(clientes,LEN);
                }else {
                ImprimirCartelDeFlags("\nSe debera dar de alta por lo menos una vez antes de comenzar a listar clientes");
                }
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
            system("cls");
            do{
            respuestaAlquileres = ImprimirMenuAlquileres();
            switch(respuestaAlquileres){
                case 1:
                    system("cls");
                    altaAlquileres(alquileres,LEN,juegos,clientes);
                break;
                case 2:
                    system("cls");
                continue;           //cortar el switch y que imprima el menu
                break;
                }
        }while(respuestaAlquileres!=2);
            break;
        case 4:
            //salir

            break;
        }

    }while(gestionRespuesta!=4);
}











