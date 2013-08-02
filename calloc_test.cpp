#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int * vet;
	
	vet = (int *)calloc(sizeof(int),10);
	
	printf("%p %p %p\n",vet,&vet[0],&vet[9]);
	
	for(int i=0;i<10;i++){		
		printf("%d ",vet[i]);		
	}
	
	free(vet);
	printf("\n");
	
	for(int i=0;i<10000;i++){		
		
		printf("%d",i*23%13);		
		if(i%2==0){
			for(int j=0;j<i%13;j++){
				printf(" ");
			}
		}else{
			for(int j=0;j<i%7;j++){
				printf(" ");
			}
		}
		
	}
	
	printf("\n%p %p %p",vet,&vet[0],&vet[99]);
	
}

