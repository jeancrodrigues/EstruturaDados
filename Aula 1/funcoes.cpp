#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float media(float num1, float num2){
    return ( num1 + num2 ) / 2 ;    
}

int par_ou_impar(int num)
{
    return num % 2 == 0;
}

int main(int argc,char const * argv[] )
{             

//    int x; 
    
//    printf("digite um numero: ");
//    scanf("%d",&x);
    printf("%x %s\n",argv[0]);        
    
    if(par_ou_impar( atoi( argv[0] ) )){
        printf("\nEsse numero eh par");        
    }else{
        printf("\nEsse numero eh impar");
    }     
    
    getch();
}

