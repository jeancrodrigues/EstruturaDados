#define T25 25000
#define T50 50000
#define T75 75000
#define T100 100000
#define T125 125000
#define T150 150000
#define T175 175000
#define T200 200000

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "metodosOrdenacao.cpp"

int testaInsertion(int tam){
	
	int v[tam], n=tam;    
    clock_t t;
        
    geraVetor(v,n);    
    t = clock();    
	insertionSort(v,n);    
	t = clock() - t;
    return t;	
}

int testaSelection(int tam){
	
	int v[tam], n=tam;    
    clock_t t;
        
    geraVetor(v,n);    
    t = clock();    
	selectionSort(v,n);    
	t = clock() - t;
    return t;	
}

int testaBubble(int tam){
	
	int v[tam], n=tam;    
    clock_t t;
        
    geraVetor(v,n);    
    t = clock();    
	bubbleSort(v,n);    
	t = clock() - t;
    return t;	
}

int testaQuick(int tam){
	
	int v[tam], n=tam;    
    clock_t t;
        
    geraVetor(v,n);    
    t = clock();    
	quickSort(vet, 0, n -1);
	t = clock() - t;
    return t;	
}

int testaMerge(int tam){
	
	int v[tam], n=tam;    
    clock_t t;
        
    geraVetor(v,n);    
    t = clock();    
	mergeSort( vet, n);
	t = clock() - t;
    return t;	
}


int main(){
	
	int i = T25;
	
	printf("Bubble %.8f %d\n" , testaBubble(i),i);
    printf("Insertion %.8f %d\n" , testaInsertion(i),i);
    printf("Selection %.8f %d\n" , testaSelection(i),i);
    printf("Merge %.8f %d\n" , testaMerge(i),i);
    printf("Quick %.8f %d\n" , testaQuick(i),i);
	
}
