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
    struct eEmpleado emple;             //encapsulado datos
    printf("Ingrese numero de legajo: ");
    scanf("%d",&emple.legajo);

    printf("\ningrese nombre del empledo: ");
    fflush(stdin);
    gets(emple.nombre);

    printf("\ningrese salario: ");
    scanf("%f",&emple.salario);

    emple.isEmpty =1;

    printf("\n\nlegajo: %d",emple.legajo);
    printf("\nnombre: %s",emple.nombre);
    printf("\nsalario: %f",emple.salario);



}
