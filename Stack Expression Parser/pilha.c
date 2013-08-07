#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int elem[100];
	int topo;
	int max;
} Pilha;

/* insere um elemento no topo da pilha */
void push(Pilha *p, int val)
{	
	int t = p->topo;
	printf("\n%p %d %d", p, t ,val);
  	p->elem[t] = val;
  	p->topo+=1;
}

/* recupera um elemento do topo da pilha */
int pop(Pilha *p)
{
  p->topo--;
  return p->elem[p->topo];
}

/* recupera um elemento do topo da pilha sem remove-lo*/
int elemTopo(Pilha *p)
{
  return p->elem[p->topo-1];
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
		printf("%d ",p->elem[i]);	
	}
}

void initPilha(Pilha *p, int tamanho){
	printf("\nbegin init pilha %p",p);	
	p = (Pilha *) malloc(sizeof(Pilha));
	printf("\nallocated pilha %p",p);	
	//p->elem = (int *)malloc(tamanho * sizeof(int));
	p->topo = 0;
	p->max = tamanho;
	int i = 0;
	for(;i<tamanho;i++) p->elem[i] = 0;
	printPilha(p);
	printf("\nfinish init pilha, <Pilha:%p topo:%d , max:%d> ", p , p->topo , p->max);
}
