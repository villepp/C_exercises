#include <stdio.h>

int main(void) {

    char forename[30];
    char familyname[30];
    printf("Type your forename and familyname: ");
    scanf("%s %s",forename,familyname);

    char gender;
    printf("What is your gender? Type in one character (M/F/O): ");
    scanf(" %c",&gender);

    int age;
    printf("How old are you?: ");
    scanf("%d",&age);

    float shoe_size;
    printf("Shoe size?: ");
    scanf("%f",&shoe_size);

    float bank_balance;
    printf("Bank balance?: ");
    scanf("%f",&bank_balance);

    char phone_number[15];
    printf("Phone number?: ");
    scanf(" %s",phone_number);

    char address[40];
    printf("Your address?: ");
    scanf(" %[^\t\n]s",address);


    printf("\nName: %s %s\n",forename, familyname);
    printf("Gender: %c\n",gender);
    printf("Address: %s \n",address);
    printf("Phone: %s\n",phone_number);
    printf("Age: %d\n",age);
    printf("Bank balance: %.2f\n",bank_balance);
    printf("Shoe size: %.1f",shoe_size);
	
	printf("Press ENTER key to Continue\n");  
getchar(); 
    return 0;
}