Like an plain array you should pass the initial size of Vector. The initialCapacity Parameter work in this way.

In the first moment functions allocs memory and check if everything works well, if faill function will return NULL.
Now the function alloc memory to allow the initial capacity size and the size of element pointers. The function will check if the allocation worked and if fail will return NULL and free memory.

The size of vector is defined to 0, because the vector is empty and the capacity of struct receive the initialcapacity value.

