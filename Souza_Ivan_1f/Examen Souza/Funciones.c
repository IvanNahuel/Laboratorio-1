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

    int retorno=0;
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

        alquileres[index].CodigoAlquiler = index;          //autoIncrimental, el primero libre

        alquileres[index].CodigoJuego = ValidarExistenciaDeCodigoDeJuego(juegos,len);//---VALIDADO

        alquileres[index].CodigoCliente = ValidarExistenciaDeCodigoDeCliente(clientes,len);//----VALIDADO

        alquileres[index].fecha.dia = DiaValidar();     //----VALIDADO

        alquileres[index].fecha.mes = MesValidar();     //----VALIDADO

        alquileres[index].fecha.anio = AnioValidar();   //----VALIDADO

        alquileres[index].isEmpty=0;
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
    printf("\n4-informes");
    printf("\n5-Salir");
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
//informes

//promedio total de los importes de los juegos alguilados
//vamos a acceder a alquileres y sumar todos los juegos alquilados,sumarlos y dividirlos por la cant de juegos alquilados
void PromedioYTotalJuegos(eAlquileres*alquileres,eJuegos*juegos,int len){
    int i;
    int cont=0;
    int acumProm=0;
    float promedio=0;


    for (i=0;i<len;i++){
        if (alquileres[i].isEmpty==0){
            //tengo que buscar el codigo de juego y sumar su importe
            printf("\nEntro al for");
            cont++;
            acumProm = (float)juegos[alquileres[i].CodigoJuego].importe+acumProm;
        }
    }
    promedio=acumProm/cont;
    printf("\nA)-la suma total de alquileres es: %d y el promedio es %.2f",acumProm,promedio);

    //CantidadJuegosMenorImporte(promedio,juegos,len);
}
void CantidadJuegosMenorImporte(float promedio,eJuegos*juegos,int len){
    printf("\n\n%f",promedio);
    int j;
    printf("\nB)-La cantidad de juegos cuyo importe no superan el promedio son: \n");
    for (j=0;j<len;j++){
        if (juegos[j].isEmpty==0 && juegos[j].importe < promedio ){
             printf("\n%2d     %18s      %4d",juegos[j].codigoJuego,juegos[j].descripcion,juegos[j].importe);
        }
    }
}
void ClientesJuegoDeterminado(eJuegos*juegos,int len,eClientes*clientes,eAlquileres*alquileres){
    int i;
    printf("\n\nC)-------Clientes que alquilaron un juego determinado--------");
    //lista de todos los clientes que alquilaron un juego determinado
    //ingresar un codigo de juego determinado, y listar todos sus clientes
    //debo ver en el campo alquiler quien alquilo ese juego y listar su codigo de cliente

    int codigoDeJuego;
    codigoDeJuego = ValidarExistenciaDeCodigoDeJuego(juegos,len);

    for (i=0;i<len;i++){
        if (alquileres[i].isEmpty==0 && alquileres[i].CodigoJuego==codigoDeJuego ){
            printf("\n%15s   %15s  ",  clientes[alquileres[i].CodigoCliente].nombre,  clientes[alquileres[i].CodigoCliente].apellido);
        }
    }
}
void JuegosClientesDeterminado(eJuegos*juegos,int len,eClientes*clientes,eAlquileres*alquileres){
        int i;
    printf("\n\nD)-------alquileres de Juegos de clientes determinados--------");
    //lista de todos los juegos que fueron alguilador por un deterinado cliente


    int codigoDeCliente;
    codigoDeCliente = ValidarExistenciaDeCodigoDeCliente(clientes,len);

    for (i=0;i<len;i++){
        if ( alquileres[i].isEmpty==0 && alquileres[i].CodigoCliente == codigoDeCliente ){
            printf("\n%15s ",  juegos[alquileres[i].CodigoJuego].descripcion);
        }
    }
}
void JuegosMenosAlquilados(eJuegos*juegos,eAlquileres*alquileres,int len){
    printf("\n---------Juegos menos alquilados----------- ");
    //tengo que recorrer el array de alquileres y contar los juegos menos alquilados
    //acceder a alquileres y contar los codigos de juegos alquilados almacenarlos en un array de 1000 y fijarse cual es el menor
    //dependiendo del index guardarlo en el array
    //y despues ir depurando el menor
    int auxCodigosJuegos[len];  //guarda los codigos de juegos
    int auxContParalelo[len];

    int indiceCodigoDeJuegoMenor;
    int minimo;

    int i;
    int j;
    int k;

    for (j=0;j<len;j++){
        auxContParalelo[j]=0;
    }
    for (i=0;i<len;i++){
        if (alquileres[i].isEmpty==0){
                auxCodigosJuegos[i] ==alquileres[i].CodigoJuego;
                auxContParalelo[alquileres[i].CodigoJuego]++;
        }
    }
    for (k=0;k<len;k++){
        if (k==0){
            minimo=auxContParalelo[i];
            indiceCodigoDeJuegoMenor=auxCodigosJuegos[i];
        }
        if (auxContParalelo[i]<minimo){
            minimo=auxContParalelo[i];
            indiceCodigoDeJuegoMenor=auxCodigosJuegos[i];
        }
    }
    int z;
    for(z=0;z<10;z++){
        printf("\n%d",auxContParalelo[z]);
    }
    int x;

    for(x=0;x<10;x++){
        printf("\n%d",auxCodigosJuegos[x]);
    }

printf("\nEl juego menos alquilado es");
printf("\n%2d     %18s      %4d",juegos[indiceCodigoDeJuegoMenor].codigoJuego,juegos[indiceCodigoDeJuegoMenor].descripcion,juegos[indiceCodigoDeJuegoMenor].importe);
}
void JuegosEnFechaDeterminada(eJuegos*juegos,eAlquileres*alquileres,int len){
//ingresamos una fecha y que imprima todos los juegos alquilados en esa fecha
printf("\n\nG)---------juegos en una fecha determinada----------");
    eFecha fecha;
    fecha.dia = DiaValidar();
    fecha.mes = MesValidar();
    fecha.anio = AnioValidar();
    int i;

    for (i=0;i<len;i++){
        if (juegos[i].isEmpty==0 && fecha.dia == alquileres[i].fecha.dia && fecha.mes == alquileres[i].fecha.mes && fecha.anio == alquileres[i].fecha.anio){
        printf("\n%2d     %18s      %4d",juegos[i].codigoJuego,juegos[i].descripcion,juegos[i].importe);
        }
    }
}
void ClientesEnFechaDeterminada(eClientes*clientes,eAlquileres*alquileres,int len){
    printf("\n\nH)clientes en fecha determinada");
    eFecha fecha;
    fecha.dia = DiaValidar();
    fecha.mes = MesValidar();
    fecha.anio = AnioValidar();
    int i;

    for (i=0;i<len;i++){
        if (clientes[i].isEmpty==0 && fecha.dia == alquileres[i].fecha.dia && fecha.mes == alquileres[i].fecha.mes && fecha.anio == alquileres[i].fecha.anio){
        printf("\n%3d        %15s        %15s        %20s         %20s",clientes[i].codigoCliente,clientes[i].apellido,clientes[i].nombre,clientes[i].domicilio,clientes[i].telefono);
        }
    }
}

void SortMoreEficient(eJuegos*juegos,int len){
//listar todos los juegos de manera descendente con el metodo mas eficiente
printf("\n\nI)-Burbujeo mas eficiente");
    int j;
    eJuegos auxJuegos;
    int flag=1;
    while (flag==1){
        flag=0;
        for (j=1;j<len;j++){
            if ( juegos[j].importe>juegos[j].importe ){
                auxJuegos= juegos[j];
                juegos[j]=juegos[j-1];
                juegos[j-1]=auxJuegos;
                flag=1;
            }
        }
    }
    listarJuego(juegos,len);
}
void SortInsertion(eClientes*clientes,int len){
    printf("\n\nJ)-Metodo insercion");
int i;
int j;
eClientes auxClientes;

for (i=1;i<len;i++){
    auxClientes = clientes[i];
    j=i-1;
    while ( j>=0 && strcmp(clientes[i].apellido,clientes[j].apellido)>0){
        clientes[j+1]=clientes[j];
        j--;
        }
        clientes[j+1]=auxClientes;
    }
    listarClientes(clientes,len);
}









