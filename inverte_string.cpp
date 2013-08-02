#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAX 100

char s[MAX];
int topo=0; /* topo da pilha */

/* insere um elemento no topo da pilha */
void push(char *pilha, int nro)
{
  pilha[topo]=nro;
  topo++;
}

/* recupera um elemento do topo da pilha */
char pop(char *pilha)
{
  topo--;
  return pilha[topo];
}

/* recupera um elemento do topo da pilha sem remove-lo*/
int elemTopo(int *pilha)
{
  return pilha[topo-1];
}

/* verifica se a pilha esta vazia */
int PilhaVazia()
{
  if (topo==0)
     return 1;
  else return 0;
}

/* verifica se a pilha esta cheia */
int PilhaCheia()
{
  if (topo==MAX)
     return 1;
  else return 0;
}


void inverte_string(char * str){
	
	int i=0;
	
	do{
		push(s,str[i]);				
	}while(str[i++]!='\0');
	
	do{
		printf("%c",pop(s));
	}while(!PilhaVazia());
			
}

int main()
{  
		
	char frase[MAX];
	
	topo=0;
	
	printf("Digite uma frase: ");	
	gets(frase);
	
	
	printf("Sua frase invertida eh : ");	
	inverte_string(frase);
	
}
