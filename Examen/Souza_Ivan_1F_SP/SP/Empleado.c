#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"


Empleado* employee_new()
{
    Empleado* this = malloc(sizeof(Empleado));      //pide espacio de memoria para una structura de tipo empleado
    return this;                                    //lo retorna
}

employee_newParametros(char*idAux,char* nombreAux,char* horasAux)
{
//los setter de los datos idAux, Nombre,
    Empleado*Employ = employee_new();       //pido espacio de memoria para un empleado
    int id;
    int horas;

    id = atoi(idAux);
    horas = atoi(horasAux);

    if (Employ!=NULL)       //si obtuvo espacio de memoria
    {
    employee_setId(Employ,id);
    employee_setNombre(Employ,nombreAux);
    employee_setHorasTrabajadas(Employ,horasAux);
    }
return Employ;
}

//SETS

int employee_setId(Empleado* this,int id)
{
    int retorno = 0;
    static int nextId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            nextId++;
            this->id = nextId;
            retorno = 1;
        }
        else if(id > nextId)
        {
            nextId = id;
            this->id = nextId;
            retorno = 1;
        }
    }
    return retorno;
}

int employee_setNombre(Empleado* this,char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

//GETS

int employee_GetId(Empleado*this,int *id)
{
    int retorno=0;

    if (this!=NULL&&id !=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_getNombre(Empleado* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 1;
    }

    return retorno;
}

//CRITERIO DE SUELDOS

Empleado* em_calcularSueldo(Empleado*this)
{
    if (this!=NULL)
    {
        //176 horas = 180
        //177 a 208 horas = 270
        //209 a 240 horas = 360
        if (this->horasTrabajadas<=176)
        {
        this->sueldo =180;
        } else if (this->horasTrabajadas>=177 && this->horasTrabajadas <=208){
        this->sueldo =270;
        } else if (this->horasTrabajadas>=209 && this->horasTrabajadas <=240){
        this->sueldo =360;
        }
    }
return this;     //retorna la structura ya cargada con el sueldo incluido
}
