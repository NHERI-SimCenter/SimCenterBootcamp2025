#include <stdio.h>
#include <limits.h>

int main() {
    printf("The range of long int is from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("The range of long int is from %d to %d\n", INT_MIN, INT_MAX);
    printf("The range of long int is from 0 to %u\n", UINT_MAX);        
    return 0;
}
