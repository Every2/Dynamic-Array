#include "src/vector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Vector* myArray = createVector(5);


    int intValue = 10;
    char charValue = 'A';
    float floatValue = 3.14;

    append(myArray, &charValue);
    append(myArray, &intValue);
    append(myArray, &floatValue);

    for (size_t i = 0; i < size(myArray); i++) {
        print(intValue);
        print(charValue);
        print(floatValue);
    }

    freeVector(myArray);

    return 0;
}