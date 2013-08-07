#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *elem;
	int topo;
	int max;
} Pilha;

/* insere um elemento no topo da pilha */
void push(Pilha *p, int val)
{	
	int * el = p->elem;
	el[p->topo] = val;
  	p->topo+=1;
}

/* recupera um elemento do topo da pilha */
int pop(Pilha *p)
{
  p->topo--;
  return *(p->elem + p->topo);
}

/* recupera um elemento do topo da pilha sem remove-lo*/
int elemTopo(Pilha *p)
{
  return *( p->elem + p->topo-1);
}

/* verifica se a pilha esta vazia */
int PilhaVazia(Pilha *p)
{
  return p->topo==0;
}

/* verifica se a pilha esta cheia */
int PilhaCheia(Pilha *p)
{
  return p->topo==p->max;
}

void destroyPilha(Pilha *p){
	free(p->elem);
	free(p);
}

int count(Pilha *p){
	return p->topo;
}

void printPilha(Pilha *p){
	printf("\n");
	int i;
	for(i = 0; i < p->topo ; i++){
		printf("%d ", *(p->elem + i));	
	}
}

void initPilha(Pilha *p, int tamanho){
	p = (Pilha *) malloc(sizeof(Pilha));		
	p->elem = (int *)calloc(tamanho , sizeof(int));	
	p->topo = 0;
	p->max = tamanho;
}
