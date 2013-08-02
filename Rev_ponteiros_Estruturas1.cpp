/*

Programa ponteiros aula 2

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ra[8];
	char nome[31];	
}Aluno;


Aluno aluno;

int main(){
	
	aluno = ("1312588","Jean Carlos Rodrigues");
	
	Aluno * pAluno = &aluno;
	
	char * c = (char *) pAluno;	
	printf("size of int %d\n", sizeof(int) );
	printf("size of char %d\n", sizeof(char) );
	printf("size of float %d\n", sizeof(float) );
	printf("size of aluno %d\n", sizeof(aluno) );
		
	for(int i = 0;i< 40 * sizeof(char);i += sizeof(char)){
		
		printf("%2d %p - %c\n",i,c+i,*(c+i));	
		getc(stdin);
	}
	return 0;
}
