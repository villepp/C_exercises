#include <stdio.h>

int main(void) {
    printf("Give number of rows: \n");

    int rows;

    scanf("%d",&rows);



    for (int i = 1; i <= rows; i++) {
        int number = i+1;
        printf("%d",i);
    }
	
    return 0;
}