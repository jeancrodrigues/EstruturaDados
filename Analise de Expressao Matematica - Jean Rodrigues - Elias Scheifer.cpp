#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100

int s[MAX];
int topo=0;

int PilhaCheia();
int PilhaVazia();
int elemTopo(int *pilha);
int pop(int *pilha);
void push(int *pilha, int nro);

bool testaUltimo(int * pilha,char c){
	if(!PilhaVazia() && elemTopo(pilha)==c){
		pop(pilha);
		return 1;		
	}		
	return 0;
}

int validaExpressao( char * exp ){
	int i = 0;
	bool valida = 1;		
	
	while( exp[i] != '\0' && valida){		
		char c = exp[i]; 
		i++;				
		if( c-48 < 0 || c-48 > 9 ){ // caracter diferente de numeros
			
			switch(c){ 
				
				case('('): push(s,c);
				break;
				case('['): push(s,c);
				break;				
				case('{'): push(s,c);
				break;				
				case(')'): valida = testaUltimo(s,'(');
				break;
				case(']'): valida = testaUltimo(s,'[');
				break;
				case('}'): valida = testaUltimo(s,'{');
				break;				
			}
		}		
	}				
	return PilhaVazia() && valida;
}

int main()
{
	
	char exp[100]; //= "( (1+1) + (3*6) * 9 ) + ( { 3 ^ 2 } ) + { [34 % 5] + 2 }";
	
	do{			
	    topo = 0;
	    
		printf("Digite a expressao a ser validada\n");
		gets(exp);	   
	
		if( validaExpressao(exp) ){
			printf("\nExpressao valida");
		}else{
			printf("\nExpressao invalida");
		}
	
		printf("\n\nDigite 0 para sair ou outra tecla para continuar \n");		
	}while(getch()!='0');
	      	
   	return 0;
}


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


