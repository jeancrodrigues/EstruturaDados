#include<stdio.h>
#include<string.h>

int main(){
	
	char email[50];
	int i =0;
	
	printf("Digite seu e-mail: ");
	gets(email);	
	
	printf("\nSeu login eh: " );
	
	while(email[i]!='@' && email[i]!='\0')
		printf("%c",email[i++]);
	
}
