#include <stdio.h>

int main(void) {
    float rectangle_height;
    float rectangle_width;
    printf("Give height: ");
    scanf("%f",&rectangle_height);
    printf("Give width: ");
    scanf("%f",&rectangle_width);
    printf("\nA rectangle, of which height is %.0f cm and width is %.0f cm\n", rectangle_height, rectangle_width);
    float rectangle_perimeter = 2*rectangle_height + 2*rectangle_width;
    printf("the perimeter is equal to %.0f cm\n", rectangle_perimeter);
    float rectangle_area = rectangle_height*rectangle_width;
    printf("the area is equal to %.0f square cm", rectangle_area);
    return 0;
}