#include "stdio.h"
#include "string.h"

/*
 *  c abstraction assignment
 */

int main() {
    unsigned int letter = 'j';
    printf("letter is %d", letter);
    int result = 0;
    int i = 0;
    for(i = 0; i<letter; i++){
        result = result + i + letter;
    }
    printf("Result = %d\n", result);
    return result;
}

