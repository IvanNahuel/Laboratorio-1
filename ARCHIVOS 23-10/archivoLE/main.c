#include <stdio.h>

#define ARCH	".\\bin.dat"
#define ESC 27

struct a{
		char nombre[31];
		int edad;
	};
int main (void)
{
    int respuesta=1;
    int numeroModificar;
    char auxiliarNombre[31];

    FILE  *bin;
    struct a pers;
    int cant;

   if ((bin=fopen(ARCH,"rb+"))==NULL){
      if ((bin=fopen(ARCH,"wb+"))==NULL){
         printf("No se pudo abrir el archivo");
         exit(1);
      }
   }


   do{
      printf("\nIngrese el nombre: ");
      gets(pers.nombre);

      printf("Ingrese la edad: ");
      scanf("%d",&pers.edad);

      fflush(stdin);
      fseek(bin , 0L, SEEK_END);
      fwrite(&pers,sizeof(pers),1,bin);

      printf("\nPresione ESC para terminar");
   }while((getche())!=ESC);


   rewind (bin);       //se lleva el indicador de posición al principio para comenzar a leer

   while(!feof(bin)){
      cant = fread(&pers,sizeof(pers),1,bin);

      if(cant!=1){
         if(feof(bin)){
			break;
         }
         else{
			printf("No leyo el ultimo registro");
			break;
         }
      }
      printf("\n%s\t%d",pers.nombre,pers.edad);
   }
    //aca voy a pedir que se ingrese que numero de edad desamos modificiar
    //despues ir recorriendo el archivo y comprara si ese numero es igual al que quiero modificar,
    //si es igual, i

    printf("\nIngrese la edad del campo que desea modificar: ");
    scanf("%d",&numeroModificar);

    rewind (bin);
    while(!feof(bin)){
        cant = fread(&pers,sizeof(pers),1,bin);
        if ( numeroModificar==pers.edad ){
            printf("\nEncontro al numero que desea modificar y es: %s",pers.nombre);
            printf("\nIngrese nuevo nombre: ");
            fflush(stdin);
            gets(auxiliarNombre);

            strcpy (pers.nombre,auxiliarNombre);                //copiamos el nuevo nombre en la estructura
            printf("\nel nuevo nombre es :%s",pers.nombre);     //que esta en memoria

            fseek(bin,(long)(-1)*sizeof(pers),SEEK_CUR);    //posicion actual menos 1

            fwrite(&pers,sizeof(pers),1,bin);           //la estructura actual, escribimela en la posicion
                                                        //actual PERO en el disco, obtenida con fseek
            printf("\nArchivo guardado");
            break;

        }

      if(cant!=1){
         if(feof(bin)){
			break;
         }
         else{
			printf("No leyo el ultimo registro");
			break;
         }
      }

   }

   //MOSTRAME TODO
printf("\n\n");
printf("\t\tLIST");
    rewind (bin);
   while(!feof(bin)){
      cant = fread(&pers,sizeof(pers),1,bin);

      if(cant!=1){
         if(feof(bin)){
			break;
         }
         else{
			printf("No leyo el ultimo registro");
			break;
         }
      }
      printf("\n%s\t%d",pers.nombre,pers.edad);
   }
   fclose(bin);
   getch();

   return 0;
}

void ImprimirMenu(){
printf("\n1-Altas");
printf("\n2-Listado");

}


