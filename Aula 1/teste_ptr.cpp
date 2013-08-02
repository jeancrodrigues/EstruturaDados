#include <stdio.h>
#include <conio.h>



int main()
{

    char nome[]="jean carlos rodrigues";
    int x = 0, *p;  
    char *pc ;

    p = &x;

    while(1){
        
        for(int i = 0 ; i < 8 ; i ++ ){
            pc = (char * ) p;     
            char * vt[8];
            for(int j = 0;j<8;j++){
                vt[j] = pc++;
            }    
               
            printf("%d\t%x\t%p\t",x,p,p);         
            
            for(int j = 7;j>=0;j++){
                printf("%c",  *(vt[j]));         
            }            
            printf("\n");

            p+=2;
            x++;
        }
        
        getch();
        printf("\n");
        
    }
    getc(stdin);
}
