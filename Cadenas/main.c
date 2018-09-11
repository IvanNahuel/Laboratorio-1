#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
//strcpy
//strcpy (variable,"juan pablo");
//a la variable llamada "variable" se le asigna "juan pablo"

//fflush(stdin);    LIMPIA EL BUFFER
char nombre[20];
int cant=0;

printf("Ingrese el nombre: ");
fflush(stdin);
//gets(nombre);
fgets(nombre,20,stdin);      //stdin -->estandar de entrada
printf("%s",nombre);

cant = strlen(nombre);
cant--;
printf("%d",cant);


}




