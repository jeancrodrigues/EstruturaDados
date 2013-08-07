#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "pilha.h"

#define MAX 100


int evalOper(Pilha *p,char oper){
	return 0;		
}

int evalNumeros(Pilha *p){
	
	printPilha(p);
	
	int i = count(p) - 1;
	int res = 0;
	
	while(!PilhaVazia(p)){
		res += pop(p) ^ i;
		i++;
	}	
	return res;			
}

bool testaUltimo(Pilha *p,char c){
	if(!PilhaVazia(p) && elemTopo(p)==c){
		pop(p);
		return 1;		
	}		
	return 0;
}
/*
int validaExpressao( char * exp ){
	int i = 0;
	bool valida = 1;
	
	Pilha numchars;	
	Pilha numeros;
	Pilha ops;
	
	initPilha(numchars,MAX);
	initPilha(numeros,MAX);
	initPilha(ops,MAX);	
	
	while( exp[i] != '\0' && valida){		
		
		char c = exp[i]; 
		i++;
				
		if( c-48 >= 0 && c-48 <= 9 ){					
			push(numeros,c-48);							
		}else{//na tabela ascii o caracter '0' vale 48
			
			if(!PilhaVazia(numeros)){
				push(ops , evalNumeros(numeros));
			}
						
			switch(c){ //nossa expressao só aceita numeros , espacos e os caracteres '({[]})'
				
				case('('): evalOper( pilha,c );
				break;
				case('['): evalOper( pilha,c );
				break;				
				case('{'): evalOper( pilha,c );
				break;				
				case(')'): valida = testaUltimo(pilha,'(');
				break;
				case(']'): valida = testaUltimo(pilha,'[');
				break;
				case('}'): valida = testaUltimo(pilha,'{');
				break;
				
				case(' '): ;
				break;
				case('+'): push(oper,'+');
				break;
				case('-'): push(oper,'-');
				break;
				case('*'): push(oper,'*');
				break;
				case('/'): push(oper,'/');
				break;
				case('%'): push(oper,'%');
				break;
				case('^'): push(oper,'^');
				break;
				
				default: valida = 0;					
			}
		}		
	}				
	return PilhaVazia(pilha) && valida;
}
*/

int main()
{	
	char num[] = "1234";
	Pilha *n;
		
	initPilha(n,5);
	
	for(int i = 0; i < 4;i++){
		push(n,num[i]-48);
	}
	
	printf("%s %d",num,evalNumeros(n));
	
	/*char exp[100]; //= "( (1+1) + (3*6) * 9 ) + ( { 3 ^ 2 } ) + { [34 % 5] + 2 }";
	
	do{			
	    printf("Digite a expressao a ser validada\n");
		gets(exp);	   
	
		if( validaExpressao(exp) ){
			printf("\nExpressao valida");
		}else{
			printf("\nExpressao invalida");
		}
	
		printf("\n\nDigite 0 para sair ou outra tecla para continuar \n");		
	}while(getch()!='0');
	      	
   	return 0;*/
}

