#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b, *c, x, vec[5], *ptr, i;

    a=15;
    x=a; //copia    //x va a valer 15
    b = &a;
    c = b;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);
    //15  15  15  15

    *b = 13;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);
    //13  13  13  15


    ptr = vec;

    for(i=0; i<5; i++){
        *(ptr+i) = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d\n", *(ptr+i));
    }


    return 0;
}
