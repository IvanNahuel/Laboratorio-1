#include <stdio.h>
#include <stdlib.h>
typedef struct{
int edad;
char nombre[31];

}ePersona;

int main()
{
ePersona per[3],*p;

p=per;

//printf("Edad: %d y su nombre es: %s",per[0].edad,per[0].nombre);
int i;

per[0].edad =10;
strcpy (per[0].nombre, "Juancito");

per[1].edad =11;
strcpy (per[1].nombre, "Pedrito");

per[2].edad =8;
strcpy (per[2].nombre, "Ramoncito");

/*
for (i=0;i<3;i++){
    printf("\nNombre: ");
    fflush(stdin);
    scanf("%s",(p+i)->nombre);

    printf("\nEdad: ");
    scanf("%d",&(p+i)->edad);
    }
    */
    //operador flecha
  /*
for (i=0;i<3;i++){
printf("\nsu nombre es: %s y su edad es:%d", (p+i)->nombre, (p+i)->edad );
    }*/

    //notacion de punteros en vectores de structuras
    for (i=0;i<3;+i++){
        printf("\nsu nombre es: %s y su edad es:%d",(*(p+i)).nombre, (*(p+i)).edad);
    }

}





