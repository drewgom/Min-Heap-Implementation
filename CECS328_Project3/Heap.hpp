// Name: Andrew Gomez
// Class: CECS328
// Project: Project 3

#ifndef Heap_hpp
#define Heap_hpp

class Heap  {
public:
    Heap();
    Heap(int* arr, int size);
    int parent(int index);
    int left(int index);
    int right(int index);
    void percolateDown(int index);
    void buildMinHeap();
    void heapsort();
    void insert(int newElement);
    void pop();
    void displayHeapArray();
    void allocateMoreMemory();
    void flipArray();
    void swapAt(int a, int b);
    
private:
    int* heap_array;
    int heap_size;
    int array_size;
    int capacity;
};

#endif
