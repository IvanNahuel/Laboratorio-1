#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

int initEmployees(eEmployee* list,int len){
    int retorno=-1;
    if (list!=NULL && len>0){
        for (int i=0;i<cant;i++){
            list[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
/**de la lista existente "list" añade los siguientes parametros en la primer posicion libre del array
*
*
*
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){




 return -1;
}




