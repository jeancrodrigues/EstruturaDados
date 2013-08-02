// 
//
//		Alunos:
//		Jean Carlos Rodrigues
//		Elias Scheifer
//
//

#include<stdio.h>
#include<stdlib.h>

int main(){
		
	int numeros, i, par=0, imp=0;
	int *vet, *pares , *impares;
	
	printf("Digite a quantidade de numeros a serem lidos : ");	
	scanf("%d",&numeros);
	
	vet = (int *)malloc(numeros * sizeof(int));
	
	for(i=0;i<numeros;i++){
		printf("\nEntre com o %do numero : " , i+1);
		scanf("%d",&vet[i]);
		if(vet[i]%2==0){
			par++;		
		}else{
			imp++;
		}
	}
	
	pares=(int *)malloc(par*sizeof(int));
	impares=(int *)malloc(imp*sizeof(int));
	
	par=0;
	imp=0;
	
	for(i=0;i<numeros;i++){			
		if(vet[i]%2==0){
			pares[par]=vet[i];
			par++;		
		}else{
			impares[imp]=vet[i];
			imp++;
		}
	}
	
	printf("\n\nNumeros pares : ");
	for(i=0;i<par;i++){
		printf(" %d",pares[i]);
	}
	
	printf("\n\nNumeros pares : ");
	for(i=0;i<imp;i++){
		printf(" %d",impares[i]);
	}
	
	free(vet);
	free(pares);
	free(impares);
	
}




