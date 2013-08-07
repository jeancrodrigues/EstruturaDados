#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int testaMerge(int tam) ;
int testaQuick(int tam) ;
int testaBubble(int tam) ;
int testaSelection(int tam) ;
int testaInsertion(int tam) ;
int testaShell(int tam) ;

void bubbleSort(int vetor[], int tamanho) ;
void insertionSort(int *vet,int n) ;
void selectionSort(int * vet,int n) ;
void mergeSort(int vec[], int vecSize) ;
void merge(int vec[], int vecSize) ;
void quickSort(int vec[], int left, int right) ;
int partition(int vec[], int left, int right) ;
void swap(int* a, int* b) ;
void shellSort(int vec[], int vecSize) ;

void geraVetor(int * vet,int n) ;

int main(){

	int test , i=0;
	int tamanhos[] = { 444444 } ;
	
	
	
	
	test = testaShell(tamanhos[i]);
	printf("%.3f;", (float)test/CLOCKS_PER_SEC );	

	test = testaMerge(tamanhos[i]);
	printf("%.3f;", (float)test/CLOCKS_PER_SEC );	

	test = testaQuick(tamanhos[i]);
	printf("%.3f;", (float)test/CLOCKS_PER_SEC );	
	
	/*

	FILE * f = fopen("tempos.txt","w");	
	fprintf(f,"Elementos;BubbleSort;InsertionSort;SelectionSort;MergeSort;QuickSort;ShellSort;\n");
	
	int m = 1000;	
	
	int tamanhos[] = {25 * m , 50 * m , 75 * m , 100 * m , 125 * m , 150 * m , 175 * m , 200 * m };
	
	for(int i = 0; i<8 ; i++){	
		
		int test;
		
		printf("\nElementos %d, algoritmos: ",tamanhos[i]);
		
		fprintf(f,"%d;",tamanhos[i]);
		test = testaBubble(tamanhos[i]);
		printf(" BubbleSort,");
		fprintf(f,"%.3f;", (float)test/CLOCKS_PER_SEC );	
		test = testaInsertion(tamanhos[i]);
		printf(" InsertionSort,");
		fprintf(f,"%.3f;", (float)test/CLOCKS_PER_SEC );	
		test = testaSelection(tamanhos[i]);
		printf(" SelectionSort,");
		fprintf(f,"%.3f;", (float)test/CLOCKS_PER_SEC );	
		test = testaMerge(tamanhos[i]);
		printf(" MergeSort,");
		fprintf(f,"%.3f;", (float)test/CLOCKS_PER_SEC );	
		test = testaQuick(tamanhos[i]);
		printf(" QuickSort,");
		fprintf(f,"%.3f;", (float)test/CLOCKS_PER_SEC );	
		test = testaShell(tamanhos[i]);
		printf(" ShellSort,");
		fprintf(f,"%.3f;\n", (float)test/CLOCKS_PER_SEC );	
		
		fflush(f);
	}	
	printf("\nArquivo salvo: tempos.txt");	
	fclose(f);	*/
}

void geraVetor(int * vet,int n)
{    
   for(int i=0;i<n;i++){
       vet[i] = rand() % 99999999;
   }
}

void merge(int vec[], int vecSize) {
 //http://pt.wikipedia.org/wiki/Merge_sort	
  
 int mid;
 int i, j, k;
 int* tmp;

 tmp = (int*) malloc(vecSize * sizeof(int));
 if (tmp == NULL) {
   exit(1);
 }

 mid = vecSize / 2;

 i = 0;
 j = mid;
 k = 0;
 while (i < mid && j < vecSize) {
   if (vec[i] < vec[j]) {
     tmp[k] = vec[i++];
   }
   else {
     tmp[k] = vec[j++];
   }
   ++k;
 }

 if (i == mid) {
   while (j < vecSize) {
     tmp[k++] = vec[j++];
   }
 }
 else {
   while (i < mid) {
     tmp[k++] = vec[i++];

   }
 }

 for (i = 0; i < vecSize; ++i) {
   vec[i] = tmp[i];
 }

 free(tmp);
}

void mergeSort(int vec[], int vecSize) {
 int mid;

 if (vecSize > 1) {
   mid = vecSize / 2;
   mergeSort(vec, mid);
   mergeSort(vec + mid, vecSize - mid);
   merge(vec, vecSize);
 }
}

void bubbleSort(int vetor[], int tamanho)
{
int aux, i, j; 
for(j=tamanho-1; j>=1; j--){
for(i=0; i<j; i++){
if(vetor[i]>vetor[i+1]){
aux=vetor[i];
vetor[i]=vetor[i+1];
vetor[i+1]=aux;
}
}
}
}

void selectionSort(int * vet,int n){
   for(int i=0;i<n;i++){
       int min = i;
       for(int j=i+1;j<n;j++){
           if(vet[j]<vet[min]){
               min = j;    
           }
       }
       int aux = vet[i];
       vet[i] = vet[min];
       vet[min] = aux;        
   }
       
}

void insertionSort(int *vet,int n){
   for(int i=0;i<n;i++){
       int aux = vet[i];
       int j = i;
       while(aux<vet[j-1] && j>0){
           vet[j] = vet[j-1];
           j--;
       }
       vet[j]=aux;
   }
}

void swap(int* a, int* b) {
 int tmp;
 tmp = *a;
 *a = *b;
 *b = tmp;
}

int partition(int vec[], int left, int right) {
 int i, j;

 i = left;
 for (j = left + 1; j <= right; ++j) {
   if (vec[j] < vec[left]) {
     ++i;
     swap(&vec[i], &vec[j]);
   }
 }
 swap(&vec[left], &vec[i]);

 return i;
}

void quickSort(int vec[], int left, int right) {
 int r;

 if (right > left) {
   r = partition(vec, left, right);
   quickSort(vec, left, r - 1);
   quickSort(vec, r + 1, right);
 }
}

void shellSort(int *vet, int size) {
   int i , j , value;
   int gap = 1;
   do {
       gap = 3*gap+1;
   } while(gap < size);
   do {
       gap /= 3;
       for(i = gap; i < size; i++) {
           value = vet[i];
           j = i - gap;
           while (j >= 0 && value < vet[j]) {
               vet [j + gap] = vet[j];
               j -= gap;
           }
           vet [j + gap] = value;
       }
   } while ( gap > 1);
}

int testaInsertion(int tam){

int v[tam], n=tam;    
   clock_t t;
       
   geraVetor(v,n);    
   t = clock();    
insertionSort(v,n);    
t = clock() - t;
   return (int) t;	
}

int testaSelection(int tam){

int v[tam], n=tam;    
   clock_t t;
       
   geraVetor(v,n);    
   t = clock();    
selectionSort(v,n);    
t = clock() - t;
   return (int) t;	
}

int testaBubble(int tam){

int v[tam], n=tam;    
   clock_t t;
       
   geraVetor(v,n);    
   t = clock();    
bubbleSort(v,n);    
t = clock() - t;
   return (int) t;	
}

int testaQuick(int tam){

int v[tam], n=tam;    
   clock_t t;
       
   geraVetor(v,n);
   t = clock();
quickSort(v, 0, n -1);
t = clock() - t;
   return (int) t;
}

int testaMerge(int tam){
int v[tam], n=tam, res;    
   clock_t t;
       
   geraVetor(v,n);    
   t = clock();    
mergeSort( v, n);
res = (int) clock() - t;
   return res;	
}

int testaShell(int tam){
int v[tam], n=tam, res;    
   clock_t t;
       
   geraVetor(v,n);    
   t = clock();    
shellSort(v, n);
res = (int) clock() - t;
   return res;	
}
