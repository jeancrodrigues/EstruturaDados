#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "pilha.h"

#define MAX 100

int validaExpressao( char * exp , int * pos , char compare );

void printaexp(char * exp , int pos){
	printf("\n%s\n",exp);
	int i = 0;
	while(i < pos){
		printf(" ");
		i++;
	}
	printf("^\n");
		
}

int evalNumeros(Pilha *p){		
	int i = 1;
	int res = 0;		
	while(!PilhaVazia(p)){
		res += pop(p) * i;
		i*=10;
	}	
	
	printf("\nValidou o numero %d",res);
	
	return res;		
}

int main()
{	
	// char exp[] = "{ { ( 1 + 1 + 7 ) * ( 5 * 5 - 13 ) } * 3 } - ( 34 - 89 - 78 + ( 45 *  3 ) )"; 
	char exp[200] = "( 1 + 2 - ( 3 * 3 * 3 ) ) + ( 4 * 4 ) % 5";
		
	do{
		 printf("\ndigite a expressao : ");
		 gets(exp);
		int pos = 0;
		
		int res = validaExpressao(exp , &pos , ' ' );
		
		if(pos == -1){
			printf("\nExpressao invalida.");
		}else{
			printf("\nResultado = %d",res);
		}
		
	}while(1);
	
   	return 0;
}


int validaExpressao( char * exp , int * pos , char compare ){
	
	//printf("\nEntrou em validaexpressao");
	
	int cont = 0;
	
	if( *pos < 0 ) return 0;
	
	bool valida = 1;
	
	int tamanhoExp = strlen(exp);
	
	Pilha * numchars = initPilha(tamanhoExp);
	Pilha * numeros = initPilha(tamanhoExp);
	// push(numeros,0);
	
	Pilha * ops = initPilha(tamanhoExp);
	
	while( *pos >=0 && *pos <= tamanhoExp && valida){				
		*pos += cont;
		cont = 0;		
		char c = exp[*pos]; 				
		
	//	printf("\nPos %d \"%c\" topo %d",*pos,c,elemTopo(numeros));
		
		*pos += 1;				
				
		if( c-48 >= 0 && c-48 <= 9 ){					
			push(numchars,c-48);							
		}else{//na tabela ascii o caracter '0' vale 48
			
			if(!PilhaVazia(numchars)){
				push( numeros , evalNumeros(numchars));
			}
			
			if(count(ops)>0 && count(numeros) > 1){
				int num1 , num2;
				num2 = pop(numeros);
				num1 = pop(numeros);
								
				char oper = pop(ops);
				switch(oper){						
					case('+'): push( numeros , num1 + num2 );
					break;
					case('-'): push( numeros , num1 - num2 );
					break;
					case('*'): push( numeros , num1 * num2 );
					break;
					case('/'): {
						if(num2 == 0){
							*pos = -1;
						}else{
							push( numeros , num1 / num2 );
						}						
					}
					break;						
					case('^'): push( numeros , pow(num1, num2 ) );
					break;
					case('%'): {
						if(num2 == 0){
							*pos = -1;
						}else{
							push( numeros , num1 % num2 );	
						}
					}
					break;
				}					
				printf("\nResolveu a expressao %d %c %d = %d",num1,oper,num2, elemTopo( numeros ));					
			}
									
			switch(c){ //nossa expressao só aceita numeros , espacos e os caracteres '({[]})'
				
				case('('): {
					printaexp( exp , *pos - 1 );
					push( numeros , validaExpressao( &exp[*pos] , &cont , ')' ));
				}
				break;
				case('['): {
					printaexp( exp , *pos - 1 );
					push( numeros , validaExpressao( &exp[*pos] , &cont , ']'));	
				}
				break;				
				case('{'): {
					
					printaexp( exp , *pos - 1 );
					push( numeros , validaExpressao( &exp[*pos]  , &cont , '}'));
				}
				break;				
				case(')'): {
					printaexp( exp , *pos - 1 );
					if(c==compare){
						valida = 0;
					}else{
						*pos = -1;
					}
				}
				break;
				case(']'): {
					printaexp( exp , *pos - 1 );
					if(c==compare){
						valida = 0;
					}else{
						*pos = -1;
					}
				}
				break;
				case('}'): {
					printaexp( exp , *pos - 1 );
					if(c==compare){
						valida = 0;
					}else{
						*pos = -1;
					}
				}
				break;
								
				case('+'): {
					printf("\nValidou o operador %c" , c);
					push(ops,'+');
				}
				break;
				case('-'): {
					printf("\nValidou o operador %c" , c);
					push(ops,'-');
				}
				break;
				case('*'):{
					printf("\nValidou o operador %c" , c);
					push(ops,'*');
				}
				break;
				case('/'): {
					printf("\nValidou o operador %c" , c);
					push(ops,'/');
				}
				break;
				case('%'):{
					printf("\nValidou o operador %c" , c);
					push(ops,'%');
				}
				break;
				case('^'):{
					printf("\nValidou o operador %c" , c);
					push(ops,'^');
				}
				break;
				
				case(' '): 
				break;
				case('\0'): 
				break;
				
				/*
				case('%'): push(ops,'%');
				break;
				case('^'): push(ops,'^');
				break;*/
				
				default: {
					printf("\ncaracter invalido %c pos %d tamanho exp %d",c , *pos, tamanhoExp);
					*pos = -1;
				}					
			}
		}		
	}		
	
	// printf("\nSaiu de validaexpressao cont %d  pos %d",*pos,cont);
	if( *pos > tamanhoExp && !PilhaVazia(ops) ){
		printPilha(ops);
		*pos = -1;		
	}else if(cont > 0 && *pos > -1 ){
		*pos = *pos + cont;
	}	
	
	int resultado = pop(numeros);
	
	destroyPilha(numchars);
	destroyPilha(numeros);
	destroyPilha(ops);
	
	return resultado;
}

