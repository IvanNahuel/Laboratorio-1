#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

Empleado* em_calcularSueldo(Empleado*this);

Empleado* employee_new();

employee_newParametros(char*idAux,char* nombreAux,char* horasAux);

int employee_setId(Empleado* this,int id);

int employee_setNombre(Empleado* this,char* nombre);

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);








#endif // EMPLEADO_H_INCLUDED
