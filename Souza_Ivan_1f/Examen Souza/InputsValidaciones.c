#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Funciones.h"
#include "InputsValidaciones.h"
int DiaValidar(){
    int dia;
    do{
        printf("\nIngrese Dia del alquiler: ");
        scanf("%d",&dia);
    }while (dia<0||dia>31);
    return dia;
}
int MesValidar(){
    int mes;
    do{
        printf("\nIngrese mes del alquiler: ");
        scanf("%d",&mes);
    }while (mes<0||mes>12);
    return mes;
}
int AnioValidar(){
    int anio;
    do{
        printf("\nIngrese anio del alquiler: ");
        scanf("%d",&anio);
    }while (anio<0||anio>2019);
    return anio;
}
 //------funciones validaciones de juegos
 int ImporteValidado(){
    int retorno;
    do{
    printf("\ingrese importe: ");
    scanf("%d",&retorno);
    }while(retorno<0);
 }
/*  valida que en la planilla clientes, haya un codigo de juegos existentes, para cargarlos en el campo codigo de juego
*
*/
int ValidarExistenciaDeCodigoDeJuego(eJuegos*juegos,int len){
    int codigoIngresado;
    int flagWhile=0;

    int i;
    do{
    printf("\nIngrese codigo de juego: ");
    scanf("%d",codigoIngresado);
    for (i=0;i<len;i++){
        if (juegos[i].isEmpty==0 && juegos[i].codigoJuego == codigoIngresado){
            flagWhile=1;
            break;
        }
    }
        }while(flagWhile==0);
return codigoIngresado;
}
/*  valida que en la planilla alquileres, haya un codigo de clientes existentes, para cargarlos en el campo codigo de cliente
*
*/

int ValidarExistenciaDeCodigoDeCliente(eClientes*clientes,int len){
    int codigoIngresado;
    int flagWhile=0;

    int i;
    do{
    printf("\nIngrese codigo de cliente: ");
    scanf("%d",codigoIngresado);
    for (i=0;i<len;i++){
        if (clientes[i].isEmpty==0 && clientes[i].codigoCliente == codigoIngresado){
            flagWhile=1;
            break;
        }
    }
        }while(flagWhile==0);
return codigoIngresado;
}

//se ingresa un char, validamos caracteres si es mayor a ese numero error reingrese mas corto, y el mensaje puesto
//en cadena error

 char validarChares(int caracterMaximo,char cadenaMensaje,char cadenaError){
    int cantidad;
    char retorno[60];
    do {
            printf(cadenaMensaje);

            fgets(retorno,sizeof(retorno)-2,stdin);
            cantidad = strlen(retorno);
            retorno[cantidad-1] = '\0';
            //printf("%s", retorno);


    }while(cantidad-1>caracterMaximo);


return retorno;
 }







