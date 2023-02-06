#include <stdio.h>
#define MAX_ARRAY 100

int difference(int array[]);

int main(void){
    printf("Give  an array: ");
    int array[MAX_ARRAY]={0};

    for (int i = 0; i < MAX_ARRAY; i++)
    {
        scanf("%d",&array[i]);

        if(array[i]==0){
            break;
        }
    }
    float diff = difference(array);
    printf("The difference of elements in array is: %.1f",diff);
}

int difference(int array[]) {
    int min, max = array[0];
    int i=0;
    while(array[i]!=0)
    {
        if (array[i]<min){
            min = array[i];
        }
        if (array[i]>max){
            max = array[i];
        }
        i++;
    }
    int diff = max-min;
    return diff;
}