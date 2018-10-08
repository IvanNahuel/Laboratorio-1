#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "InputsValidaciones.h"

 void initJuegos(eJuegos*juegos,int len){
    int i;
    for (i=0;i<len;i++){
        juegos[i].isEmpty=1;
    }
}
void altaJuegos(eJuegos*juegos,int len,int* codigoJuegoCont){
    int index;
    index = obtenerEspacioLibre(juegos,len);
    if (index!=-1){

        juegos[index].codigoJuego=*codigoJuegoCont;            //Descripcion validada
        *codigoJuegoCont=*codigoJuegoCont+1;

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
void ModificarJuego(eJuegos*juegos,int len){
    int i;
    int flag=1;
    int indice =BuscarPorId(juegos,len);

    if (indice!=-1){

        validarChares(juegos[indice].descripcion,51,"\nIngrese descripcion: ","\nError Ingrese una descripcion mas corta: ");

        juegos[indice].importe = ImporteValidado();      //VALIDADO
    }else {
    printf("\nJuego no encontrado Reintente");
    }
}

int BuscarPorId(eJuegos*juegos,int len){
int respuesta;
int indice=-1;
int i=0;
respuesta = pedirIdAModificar("\nIngrese codigo de juego a modificar: ","\nError reingrese un codigo de juego valido: ");
    for (i=0;i<len;i++){
        if (juegos[i].codigoJuego==respuesta && juegos[i].isEmpty==0){
            indice =i;
            break;
        }
    }
if (indice!=-1){
printf("\nse modificara: id: %d    nombre: %s",juegos[indice].codigoJuego,juegos[indice].descripcion);
}
return indice;
}



void listarJuego(eJuegos* juego,int len){
    int i;
    sortEmployees(juego,len);                //ordenamelo
    for (i=0;i<len;i++){
        if (juego[i].isEmpty==0){
            printf("\n%2d     %18s      %4d",juego[i].codigoJuego,juego[i].descripcion,juego[i].importe);
        }
    }
    printf("\n");
}
int sortEmployees(eJuegos* list, int len){
    eJuegos aux;
    int i;
    int j;
    int auxCodigoDeJuego;

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


void altaClientes(eClientes*clientes,int len,int *PCodigoCliente){
    int i;
    int index;
    index = obtenerEspacioLibreClientes(clientes,len);
    if (index!=-1){
        //printf("%d",index);
        clientes[index].codigoCliente=*PCodigoCliente;

        validarChares(clientes[index].apellido,51,"\nIngrese apellido del cliente: ","Error Reingrese un apellido mas corto: ");

        validarChares(clientes[index].nombre,51,"\nIngrese nombre del cliente: ","Error Reingrese un nombre mas corto: ");

        validarChares(clientes[index].domicilio,51,"Ingrese domicilio del cliente: ","Error Reingrese un domicilio mas corto: ");

        ValidarNumeroTelefonico(clientes[index].telefono);

        *PCodigoCliente=*PCodigoCliente+1;

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

void ModificarCliente(eClientes*clientes,int len){
    int i;
    int indice=buscarClientePorID(clientes,len);

    if (indice!=-1){

        validarChares(clientes[indice].apellido,51,"\nIngrese apellido del cliente: ","Error Reingrese un apellido mas corto: ");

        validarChares(clientes[indice].nombre,51,"\nIngrese nombre del cliente: ","Error Reingrese un nombre mas corto: ");

        validarChares(clientes[indice].domicilio,51,"Ingrese domicilio del cliente: ","Error Reingrese un domicilio mas corto: ");

        ValidarNumeroTelefonico(clientes[indice].telefono);
    }else {
    printf("\nCliente no encontrado reintente nuevamente");
    }

}

int buscarClientePorID(eClientes*clientes,int len){
int respuesta;
int index=-1;
int i;
respuesta = pedirIdAModificar("\nIngrese el codigo de cliente: ","\nError reingrese un codigo de cliente valido: ");
for (i=0;i<len;i++){
    if (clientes[i].codigoCliente==respuesta && clientes[i].isEmpty==0){
        index=i;
        break;
        }
    }
if (index!=-1){
//
printf("\nse modificara: id: %d    nombre: %s",clientes[index].codigoCliente,clientes[index].nombre);
}

return index;
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
    int auxCodigoDeCliente;
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
        printf("\n%d",index);

        alquileres[index].CodigoAlquiler = index;          //autoIncrimental, el primero libre

        alquileres[index].CodigoJuego = ValidarExistenciaDeCodigoDeJuego(juegos,len);//---VALIDADO

        alquileres[index].CodigoCliente = ValidarExistenciaDeCodigoDeCliente(clientes,len);//----VALIDADO

        alquileres[index].fecha.dia = DiaValidar();     //----VALIDADO

        alquileres[index].fecha.mes = MesValidar();     //----VALIDADO

        alquileres[index].fecha.anio = AnioValidar();   //----VALIDADO
    }
}

//----------Otras funciones
void HarcodeoDeAlgunasFunciones(eJuegos*juegos,eClientes*clientes,int* codigoJuegoCont,int* codigoClienteCont){

        juegos[0].codigoJuego=0;

        strcpy(juegos[0].descripcion,"Call of duty");

        juegos[0].importe = 15;

        juegos[0].isEmpty=0;


        juegos[1].codigoJuego=1;

        strcpy(juegos[1].descripcion,"Halo 5");

        juegos[1].importe = 150;

        juegos[1].isEmpty=0;

        *codigoJuegoCont=2;

        //listarJuego(juegos,LEN);


        //harcodeo cliente

        clientes[0].codigoCliente=0;

        strcpy(clientes[0].apellido,"Souza");

        strcpy(clientes[0].nombre,"Ivan");

        strcpy(clientes[0].domicilio,"Palacios 605");

        strcpy(clientes[0].telefono, "1558267965");

        clientes[0].isEmpty=0;


        clientes[1].codigoCliente=1;

        strcpy( clientes[1].apellido,"Zalazar");

        strcpy( clientes[1].nombre,"Matias");

        strcpy( clientes[1].domicilio,"Martin Fiero 748");

        strcpy( clientes[1].telefono, "1132748401");

        clientes[1].isEmpty=0;

        *codigoClienteCont=2;

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
    printf("\n                                ALQUILERES                           ");
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
    printf("\n                                CLIENTES                           ");
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
    printf("\n                                JUEGOS                           ");
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

int pedirIdAModificar(char*mensaje,char*mensajeError){
    int flag=1;
    int respuesta;
    do{
    if (flag){
    printf("%s",mensaje);
    flag=0;
    }else {
    printf("%s",mensajeError);
    }

    scanf("%d",&respuesta);
    }while (respuesta<0||respuesta>1000);

return respuesta;
}

int pedirIdABajar(char*mensaje,char*mensajeError){
    int flag=1;
    int respuesta;
    do{
    if (flag){
    printf("%s",mensaje);
    flag=0;
    }else {
    printf("%s",mensajeError);
    }

    scanf("%d",&respuesta);
    }while (respuesta<0||respuesta>1000);

return respuesta;

}
void ImprimirCartelDeFlags(char*pCadena){
system("cls");
printf("%s",pCadena);
}





