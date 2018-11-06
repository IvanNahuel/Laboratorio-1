#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int employee_setId(Employee* this,int id){
    int retorno=-1;
    if (this!=NULL){
        if(id > 0){
            this->id = id;
            retorno=0;
        }
    }
    return retorno;
}
int employee_getId(Employee* this,int* id){
    if (this!=NULL){
        return this->id;
    }
}
int employee_setNombre(Employee* this,char* nombre){
    int retorno=-1;
    if (this!=NULL){                    //si el puntero a persona es distinto a nulo
        strcpy(this->nombre, nombre);   //en la posicion pasada por parametro copiame
        retorno =0;
    }
    return retorno;
}
char* employee_getNombre(Employee* this,char* nombre){
    if (this!=NULL){
        return this->nombre;
    }
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno=-1;
    if (this!=NULL){
        if(horasTrabajadas > 0){
            this->horasTrabajadas = horasTrabajadas;
            retorno=0;
        }
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    if (this!=NULL){
        return this->horasTrabajadas;
    }
}
int employee_setSueldo(Employee* this,int sueldo){
    int retorno=-1;
    if (this!=NULL){
        if(sueldo > 0){
            this->sueldo = sueldo;
            retorno=0;
        }
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
    if (this!=NULL){
        return this->sueldo;
    }
}
