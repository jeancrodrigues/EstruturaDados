#include<stdio.h>



int main(){
	char c;
	do
	{
		putchar(c);
		c=getc(stdin);
	}while(c!='\'');
	
}
