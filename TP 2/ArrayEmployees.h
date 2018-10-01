#ifndef ArrayEmployees_H_INCLUDED
#define ArrayEmployees_H_INCLUDED
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

int initEmployees(eEmployee* list,int len);




#endif
