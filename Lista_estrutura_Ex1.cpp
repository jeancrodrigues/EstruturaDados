#include<stdio.h>
#include<stdlib.h>

#define NUMPROD 2

typedef struct{
	int codigo;
	char nome[30];
	char fornecedor[30];
	int peso;
	float preco;
	char dataCompra[11];
	int quantidade;
	char telefoneFornecedor[10];		
}Produto;

Produto produtos[NUMPROD];

void le_produtos(){
	
	int i;
	
	for(i=0;i<NUMPROD;i++){
			
		printf("Cadastro de produtos\nDigite os valores.");		
		
		printf("\nCodigo: ");
		scanf("%d%*c",&produtos[i].codigo);
		
		printf("Nome: ");
		gets(produtos[i].nome);
		
		printf("Fornecedor: ");
		gets(produtos[i].fornecedor);		
		
		printf("Peso: ");
		scanf("%d%*c",&produtos[i].peso);
		
		printf("Preco: ");
		scanf("%f%*c",&produtos[i].preco);
		
		printf("Data da compra (dd/mm/aaaa): ");
		gets(produtos[i].fornecedor);	
		
		printf("Quantidade: ");
		scanf("%d%*c",&produtos[i].quantidade);
		
		printf("TelefoneFornecedor: ");		
		gets(produtos[i].telefoneFornecedor);			
	}	
}

void lista_produtos()
{
	int i;
//	system("cls");
	printf("Lista de produtos com quantidade zero.");
	for(i=0;i<NUMPROD;i++){		
		if(produtos[i].quantidade==0){
				printf("\n%d: %s\t%s\t%.2f",produtos[i].codigo,produtos[i].nome,produtos[i].telefoneFornecedor,produtos[i].preco);
		}			
	}	
}

int main()
{
	le_produtos();
	lista_produtos();
}


