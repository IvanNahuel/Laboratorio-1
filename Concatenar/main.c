#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[50];
    char apenom[50];
    char apellido[50];
    printf("ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    printf("ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("\n");
    strcpy(apenom,apellido);
    strcat(apenom," ");
    strcat(apenom,nombre);
    printf("%s",apenom);
/*
    for (int i=0; strlen() ){
        if (nombre[i]==" "&&nombre[i+1]!='\0'){ //si nombre es igual a espacio vacia y la sig posicion
                                                //no esta en espacio en blanco
            nombre[i+1]=topper(nombre[i+1);



tolower()     minusculas char/    strlwr()      mayusculas string
toupper()     mayusculas char/    strupr()      mayusculas string


        }
    }
    */


}
