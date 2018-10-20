#include <stdio.h>
#include <stdlib.h>

typedef struct{
int edad;
char nombre[31];

}ePersona;



int main()
{
//una structrura es un tipo de datos, por lo cual existen punteros a structuras

ePersona per,*p;
 per.edad = 10;
 strcpy(per.nombre,"Gabriel");

 p=&per;    //el puntero a estructura ahora apunta a la estructura "PER"
 printf("edad: %d nombre: %s",per.edad,per.nombre);

 p->edad=15;
 strcpy(p->nombre,"Justo");

 printf("\n\n");
 printf("edad: %d nombre: %s",per.edad,per.nombre);

 printf("\n\n");
 (*p).edad = 20;
 strcpy((*p).nombre ,"Bustamante");
 printf("edad: %d nombre: %s",per.edad,per.nombre);




}
