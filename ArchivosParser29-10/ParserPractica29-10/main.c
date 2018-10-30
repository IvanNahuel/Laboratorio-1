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

    //Persona **P_personas;
    Persona personas[8];
    int r,i;
    r = parseData("datos.csv",personas,8);

    for(i=0; i<r; i++){
        printf("id:%d nombre:%s apellido:%s edad:%d\n", personas[i].id,
        //GetName(personas[i].nombre),
        personas[i].nombre,
        personas[i].apellido,
        personas[i].edad);
        //exit(EXIT_SUCCESS);
    }
}
int parseData(char* fileName,Persona* arrayPersonas, int len){
    //Persona*PersonasArray[20];      //array de punteros a estructuras

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

    if(r==4 && flag==1){
    Initialize(&arrayPersonas[i],atoi(var4), strcpy(arrayPersonas[i].apellido,var3), strcpy(arrayPersonas[i].nombre,var2),atoi(var1));
    i++;
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
    /*
    person_setAge(this,edad);   //los datos de edad ya estan pasados por parametro
    SetName(this,nombre);       //los datos nombre los seteo
    SetSurname(this,apellido);  //seteo los datos de apellido
    SetId(this,id);             //seteo los id
    */
    return this;
    }
}

void Initialize(Persona*this,int edad,char*apellido,char*nombre,int id){
    person_setAge(this,edad);   //los datos de edad ya estan pasados por parametro
    SetName(this,nombre);       //los datos nombre los seteo
    SetSurname(this,apellido);  //seteo los datos de apellido
    SetId(this,id);
}

/*
static void initialize(Person* this, int age, int something)
{
    this->age = age;       //inicializa con numeros
    this->something = something;    //inicializa con numeros
}
*/

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
char*GetName(Persona*this){
    if (this!=NULL){
        return this->nombre;
    }
}*/














