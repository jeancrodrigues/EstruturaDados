#include<stdio.h>
#define N 3

int matriz[N][N];

void le_matriz(){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("\nDigite o elemento da posicao %d x %d : " , i+1, j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
}

int calcula_soma(){
	
	int i,j,soma=0;	
	printf("\nMatriz %d x %d\n\n",N,N);
	
	for(i=0;i<N;i++){
		soma+=matriz[i][i];				
	}
	return soma;
}

int main(){	
		
	le_matriz();

	
	printf("Soma dos elementos da diagonal : %d " , calcula_soma());
	
}
