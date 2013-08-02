#include<stdio.h>
#include<stdlib.h>


int main(){
    
    int num = 10;
    int * pnum = &num;

    printf("%p %p %p\n%d %d\n" ,  &pnum ,  pnum , &num , *pnum , num );

    system("PAUSE");


}
