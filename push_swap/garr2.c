#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandoms(int lower, int upper, 
                             int count)
{
    int i;
    for (i = 0; i < count - 1; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
    int num = (rand() % (upper - lower + 1)) + lower;
    printf("%d", num);
}
  
// Driver code
int main()
{
    int lower = 0, upper = 2147483647, count = 500;
  
    // Use current time as 
    // seed for random generator
    srand(time(0));
  
    printRandoms(lower, upper, count);
  
    return 0;
}
