#include <stdio.h>
#include <stdlib.h>

#define print(x) _Generic((x), int: printf("%d\n", x), char: printf("%c\n", x), float: printf("%f\n", x), default: printf("Unkown type\n"))

typedef struct {
    void** array;
    size_t size;
    size_t capacity;
} Vector;

Vector* createVector(size_t initialCapacity) {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    if (vector == NULL) {
        return NULL; 
    }

    vector->array = (void**)malloc(initialCapacity * sizeof(void*));
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

int append(Vector* vector, void* element) {
    if (vector == NULL) {
        return 0; 
    }

    
    if (vector->size == vector->capacity) {
        size_t newCapacity = vector->capacity * 2;
        void** newArray = (void**)realloc(vector->array, newCapacity * sizeof(void*));
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

void* get(Vector* vector, size_t index) {
    if (vector == NULL || index >= vector->size) {
        return NULL;
    }
    return vector->array[index];
}
