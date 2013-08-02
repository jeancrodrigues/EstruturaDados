#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    if( argc > 2 )
    {       
        printf("Nome do programa : %s\n",*argv);
        
        int i = atoi(*(argv + 1));
        int j = atoi(*(argv + 2));

        
        printf("A soma de %d com %d eh %d\n",  i , j , i + j );

    }else{
         printf("Digite dois parametros na linha de comando\n");
    }

}
