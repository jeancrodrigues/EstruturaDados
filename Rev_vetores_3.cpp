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

void imprime_transposta(){
	
	int i,j;	
	printf("\nMatriz %d x %d\n\n",N,N);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d\t",matriz[j][i]);			
		}
		printf("\n");
	}
}

int calcula_soma(){
	
	int i,j,soma=0;	
	printf("\nMatriz %d x %d\n\n",N,N);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(j==i){
				soma+=matriz[i][j];				
			}
		}
	}
	return soma;
}

int main(){			
	le_matriz();
	imprime_transposta();	
	
}


