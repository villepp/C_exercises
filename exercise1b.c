#include <stdio.h>

int main(void) {
    int rectangle_height = 7;
    int rectangle_width = 5;
    printf("A rectangle, of which height is %d cm and width is %d cm\n", rectangle_height, rectangle_width);
    int rectangle_perimeter = 2*rectangle_height + 2*rectangle_width;
    printf("the perimeter is equal to %d cm\n", rectangle_perimeter);
    int rectangle_area = rectangle_height*rectangle_width;
    printf("the area is equal to %d square cm", rectangle_area);
    return 0;
}