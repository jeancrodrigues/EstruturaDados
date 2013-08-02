// metodos ordenacao

void geraVetor(int * vet,int n)
{    
    for(int i=0;i<n;i++){
        vet[i] = rand() % 999999;
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
 
        for(j=tamanho-1; j>=1; j--)
        {
                for(i=0; i<j; i++)
                {
                        if(vetor[i]>vetor[i+1])
                        {
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


