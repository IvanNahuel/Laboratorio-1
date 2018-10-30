#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Persona
{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
};
    typedef struct S_Persona Persona;
    int parseData(char* fileName,Persona* arrayPersonas, int len);

int main(void){
    //Persona*PersonasArray[20];      //array de punteros a estructuras

    Persona personas[8];
    int r,i;
    r = parseData("datos.csv",personas,8);

    for(i=0; i<r; i++){
        printf("id:%d nombre:%s apellido:%s edad:%d\n", personas[i].id,
        personas[i].nombre,
        personas[i].apellido,
        personas[i].edad);

        //aca tendria que pedir memoria dinamicamente
        //y asi el array se ira agrandando

        //exit(EXIT_SUCCESS);
    }
}

int parseData(char* fileName,Persona* arrayPersonas, int len){
    Persona*PersonasArray[20];      //array de punteros a estructuras

    int flag=0;
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen(fileName,"r");

    if(pFile == NULL){
    return -1;
    }

    do{
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    if(r==4 && flag==1)
    {
    arrayPersonas[i].id = atoi(var1);
    strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
    strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
    arrayPersonas[i].edad = atoi(var4);
    i++;


    PersonasArray[i] = NewPersona(arrayPersonas[i].id,arrayPersonas[i].nombre,arrayPersonas[i].apellido,arrayPersonas[i].edad);
    //PersonasArray[i] = NewPersona(1,"Jose","gomez",12);



    //CREAR UN ARRAY DE PUNTEROS Y GUARDARLOS EN DICHO ARRAY
    //DESPUES LLAMAR A LA FUNCION "NEWPERSONA"

    //ACA TENGO QUE HACER UN SET ID, SET NOMBRE, SET APELLIDO, SET EDAD
    //
    //LEER EL REGISTRO
    //NEW PERSONA   (PEDIR MEMORIA)
    //SETEAR LOS CAMPOS
    //SET ID, SET APELLIDO, SET NOMBRE

    }
    else if (r!=4&&flag==1){   //si la lectura en R es distinto de 4, y flag es 1, o flag es 0
        break;
    }

    flag=1;

    }while(!feof(pFile) && i<len);
    fclose(pFile);
    return i;
}

Persona*NewPersona(int id,char*nombre,char*apellido,int edad){
    Persona*this = malloc(sizeof(Persona));
    if (this!=NULL){
    //set de los 4 datos
    person_setAge(this,edad);   //los datos de edad ya estan pasados por parametro
    SetName(this,nombre);       //los datos nombre los seteo
    SetSurname(this,apellido);  //seteo los datos de apellido
    SetId(this,id);             //seteo los id

    return this;
    }
}

void person_setAge(Persona* this, int age){
    if(age > 0){
        this->edad = age;        //coloca la edad valida
    }
}
void SetName(Persona*this,char*nombre){
    if (this!=NULL){                    //si el puntero a persona es distinto a nulo
        strcpy(this->nombre, nombre);   //en la posicion pasada por parametro copiame
    }
}
void SetSurname(Persona*this,char*Surname){
    if (this!=NULL){                    //si el puntero a persona es distinto a nulo
        strcpy(this->apellido, Surname);   //en la posicion pasada por parametro copiame
    }
}
void SetId(Persona* this, int id){
    if(id > 0){
        this->id = id;        //coloca la edad valida
    }
}












