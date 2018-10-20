#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cad[]="hoy es sabado";
    mostrarCadena(cad);


    return 0;
}
void mostrarCadena(char* punteroCadena){
    while(*punteroCadena != '\0'){
        printf("%c",*punteroCadena);
        punteroCadena++;
    }
}
