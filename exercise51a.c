#include <stdio.h>

void hello(void)
{
    printf("Hi, A am a function\n");
}

int main(void)
{
    printf("This text is printed in main\n");
    hello();
    printf("And back again in main");
    
    return 0;
}