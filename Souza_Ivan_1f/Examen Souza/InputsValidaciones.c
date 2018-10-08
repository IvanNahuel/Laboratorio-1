#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Funciones.h"
#include "InputsValidaciones.h"
int DiaValidar(){

    int flag=1;
    int dia;
    do{
        if (flag){
        printf("\nIngrese Dia del alquiler: ");
        flag=0;
        }else {
        printf("\nReingrese un dia valido: ");
        }

        scanf("%d",&dia);
    }while (dia<0||dia>31);
    return dia;
}
int MesValidar(){
    int flag=1;
    int mes;
    do{
        if (flag){
        printf("\nIngrese mes del alquiler: ");
        flag=0;
        }else {
        printf("\nReingrese un mes valido: ");
        }

        scanf("%d",&mes);
    }while (mes<0||mes>12);
    return mes;
}
int AnioValidar(){
    int flag=1;
    int anio;
    do{
        if (flag){
        printf("\nIngrese anio del alquiler: ");
        flag =0;
        }else {
        printf("\nReingrese un anio valido: ");
        }

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
    return retorno;
 }
/*  valida que en la planilla clientes, haya un codigo de juegos existentes, para cargarlos en el campo codigo de juego
*
*/
int ValidarExistenciaDeCodigoDeJuego(eJuegos*juegos,int len){
    int codigoIngresado;
    int flagWhile=0;
    int flagError=1;
    int i;
    do{
    printf("\nIngrese codigo de juego: ");
    fflush(stdin);
    scanf("%d",&codigoIngresado);
    for (i=0;i<len;i++){
        if (juegos[i].isEmpty==0 && juegos[i].codigoJuego == codigoIngresado){
            flagWhile=1;
            flagError=0;
            break;
        }
    }
    if (flagError){
        printf("\nEl codigo de juego no existe, Reingrese un codigo existente: ");
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
    int flagValidar=1;

    int i;
    do{
    printf("\nIngrese codigo de cliente: ");
    scanf("%d",&codigoIngresado);
    for (i=0;i<len;i++){
        if (clientes[i].isEmpty==0 && clientes[i].codigoCliente == codigoIngresado){
            flagWhile=1;
            flagValidar=0;
            break;
        }
    }
    if (flagValidar){
        printf("\nEl codigo de cliente no existe, Reingrese un codigo existente");
    }
        }while(flagWhile==0);

return codigoIngresado;
}

//se ingresa un char, validamos caracteres si es mayor a ese numero error reingrese mas corto, y el mensaje puesto
//en cadena error

void validarChares(char*retornoParam,int caracterMaximo,char* cadenaMensaje,char* cadenaError){
    int cantidad;
    int flag=1;
    char retorno[60];
    do {
            if (flag==1){
            printf("%s",cadenaMensaje);
            flag=0;
            }else {
            printf("%s",cadenaError);
            }
            fflush(stdin);
            fgets(retorno,sizeof(retorno)-2,stdin);
            cantidad = strlen(retorno);
            retorno[cantidad-1] = '\0';
            //printf("\nla cantidad de letras es: %d\n",cantidad-1);
            //printf("\n%s\n", retorno);

    }while(cantidad-1>caracterMaximo);
   strcpy(retornoParam,retorno);
}
void ValidarNumeroTelefonico(char* pCadena){

    char retorno[50];
    int cantidad;
    int i;
    int flag=0;

    do{
        printf("\nIngrese un numero telefonico: ");
        fgets(retorno,sizeof(retorno)-2,stdin);
        cantidad = strlen(retorno);
        retorno[cantidad-1] = '\0';

    for (i=0;retorno[i]!='\0';i++){
        if (retorno[i]<48||retorno[i]>57){
            printf("\nError Reingrese un numero telefonico valido");
            flag=0;
            break;
            }
            else{
            flag=1;
            }
        }
    }while(flag==0);
    strcpy(pCadena,retorno);
    //printf("finalizo funcion validad numero");
}












