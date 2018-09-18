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


                break;
            case 3:

                break;
            case 4:
                Listar(persona,CANT);
                break;
            case 5:

                break;



        }

        //switch
        //dependiendo del caso ejecutar x funcion

    }while(respuesta!=5);


/*
persona.dni;
persona.apellido;
persona.nombre;
persona.fechaNac.dia;
persona.fechaNac.mes;
persona.fechaNac.anio;
*/
//alta, baja, modificacion, listar, salir

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

//%ld long entero

void alta(ePersona personas[],int cant){
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
            //dni nombre apellido fechaNacimiento
            printf("\n%ld  %s  %s  %d/%d/%d",personas[i].dni,personas[i].nombre,personas[i].apellido,personas[i].fechaNac.dia,personas[i].fechaNac.mes,personas[i].fechaNac.anio);
        }
    }
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
        if (persona[i].dni == dni){
            retorno=i;
        }
    }
    return retorno;
}


