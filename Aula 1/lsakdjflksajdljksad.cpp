#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int compara_string(char * palavra1 , char * palavra2 ){
    int i = 0;

    for(; !( palavra1[i] == '\0' || palavra2[i] == '\0' ); i++ ){                      
        printf("%2d %c %c\n", i, palavra1[i], palavra2[i]);
        if(palavra1[i]!=palavra2[i]) return 0;
    }
    printf("%2d %c %c\n", i, palavra1[i], palavra2[i]);
    if(palavra1[i]==palavra2[i]) return 1;
    return 0;
}

int main()
{
    if(compara_string("elias","elias")){
        printf("\n\nAs palavras sao iguais");
    }else{
        printf("\n\nAs palavras nao sao iguais");
    }

    getch();
}
