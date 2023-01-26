<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_RAND -40
#define MAX_RAND 80
#define ARRAY_SIZE 15

int main(void)
{
int i,array[ARRAY_SIZE];
int random_number;
srand(time(NULL));

for (i=0;i<ARRAY_SIZE;i++) {
    random_number=rand() %(MAX_RAND+1) MIN_RAND;
    array[i]=random_number;
}

int max = MIN_RAND+MAX_RAND; //could be done better
printf("Array of size %d filled with random numbers (between %d ... %d) is:\n", ARRAY_SIZE, MIN_RAND, max);

for (i=0;i<ARRAY_SIZE;i++) {
   printf("%d ", array[i]);
}
return 0;
=======
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_RAND -40
#define MAX_RAND 80
#define ARRAY_SIZE 15

int main(void)
{
int i,array[ARRAY_SIZE];
int random_number;
srand(time(NULL));

for (i=0;i<ARRAY_SIZE;i++) {
    random_number=rand() %(MAX_RAND+1) MIN_RAND;
    array[i]=random_number;
}

int max = MIN_RAND+MAX_RAND; //could be done better
printf("Array of size %d filled with random numbers (between %d ... %d) is:\n", ARRAY_SIZE, MIN_RAND, max);

for (i=0;i<ARRAY_SIZE;i++) {
   printf("%d ", array[i]);
}
return 0;
>>>>>>> 30c1dce2d89cd49c9d6c9d8d5b29eb894d1a016a
}