<<<<<<< HEAD
#include <stdio.h>

int main(void) {
    char username[30]="Charley Brown";
    char gender = 'M';
    int age = 21;
    int shoe_size = 44; //Initially used float here, because sometimes decimals are used.
    float bank_balance = 34.43;
    char address[30]="Willowstreet";
    char phone_number[30]="050-234243242";

    printf("Name: %s\n",username);
    printf("Gender: %c\n",gender);
    printf("Address: %s\n",address);
    printf("Phone: %s\n",phone_number);
    printf("Age: %d\n",age);
    printf("Bank balance: %.2f\n",bank_balance);
    printf("Shoe size: %d",shoe_size);
    return 0;
=======
#include <stdio.h>

int main(void) {
    char username[30]="Charley Brown";
    char gender = 'M';
    int age = 21;
    int shoe_size = 44; //Initially used float here, because sometimes decimals are used.
    float bank_balance = 34.43;
    char address[30]="Willowstreet";
    char phone_number[30]="050-234243242";

    printf("Name: %s\n",username);
    printf("Gender: %c\n",gender);
    printf("Address: %s\n",address);
    printf("Phone: %s\n",phone_number);
    printf("Age: %d\n",age);
    printf("Bank balance: %.2f\n",bank_balance);
    printf("Shoe size: %d",shoe_size);
    return 0;
>>>>>>> 30c1dce2d89cd49c9d6c9d8d5b29eb894d1a016a
}