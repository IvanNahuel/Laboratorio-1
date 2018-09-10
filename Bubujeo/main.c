#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int pts[5]={1,0,3,3,1},auxpts;
    int dg[5]={8,10,5,3,4},auxdg;

    /*
    for (int i=0;i<5-1;i++){
        for (int j=i+1;j<5;j++){
            if (pts[i]<pts[j]){
                auxpts = pts[i];
                pts[i] = pts[j];
                pts[j] = auxpts;

                auxdg = dg[i];
                dg[i] = dg[j];
                dg[j] =auxdg;

            } else if (pts[i]==pts[j]){     //si el numero actual es igual al siguiente
                if (dg[i]<dg[j]){
                    auxdg = dg[i];
                    dg[i] = dg[j];
                    dg[j] =auxdg;
                }
            }
        }
    }*/
    ChangeState(pts,dg,5);

    for (int i=0;i<CANT;i++){
        printf("\n");
        printf("%d",pts[i]);
        printf("  ");
        printf("%d",dg[i]);
    }

}
void ChangeState(int*valA[],int *valB[],int cant){
    int auxpts;
    int auxdg;

    for (int i=0;i<cant-1;i++){
        for (int j=i+1;j<cant;j++){
            if (valA[i]<valA[j]){
                auxpts = valA[i];
                valA[i] = valA[j];
                valA[j] = auxpts;

                auxdg = valB[i];
                valB[i] = valB[j];
                valB[j] =auxdg;

            } else if (valA[i]==valA[j]){     //si el numero actual es igual al siguiente
                if (valB[i]<valB[j]){
                    auxdg = valB[i];
                    valB[i] = valB[j];
                    valB[j] =auxdg;
                }
            }
        }
    }
}
