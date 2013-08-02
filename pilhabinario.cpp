#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAX 100

int s[MAX];
int topo=0; /* topo da pilha */

/* insere um elemento no topo da pilha */
void push(int *pilha, int nro)
{
  pilha[topo]=nro;
  topo++;
}

/* recupera um elemento do topo da pilha */
int pop(int *pilha)
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

int main()
{  
		
	int nro = 0, aux = 0, ops = 0;
	
	do{
		topo=0;
		ops=0;
		
		printf("\nDigite um numero qualquer: ");
		scanf("%d",&nro);
		
		aux = nro;
		do{
			push(s,(int)aux%2);
			aux /= 2;		
			ops++;
		}while(aux!=0);	
		
		printf("\nNumero %d em binario: ", nro);
		for(int i=0;i<ops;i++){
			printf("%c",pop(s)+48);
		}		
		printf("\n");				
		
		printf("Digite s para sair ou outra tecla para continuar: ");
		
	}while(getch()!='s');
	
}
