#include "src/vector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int intValue = 42;
    char charValue = 'A';
    float floatValue = 3.14;
    char* stringValue = "Hello, world!";
    
    Vector* vector = createVector(5);
    
    GenericValue value;
    value.type = INT;
    value.integer = intValue;
    append(vector, value);

    value.type = CHAR;
    value.character = charValue;
    append(vector, value);

    value.type = FLOAT;
    value.floatpointer = floatValue;
    append(vector, value);

    value.type = STRING;
    value.string = stringValue;
    append(vector, value);
    
    for (size_t i = 0; i < size(vector); i++) {
        printGeneric(get(vector, i));
    }
    
    freeVector(vector);
    
    return 0;
}