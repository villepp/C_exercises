#include <stdio.h>

int main(void)
{
    int array[10];
    int total;
    
    for(int i=0;i<10;i++) {
        scanf("%d",&array[i]);
        total += array[i];
    }
    
    printf("Values: ");
    printf("%d",array[0]);
    for(int i=1;i<10;i++) {
        if(array[i]>=0){
                printf("%+d",array[i]);
            }
        else{
            printf("%d",array[i]);
        }
    }
    printf(" = %d", total);
}