#include <stdio.h>

void coco_doo(int x);

int main(void) {
    printf("Give a number: ");
    int a;
    scanf("%d", &a);
    printf("\n");
    coco_doo(a);
    return 0;
}

void coco_doo(int number) {
    for (int i = 0; i < number; i++)
    {
        printf("cock-a-doodle-doo\n");
    }
    
}