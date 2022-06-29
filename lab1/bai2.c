#include <stdio.h>

// Ho Sy The - 20200614

int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("Ho Sy The - 20200614\n");
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("\t\ta[%d]\t", i);
    printf("\n");
    
    for (int i=0; i<5;i++)  printf("\t%p", a + i);

    printf("\n");
           
    return 0;
}