#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define LEN 1000

int main()
{
eEmployee list[LEN];

char auxNombre[50];
char auxApellido[50];
float auxSalary;
int auxSector;

int idModificar;

initEmployees(list,LEN);
int respuesta;
int indexFree;

do{
    respuesta=PedirRespuesta();
    switch (respuesta){
    case 1:
        indexFree= obtenerEspacioLibre(list,LEN);
        if (indexFree!=-1){
        printf("\nIngrese Apellido: ");
        fflush(stdin);
        gets(auxApellido);

        printf("\nIngrese Nombre: ");
        fflush(stdin);
        gets(auxNombre);

        printf("\nIngrese salario: ");
        scanf("%f",&auxSalary);

        printf("\nIngrese sector: ");
        scanf("%d",&auxSector);

        addEmployee(list,LEN,indexFree,auxNombre,auxApellido,auxSalary,auxSector);
        }


        break;
    case 2:
        idModificar = idAModificarRespuesta();
        findEmployeeById(list,LEN,idAModificarRespuesta());



        break;
    case 3:

        break;
    case 4:

        break;
        }
    }while(respuesta);

}
