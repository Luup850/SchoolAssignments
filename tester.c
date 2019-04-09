#include <stdio.h>
#include <string.h>

void test2 (int);

int main (void) {
    const int testArray = 2;
    test2(&testArray);

    printf("%d", testArray);
    return(0);
}

void test2 (int* array){
    
    *array = 7;
}