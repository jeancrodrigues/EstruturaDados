#include<stdio.h>
#include<stdlib.h>

#include<conio.h>

int strlen(char * str)
{
	int i = 0;
	while(*(str+i)!='\0')i++;
	return i;
}

void strcpy(char *str , char *strdest )
{
	int i = 0;
	while(*(str+i)!='\0')
	{
		*(strdest+i)=*(str+i);
		i++;
	}
	*(strdest+i) = '\0';
}

void strlwr(char *str){
	int i = 0;
	while(*(str+i)!='\0'){
		int ord = *(str+i);
		if( ord >= 65 && ord <= 90 ){
			*(str+i) += 32;
		}
		i++;
	}
}

void strupr(char *str){
	int i = 0;
	while(*(str+i)!='\0'){
		int ord = *(str+i);
		if( ord >= 97 && ord <= 122 )
			*(str+i) -= 32;
		i++;
	}
}

int strchr(char *str, int chr )
{
	int i = 0;
	do{
		if(*(str+i)==chr)return i;
	}while(*(str+i++)!='\0');
	return NULL;
}

int strcmp(char *str, char *str_aux)
{
	int i = 0;
	do{
		if(*(str+i)!=*(str_aux+i)) return 0;
	}while(*(str+i)!='\0'&& *(str_aux+i++)!='\0');
	return 1;
}

void strcat(char *str, char *str_aux)
{
	int i=0 , j=0;
	while( *(str+i) != '\0' )i++;
	
	while(*(str_aux+j)!='\0')
	{
		*(str+i) = *(str_aux+j);
		j++;
		i++;
	}
}

int main(){	
	char nome[] = "jean" , snome[]=" rodrigues";	
	strcat(nome,snome);
	int i = (int)&nome;
	int aux = 8,dir=-1;
	char c;

	do{		 
		char *p = (char *)i;
		printf("%d %d %p\t",dir,aux,p);		
		for( int j = 0; j < aux;j++ ){
			char *p = (char *)i;			
			i+=dir;
			printf("%c",*p);
		}		
		printf("\n");
		
		c = getch();
		
		switch(c){
			case '2':aux=16;
			break;
			case '3':aux=32;
			break;
			case '4':aux=64;
			break;
			case '5':aux=128;
			break;
			case '6':aux=256;
			break;
			case '7':aux=512;
			break;
			case '8':aux=1024;
			break;
			case '9':aux=2048;
			break;
			case 'm':dir=1;
			break;
			case 'n':dir=-1;
			break;
		}
		
	}while(c!='o');
}
