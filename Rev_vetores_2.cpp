#include<stdio.h>

#define TAM 100

int le_vetor(int * vetor){
	
	int tam,i = 0;
		
	printf("\nDigite o numero de elementos do vetor(MAX=%d): ",TAM);
	scanf("%d",&tam);	
	
	for(i = 0;i<tam;i++){		
		printf("\nDigite o %d elemento do vetor: ",i+1);
		scanf("%d",&vetor[i]);		
	}	
	return tam;
	
}

void separa_vetor(int * vetor , int * pares , int * impares,int tamanho){
	
	int j=0,k=0;
		
	for(int i = 0;i<tamanho;i++){
		if(vetor[i]%2==0){
			pares[j]=vetor[i];
			j++;
		}else{
			impares[k]=vetor[i];
			k++;			
		}
	}
	pares[j]=-1;
	impares[k]=-1;
}

void imprime_vetor(int * vetor){
	int i = 0;
	while(vetor[i]!=-1){
		printf("%d ",vetor[i]);
		i++;
	}	
}

int main(){
	
	int vetor[TAM],pares[TAM],impares[TAM],tamanho_vet = 0;
	tamanho_vet = le_vetor(vetor);	
	separa_vetor(vetor,pares,impares,tamanho_vet);
	
	printf("\n\nValores pares\n");
	imprime_vetor(pares);
	
	printf("\n\nValores impares\n");
	imprime_vetor(impares);	
}


















