#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{

    int respuesta;
    Person* personArray[50];        //array de person de 50 punteros
    int i;
    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);
    }
    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);      //set, Ajustar
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }


    //alta, listar
    do{
        menu();
        scanf("%d",&respuesta);

        switch(respuesta){
    case 1:
        for (i=0;i<3;i++){
            NewName(personArray[i]);
        }

        break;
    case 2:
        for (i=0;i<3;i++){
            printf("\nAge: %s",personGetName(personArray[i]));
        }
        break;
        }
    }while(respuesta==1||respuesta==2);

    scanf(" ");
    return 0;
}
void menu(){

printf("\n1-Alta");
printf("\n2-Listado");
printf("\nIngrese respuesta: ");

}
void NewName(Person*this){
    char nombre[20];
    if (this!=NULL){                    //si el puntero a persona es distinto a nulo
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nombre);
        strcpy(this->nombre, nombre);   //en la posicion pasada por parametro copiame
                                        //lo que haya en nombre
    }
}

int personGetName(Person*this){         //en la posicion actual pasada por parametro
    return this->nombre;                //obteneme el nombre
}





