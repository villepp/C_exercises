#include <stdio.h>

int main(void){
    char string[100];
    printf("Enter a string: ");
    fgets(string,100,stdin);
    char *index_first= string;

    int i = 0;
    while(*(string+i)!='\0') {
        i++;
    }
    char *index_last = (string+i-2); //Thought this would work with -1 but output printed a new line. So it was pointing to new line character, I guess. Maybe there's a clearer way to do this.
    
    char temp;
    while(index_first<index_last) {
        temp = *index_first;
        *index_first= *index_last;
        *index_last = temp;

        index_first++;
        index_last--;
    }

    printf("Reversed string: %s",string);
    return 0;
}