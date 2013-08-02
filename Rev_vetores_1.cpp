#include<stdio.h>

#define N 10

int main()
{
	
	int vetor[N],i,soma=0;
	float media=0;
	
	for(i=0;i<N;i++)
	{
		printf("Digite o %d elemento do vetor: " , i + 1 );
		scanf("%d",&vetor[i]);	
		soma += vetor[i];
	}
	
	media = (float) soma / N;	
	
	printf("\n\nMedia %.2f\n\nElementos do vetor maiores que a media",media);
	
	for(i=0;i<N;i++){			
		if(vetor[i]>media)
		{
			printf("\n%d",vetor[i]);
		}
	}
}
