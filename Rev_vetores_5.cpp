#include<stdio.h>
#include<string.h>

#define N 100

int main(){			

	char palavra[N];	
	int tam = 0 , i;		

	printf("\nDigite uma palavra: ");
	gets(palavra);
			
//	while(palavra[tam]!='\0')tam++;

	tam = strlen(palavra);
	
	for(i=tam-1;i>=0;i--)
		printf("%c",palavra[i]);
}
