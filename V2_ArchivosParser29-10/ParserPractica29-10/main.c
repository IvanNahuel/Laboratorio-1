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
    int parseData(char* fileName,Persona* arrayPersonas, int len,Persona** lista );

int main(void){

    Persona personas[8];

    int size = 10;      //**
    int index=0;        //**
    Persona** lista = (Persona**)malloc(sizeof(Persona*)*size);      //**

    int r,i;
    r = parseData("datos.csv",personas,8,&lista);

    int j;
    for (j=0;j<10;j++){
        printf("\nEl nombre: %s", (*lista+j)->nombre);
    }
}

int parseData(char* fileName,Persona* arrayPersonas, int len,Persona** lista ){
    int flag=0;
    FILE *pFile;
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen(fileName,"r");

    int size = 10;      //**
    int index=0;        //**
    //Persona** lista = (Persona**)malloc(sizeof(Persona*)*size);      //**

    if(pFile == NULL){
    return -1;
    }

    do{

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    Persona persona;                    //**
    strcpy(persona.apellido,var3);      //**
    strcpy(persona.nombre,var2);        //**
    persona.id = atoi(var1);            //**
    persona.edad = atoi(var4);          //**

    //printf("\nEl nombre: %s",persona.nombre);       //**

    lista[index] = &persona;                 //**
    index++;                                //**

    if (index>=size){                       //**
        size+=10;                           //**
        lista = realloc(lista,sizeof(Persona)*size);    //**
    }

    if(r==4 && flag==1){
    Initialize(&arrayPersonas[i],atoi(var4),var3,var2 ,atoi(var1));
    i++;
    }
    else if (r!=4&&flag==1){   //si la lectura en R es distinto de 4, y flag es 1, o flag es 0
        break;
    }
    flag=1;

    }while(!feof(pFile)/* && i<len*/);
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
void Initialize(Persona*this,int edad,char*apellido,char*nombre,int id){
    person_setAge(this,edad);   //los datos de edad ya estan pasados por parametro
    SetName(this,nombre);       //los datos nombre los seteo
    SetSurname(this,apellido);  //seteo los datos de apellido
    SetId(this,id);
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
/*
char*GetNombre(Persona*this){
    return this->nombre;
}
char*GetApellido(Persona*this){
    return this->apellido;
}*/

int GetId(Persona*this){
    return this->id;
}
int GetAge(Persona*this){
    return this->edad;
}














