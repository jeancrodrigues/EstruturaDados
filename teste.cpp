#include<stdio.h>


int main(void)
{
	static int mat[]={4,5,6};
	static char st[] = "Hell, no Word";
	
	int i, *ptr;
	ptr = mat;
	for(i=0;i<3;i++)	
		printf("%d ",*ptr++);
		
	printf("\n");
	
	printf("\n%s",st);
	printf("\n%s",&st[0]);
	printf("\n%s",st+6);		
	
	return 0;
}
