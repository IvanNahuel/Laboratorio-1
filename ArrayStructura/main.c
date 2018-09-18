#include <stdio.h>
#include <stdlib.h>

struct eEmpleado{
    int legajo;
    char nombre[31];
    float salario;
    int isEmpty;

};

int main()
{
    struct eEmpleado emple[2];             //encapsulado datos
    //hardcodeo {{1,"juan",500,0},{2,"pedro",5000,2}

    for (int i=0;i<2;i++){
    printf("Ingrese numero de legajo: ");
    scanf("%d",&emple[i].legajo);

    printf("\ningrese nombre del empledo: ");
    fflush(stdin);
    gets(emple[i].nombre);

    printf("\ningrese salario: ");
    scanf("%f",&emple[i].salario);

    emple[i].isEmpty =1;
    }
    for (int i=0;i<2;i++){
        printf("\n\nlegajo: %d",emple[i].legajo);
        printf("\nnombre: %s",emple[i].nombre);
        printf("\nsalario: %f",emple[i].salario);
    }
}

