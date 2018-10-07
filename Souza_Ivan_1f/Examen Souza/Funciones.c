#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "InputsValidaciones.h"

void test(){
printf("hola");
}

 void initJuegos(eJuegos*juegos,int len){
    int i;
    for (i=0;i<len;i++){
        juegos[i].isEmpty=1;
    }
}
void altaJuegos(eJuegos*juegos,int len){
    int index;
    index = obtenerEspacioLibre(juegos,len);
    if (index!=-1){

        juegos[index].codigoJuego=index;            //Descripcion validada

        validarChares(juegos[index].descripcion,51,"\nIngrese descripcion: ","\nError Ingrese una descripcion mas corta: ");

        juegos[index].importe = ImporteValidado();      //VALIDADO

        juegos[index].isEmpty=0;
        //printf("\n!alta exitosa");
    }
}
int obtenerEspacioLibre(eJuegos*juegos,int len){
    int i;
    int retorno=-1;
    for (i=0;i<len;i++){
        if (juegos[i].isEmpty==1){
            retorno =i;
            break;
        }
    }
    return retorno;
}
void BajaJuegos(eJuegos*juegos,int len,int idBajar){
int i;
for (i=0;i<len;i++){
    if (juegos[i].codigoJuego==idBajar){
        juegos[i].isEmpty=1;
        break;
        }
    }
}
void ModificarJuego(eJuegos*juegos,int len,int idModificar){
    int i;
    int flag=1;

    for (i=0;i<len;i++){
        if (juegos[i].codigoJuego==idModificar && juegos[i].isEmpty==0 ){
        printf("\nindex: %d",i);
        validarChares(juegos[idModificar].descripcion,51,"\nIngrese descripcion: ","\nError Ingrese una descripcion mas corta: ");

        juegos[idModificar].importe = ImporteValidado();      //VALIDADO
        flag =0;
        break;
        }
    }
    if (flag){
        printf("\nNo se ha encontrado el indice buscado, verifique que sea el correcto");
    }
}
void listarJuego(eJuegos* juego,int len){
    int i;
    sortEmployees(juego,len);                //ordenamelo
    for (i=0;i<len;i++){
        if (juego[i].isEmpty==0){
            //sortEmployees(juego,len);                //ordenamelo
            printf("\n%2d     %10s      %4d",juego[i].codigoJuego,juego[i].descripcion,juego[i].importe);
        }
    }
}
int sortEmployees(eJuegos* list, int len){
    eJuegos aux;
    int i;
    int j;
    int retorno=-1;
    if (list!=NULL && len>0){
        for ( i=0;i<len-1;i++){
            for ( j=i+1;j<len;j++){
                if (list[i].importe < list[j].importe && list[i].isEmpty==0 && list[j].isEmpty==0){           //si i es menor a j
                    aux = list[i];
                    list[i]=list[j];
                    list[j]=aux;

                } else if ( list[i].importe==list[j].importe && strcmp(list[i].descripcion,list[j].descripcion)>0 && list[i].isEmpty==0 && list[j].isEmpty==0 ){
                    printf("\nOdeno por nombre\n");
                    aux = list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }
        }
    }
    return retorno;
}

//------------funciones Clientes----

 void initClientes(eClientes*clientes,int len){
    int i;
    for (i=0;i<len;i++){
        clientes[i].isEmpty=1;
    }
}


void altaClientes(eClientes*clientes,int len){
    int i;
    int index;
    index = obtenerEspacioLibreClientes(clientes,len);
    if (index!=-1){
        //printf("%d",index);
        clientes[index].codigoCliente=index;

        validarChares(clientes[index].apellido,51,"\nIngrese apellido del cliente: ","Error Reingrese un apellido mas corto: ");

        validarChares(clientes[index].nombre,51,"\nIngrese nombre del cliente: ","Error Reingrese un nombre mas corto: ");

        validarChares(clientes[index].domicilio,51,"Ingrese domicilio del cliente: ","Error Reingrese un domicilio mas corto: ");

        ValidarNumeroTelefonico(clientes[index].telefono);

        clientes[index].isEmpty=0;

    }
}
int obtenerEspacioLibreClientes(eClientes*clientes,int len){
    int i;
    int retorno=-1;
    for (i=0;i<len;i++){
        if (clientes[i].isEmpty==1){
            retorno =i;
            break;
        }
    }
    return retorno;
}

void ModificarCliente(eClientes*clientes,int len,int idModificar){
    int flag=1;

    int i;
    for (i=0;i<len;i++){
        if ( clientes[i].isEmpty==0 && clientes[i].codigoCliente==idModificar){

        validarChares(clientes[idModificar].apellido,51,"\nIngrese apellido del cliente: ","Error Reingrese un apellido mas corto: ");

        validarChares(clientes[idModificar].nombre,51,"\nIngrese nombre del cliente: ","Error Reingrese un nombre mas corto: ");

        validarChares(clientes[idModificar].domicilio,51,"Ingrese domicilio del cliente: ","Error Reingrese un domicilio mas corto: ");

        ValidarNumeroTelefonico(clientes[idModificar].telefono);

        flag=0;
        break;
        }
    }
    if (flag){
        printf("\nError no se ha encontrado el codigo de cliente ingresado reintente ");
    }
}
void BajaClientes(eClientes*clientes,int len,int idBajar){
int i;
for (i=0;i<len;i++){
    if (clientes[i].codigoCliente==idBajar &&clientes[i].isEmpty==0){
        clientes[i].isEmpty=1;
        break;
        }
    }
}

void listarClientes(eClientes* clientes,int len){
    int i;
    sortClientes(clientes,len);                //ordenamelo
    for (i=0;i<len;i++){
        if (clientes[i].isEmpty==0){
            printf("\n%3d        %15s        %15s        %20s         %20s",clientes[i].codigoCliente,clientes[i].apellido,clientes[i].nombre,clientes[i].domicilio,clientes[i].telefono);
        }
    }
}
int sortClientes(eClientes* list, int len){
    eClientes aux;
    int i;
    int j;
    int retorno=-1;
    if (list!=NULL && len>0){
        for ( i=0;i<len-1;i++){
            for ( j=i+1;j<len;j++){
                if ( list[i].isEmpty==0 && list[j].isEmpty==0 && strcmp(list[i].apellido,list[j].apellido)>0){           //si i es menor a j
                    aux = list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
                else if (list[i].isEmpty==0 && list[j].isEmpty==0 && strcmp(list[i].apellido,list[j].apellido)==0){
                    if (strcmp(list[i].nombre,list[j].nombre)>0){
                        aux = list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                }
            }
        }
    }
    return retorno;
}

//--------funciones alquileres------
 void initAlquileres(eAlquileres*alquileres,int len){
    int i;
    for (i=0;i<len;i++){
        alquileres[i].isEmpty=1;
    }
}
int obtenerEspacioLibreAlquileres(eAlquileres*alquileres,int len){
    int i;
    int retorno=-1;
    for (i=0;i<len;i++){
        if (alquileres[i].isEmpty==1){
            retorno =i;
            break;
        }
    }
    return retorno;
}
void altaAlquileres(eAlquileres*alquileres,int len,eJuegos*juegos,eClientes*clientes){
    int i;
    int index;
    index = obtenerEspacioLibreAlquileres(alquileres,len);
    if (index!=-1){
        printf("\n%d",i);

        alquileres[index].CodigoAlquiler = index;          //autoIncrimental, el primero libre

        alquileres[index].CodigoJuego = ValidarExistenciaDeCodigoDeJuego(juegos,len);//---VALIDADO

        alquileres[index].CodigoCliente = ValidarExistenciaDeCodigoDeCliente(clientes,len);//----VALIDADO

        alquileres[index].fecha.dia = DiaValidar();     //----VALIDADO

        alquileres[index].fecha.mes = MesValidar();     //----VALIDADO

        alquileres[index].fecha.anio = AnioValidar();   //----VALIDADO
    }
}
void HarcodeoDeAlgunasFunciones(eJuegos*juegos,eClientes*clientes){
        juegos[0].codigoJuego=0;

        strcpy(juegos[0].descripcion,"Call of duty");

        juegos[0].importe = 15;

        juegos[0].isEmpty=0;


        juegos[1].codigoJuego=1;

        strcpy(juegos[1].descripcion,"Halo 5");

        juegos[1].importe = 150;

        juegos[1].isEmpty=0;

        //listarJuego(juegos,LEN);


        //harcodeo cliente


        clientes[0].codigoCliente=0;

        strcpy(clientes[0].apellido,"souza");

        strcpy(clientes[0].nombre,"ivan");

        strcpy(clientes[0].domicilio,"Palacios 605");

        strcpy(clientes[0].telefono, "1558267965");

        clientes[0].isEmpty=0;


        clientes[1].codigoCliente=1;

        strcpy( clientes[1].apellido,"Zalazar");

        strcpy( clientes[1].nombre,"Matias");

        strcpy( clientes[1].domicilio,"Martin Fiero 748");

        strcpy( clientes[1].telefono, "1132748401");

        clientes[1].isEmpty=0;


        //printf("el cliente es: %s      y alquilo el juego: %s       %d/%d/%d", clientes[alquileres[0].CodigoCliente].nombre ,  juegos[alquileres[0].CodigoJuego].descripcion,alquileres[0].fecha.dia,alquileres[0].fecha.mes,alquileres[0].fecha.anio);

}

int ImprimirMenuPrincipalYObtenerRespuesta(){
    int respuesta;
    int flag=1;

    printf("\n1-Juegos");
    printf("\n2-Clientes");
    printf("\n3-Alquileres");
    printf("\n4-Salir");
    do{
    if (flag){
    printf("\nIngrese Respuesta: ");
    flag=0;
    }else {
    printf("\nError Reingrese respuesta correcta: ");
    }
    scanf("%d",&respuesta);

    }while(respuesta<=0||respuesta>4);
return respuesta;
}

int ImprimirMenuAlquileres(){
    int respuesta;
    int flag=1;
    printf("                                ALQUILERES                           ");
    printf("\n1-Altas");
    printf("\n2-Ir al menu principal");

    do{
    if (flag){
    printf("\nIngrese Respuesta: ");
    flag=0;
    }else {
    printf("\nError Reingrese respuesta correcta: ");
    }
    scanf("%d",&respuesta);

    }while(respuesta<=0||respuesta>2);

return respuesta;
}


int ImprimirMenuClientes(){
    int respuesta;
    int flag=1;
    printf("                                CLIENTES                           ");
    printf("\n1-Altas");
    printf("\n2-Modificar");
    printf("\n3-Baja");
    printf("\n4-Listar");
    printf("\n5-Ir al menu principal");

    do{
    if (flag){
    printf("\nIngrese Respuesta: ");
    flag=0;
    }else {
    printf("\nError Reingrese respuesta correcta: ");
    }
    scanf("%d",&respuesta);

    }while(respuesta<=0||respuesta>5);

return respuesta;
}




int ImprimirMenuJuegos(){
    int respuesta;
    int flag=1;
    printf("                                JUEGOS                           ");
    printf("\n1-Altas");
    printf("\n2-Modificar");
    printf("\n3-Baja");
    printf("\n4-Listar");
    printf("\n5-Ir al menu principal");

    do{
    if (flag){
    printf("\nIngrese Respuesta: ");
    flag=0;
    }else {
    printf("\nError Reingrese respuesta correcta: ");
    }
    scanf("%d",&respuesta);

    }while(respuesta<=0||respuesta>5);

return respuesta;
}






