#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define LEN 1000

int main()
{
eEmployee list[LEN];

char auxNombre[50];
char auxApellido[50];
float AuxSalario;
int AuxSector;

int idModificar;
int idEliminar;

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
        scanf("%f",&AuxSalario);

        printf("%f",AuxSalario);

        printf("\nIngrese sector: ");
        scanf("%d",&AuxSector);

        printf("%d",AuxSector);

        addEmployee(list,LEN,indexFree,auxNombre,auxApellido,AuxSalario,AuxSector);
        }
        break;
    case 2:
        idModificar = idAModificarRespuesta();
        if (findEmployeeById(list,LEN,idModificar)!=-1){
        modificarEmploy(list,LEN,idModificar);
        }
        break;
    case 3:
        printf("\nIngrese el id del empleado que desea eliminar:");
        scanf("%d",&idEliminar);
        removeEmployee(list,LEN,idEliminar);

        break;
    case 4:
        printEmployees(list,LEN);

        break;
        }
    }while(respuesta);

}
