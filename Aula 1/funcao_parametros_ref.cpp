#include <stdio.h>
#include <conio.h>


int soma_produto(int num1,int num2,int * soma,int * prod)
{
    *soma = num1 + num2;    
    *prod = num1 * num2;
}

int soma_produto2(int num1,int num2,int * soma,int * prod)
{
    *soma = num1 * num2;    
    *prod = num1 + num2;
}

int main()
{
    int s , p , *x;
    soma_produto(2,3,&s,&p);
    printf("Soma : %d\nProduto : %d\n\n",s,p );
    
    x = (int *)soma_produto ;

    for(int i =0;i<28;i++){
        printf("%x\n",x[i]);
    }

    printf("Soma : %d\nProduto : %d",s,p );

    printf("\n\n%p",soma_produto);
    printf("\n\n%p",x);
    
    
    
    printf("\n\n%p",soma_produto2);    
    getch();
}
