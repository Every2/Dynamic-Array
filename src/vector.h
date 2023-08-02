#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define print(x) _Generic((x), int: printf("%d\n", x), char: printf("%c\n", x), float: printf("%f\n", x), default: printf("Unknown type\n"))

typedef struct {
    void** array;
    size_t size;
    size_t capacity;
} Vector;

Vector* createVector(size_t initialCapacity);
void freeVector(Vector* vector);
int append(Vector* vector, void* element);
size_t size(Vector* vector);
void* get(Vector* vector, size_t index);

#endif /* VECTOR_H */
