#include <stdio.h>
#include <stdlib.h>


typedef enum {
    INT,
    CHAR, 
    FLOAT,
    STRING,
    VECTOR
} Generic;

typedef struct {
    Generic type;
    union {
    int integer;
    char character;
    float floatpointer;
    char* string;
    struct Vector* vector;
    };
} GenericValue;

typedef struct {
    GenericValue* array;
    size_t size;
    size_t capacity;
} Vector;

Vector* createVector(size_t initialCapacity) {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    if (vector == NULL) {
        return NULL; 
    }

    vector->array = (GenericValue*)malloc(initialCapacity * sizeof(GenericValue));
    if (vector->array == NULL) {
        free(vector);
        return NULL; 
    }

    vector->size = 0;
    vector->capacity = initialCapacity;

    return vector;
}

void freeVector(Vector* vector) {
    if (vector != NULL) {
        free(vector->array);
        free(vector);
    }
}

int append(Vector* vector, GenericValue element) {
    if (vector == NULL) {
        return 0; 
    }

    
    if (vector->size == vector->capacity) {
        size_t newCapacity = vector->capacity * 2;
        GenericValue* newArray = (GenericValue*)realloc(vector->array, newCapacity * sizeof(GenericValue));
        if (newArray == NULL) {
            return 0; 
        }
        vector->array = newArray;
        vector->capacity = newCapacity;
    }

    vector->array[vector->size++] = element;
    return 1; 
}

size_t size(Vector* vector) {
    if (vector == NULL) {
        return 0;
    }
    return vector->size;
}

GenericValue get(Vector* vector, size_t index) {
    GenericValue v = {0};
    if (vector == NULL || index >= vector->size) {
        return v;
    }
    return vector->array[index];
}

void printGeneric(GenericValue value) {
    switch (value.type) {
        case INT:
            printf("%d\n", value.integer);
            break;
        case CHAR:
            printf("%c\n", value.character);
            break;
        case FLOAT:
            printf("%f\n", value.floatpointer);
            break;
        case STRING:
            printf("%s\n", value.string);
            break;
        case VECTOR:
            printf("Vector\n"); 
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}

