#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int *n;
}N;

void um(N *n){
	n->n = (int *)malloc(sizeof(int));
	int * num = n->n;	
	*num = 1;
}

int main(){	
	
	N *n = (N *)malloc(sizeof(N));	
	um(n);
	
	int * i = n->n;
	
	printf("%d ", *i);	//certo
	printf("%d", *(n->n) );	// bizarro mas funciona
	printf("%d", n->*n );	// erro
	
	return 0;	
}

