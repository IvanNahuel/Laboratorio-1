#include <stdio.h>
#include <stdlib.h>
#define CANT 5

typedef struct{
int dia,mes,anio;
}eFecha;

typedef struct{
long int dni;
char apellido[31];
char nombre[31];
eFecha fechaNac;
int isEmpty;
}ePersona;

int main()
{
    ePersona persona[CANT];
    init(persona,CANT);     //inicializa todos los espacios dentro del vector y los vacia
    int respuesta;

    do{
        respuesta=PedirRespuesta();
        switch (respuesta){
            case 1:
                alta(persona,CANT);

                break;
            case 2:
                Baja(persona,CANT);
                break;
            case 3:
                Modificacion(persona,CANT);
                break;
            case 4:
                Listar(persona,CANT);
                break;
            case 5:

                break;
        }

    }while(respuesta!=5);
}
void ImprimirMenu(){
    printf("\n1-Alta");
    printf("\n2-Baja");
    printf("\n3-Modificacion");
    printf("\n4-Listar");
    printf("\n5-salir");
}

void init(ePersona personas[],int cant){
    for (int i=0;i<cant;i++){
        personas[i].isEmpty=1;
    }
}

void alta(ePersona personas[],int cant){
    printf("\n-----------------------------------ALTAS------------------------------------");
    int index;
    int flagEspacio;
    long int auxiliarDni;
    index = obtenerEspacioLibre(personas,cant);

    if (index!=-1){

            printf("\nIngrese dni: ");
            scanf("\n%ld",&auxiliarDni);

            flagEspacio= buscarPorDni(personas,auxiliarDni,cant);
            //auxiliar dni y lo seteo al array

            if (flagEspacio==-1){

            personas[index].dni=auxiliarDni;

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(personas[index].nombre);

            printf("\nIngrese apellido: ");
            fflush(stdin);
            gets(personas[index].apellido);

            printf("\n----Fecha de nacimiento---\n");
            printf("\n\nIngrese dia: ");
            scanf("%d",&personas[index].fechaNac.dia);

            printf("\nIngrese mes: ");
            scanf("%d",&personas[index].fechaNac.mes);

            printf("\nIngrese anio: ");
            scanf("%d",&personas[index].fechaNac.anio);

            printf("\n!!Alta exitosa");

            personas[index].isEmpty=0;
            }else {
            printf("\nError ya existe ese DNI en la base de datos\n");
            }
    }
}
int PedirRespuesta(){
    int respuesa;
    printf("\nIngrese respuesta");
    ImprimirMenu();
    printf("\n");
    scanf("%d",&respuesa);
    while (respuesa<0 ||respuesa>5){
        printf("\nError, reingrese respuesta correcta: ");
        scanf("%d",&respuesa);
    }
    return respuesa;
}
void Listar(ePersona personas[],int cant){
    for (int i=0;i<cant;i++){
        if (personas[i].isEmpty==0){
            printf("\n%ld  %s  %s  %d/%d/%d",personas[i].dni,personas[i].nombre,personas[i].apellido,personas[i].fechaNac.dia,personas[i].fechaNac.mes,personas[i].fechaNac.anio);
        }
    }
}
void ListarPorIndex (ePersona personas[],int index){
    printf("\n%ld  %s  %s  %d/%d/%d",personas[index].dni,personas[index].nombre,personas[index].apellido,personas[index].fechaNac.dia,personas[index].fechaNac.mes,personas[index].fechaNac.anio);
}

int obtenerEspacioLibre(ePersona per[],int cantidad){
    int retorno=-1;
    for (int i=0;i<cantidad;i++){
        if (per[i].isEmpty==1){
            retorno =i;
            break;
        }
    }
    return retorno;
}
int buscarPorDni(ePersona persona[],long int dni,int cant){
    int retorno=-1;
    for (int i=0;i<cant;i++){
        if (persona[i].dni == dni && persona[i].isEmpty==0){
            retorno=i;
        }
    }
    return retorno;
}
int Baja(ePersona per[],int tamanio){
        printf("\n-----------------------------------BAJA------------------------------------");
    int respuestaEliminar;
    int retorno;
    int index;
    long int dni;
    printf("\ningrese dni: ");
    scanf("%ld",&dni);

    index = buscarPorDni(per,dni,tamanio);

    if (index==-1){
        printf("\nError, no se ha encontrado a la parsona");
        retorno=-1;
    } else {

        do{

        printf("\nDesea eliminar a");
        ListarPorIndex(per,index);

        respuestaEliminar = RespuetasSiNo();

        }while( respuestaEliminar!=1 && respuestaEliminar!=2);

        switch (respuestaEliminar){

        case 1:
        per[index].isEmpty=1;
        printf("\nBaja Exitosa");
        retorno=0;
        break;

        case 2:
            printf("\nBaja cancelada");
        break;
        }
    }
return retorno;
}
int RespuetasSiNo(){
    int retorno;
    printf("\n1-Si");
    printf("\n2-No");
    printf("\n");
    scanf("%d",&retorno);

    return retorno;
}
void Modificacion(ePersona per[],int tam){
    int respuesta;
    long int dni;
    int index;

    printf("\n---------------------------------MODIFICACIONES-------------------------------------");
    Listar(per,tam);
    printf("\nIngrese el dni de la persona que quiere modificar: ");
    scanf("%ld",&dni);

    index = buscarPorDni(per,dni,tam);

     if (index==-1){
        printf("\nError, no se ha encontrado a la parsona");
    } else {
    do {
    printf("\nDesea modificar a:");
    ListarPorIndex(per,index);
    respuesta = RespuetasSiNo();

    }while(respuesta!=1 && respuesta !=2 );

    switch(respuesta){
        case 1:

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(per[index].nombre);

            printf("\nIngrese apellido: ");
            fflush(stdin);
            gets(per[index].apellido);

            printf("\n----Fecha de nacimiento---\n");
            printf("\n\nIngrese dia: ");
            scanf("%d",&per[index].fechaNac.dia);

            printf("\nIngrese mes: ");
            scanf("%d",&per[index].fechaNac.mes);

            printf("\nIngrese anio: ");
            scanf("%d",&per[index].fechaNac.anio);
            printf("\nModificacion exitosa");

            break;
        case 2:
            printf("\nSe ha cancelado la modificacion");
            break;
        }
    }
}



