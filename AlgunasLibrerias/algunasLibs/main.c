#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char test[50];

    ingresarCadenas(&test);

    printf("%s",test);

    /*
    char buffer[64];
    int cantidad;
    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);
    cantidad = strlen(buffer);
    buffer[cantidad-1] = '\0';
    printf("%s", buffer);*/

}

void ingresarCadenas(char*retorno){
    char buffer[64];
    int cantidad;
    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);
    cantidad = strlen(buffer);
    buffer[cantidad-1] = '\0';
    printf("%s\n",buffer);
    *retorno = buffer;
    //printf("%s", buffer);
}
