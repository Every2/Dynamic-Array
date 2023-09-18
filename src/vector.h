#ifndef VECTOR_H
#define VECTOR_H

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

Vector* createVector(size_t initialCapacity);
void freeVector(Vector* vector);
int append(Vector* vector, GenericValue element);
size_t size(Vector* vector);
GenericValue get(Vector* vector, size_t index);
void print(GenericValue value);

#endif /* VECTOR_H */
