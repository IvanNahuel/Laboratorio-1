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


//RECUPERATORIO SEGUNDO PARCIAL


struct S_Vendedor
{
  int id;
  char nombre[128];
  int nivel;
  int cantidadProductos;
  float montoVendido;
  float comision;
};

typedef struct S_Vendedor eVendedor;
employee_newParametrosVendedor(char*idAux,char* nombreAux,char* Auxnivel,char*AuxcantidadProductos,char*AuxmontoVendido);

eVendedor* vendedor_new();

int vendedor_setId(eVendedor* this,int id);

int vendedor_setNombre(eVendedor* this,char* nombre);

int vendedor_setNivel(eVendedor* this,int nivel);

int vendedor_setCantProductos(eVendedor* this,int cant);

int vendedor_setMonto(eVendedor* this,int monto);










#endif // EMPLEADO_H_INCLUDED
