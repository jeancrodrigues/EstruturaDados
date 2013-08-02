#include<stdio.h>
#include<stdlib.h>

/**
	Busca binária recursiva
	
	Alunos
		Jean Carlos Rodrigues		
		Elias Scheifer
**/


int bin_search_rec(int * vet,int begin, int end, int search ){
	
	// se encontrar o elemento no vetor retorna a posicao 
	// senao retorna -1
		
	int middle = (begin + end)/2;			
	
	if(begin>end)
		return -1;
	
	if(vet[middle]==search)
		return middle;
		
	if(vet[middle]>search){
		return bin_search_rec(vet,begin,middle-1,search);
	}else{
		return bin_search_rec(vet,middle+1,end,search);
	}		
}


int main(){
	
	int vet[] = {1,2,7,12,56,123,345,999};
	int n=8,s=12;
	
	int pos = bin_search_rec(vet,0,n-1,s) ;
	for(int i=0;i<n;i++){
		printf("%d ",vet[i]);
		
	}
	printf("\n\nO numero %d esta na %d posicao do vetor.\n",s,pos+1)	;
	
	system("pause");
	
}

