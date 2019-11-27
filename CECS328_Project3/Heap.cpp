// Name: Andrew Gomez
// Class: CECS328
// Project: Project 3

#include "Heap.hpp"
#include <iostream>

using namespace std;
// Allocates the memory for a heap with a certain array size
Heap::Heap()    {
    // Allocates the memory
    heap_array = new int[1];
    array_size = 0;
    capacity = 1;
    heap_size = 0;
}

// creates a new heap with a certain array as its array
Heap::Heap(int* arr, int size)    {
    heap_array = arr;
    array_size = size;
    capacity = size;
    heap_size = 0;
}

// returns the index of the parent
int Heap::parent(int index) {
    if (index == 0) {
        return 0;
    }
    else    {
        return (index-1)/2;
    }
}

// returns the index of the left node
int Heap::left(int index)   {
    return (2 * (index + 1)) - 1;
}

// returns the index of the right node
int Heap::right(int index)  {
    return 2 * (index + 1);
}

// turns everything below a certain index in to a min heap
void Heap::percolateDown(int index)    {
    int l = left(index);
    int r = right(index);
    int smallest;
    
    if (l <= heap_size-1 && heap_array[l] < heap_array[index])  {
        smallest = l;
    }
    else {
        smallest = index;
    }
    if (r <= heap_size-1 && heap_array[r] < heap_array[smallest])  {
        smallest = r;
    }
    if (smallest != index)  {
        swapAt(index, smallest);
        percolateDown(smallest);
    }
    
}

// turns in a random array in to a min heap
void Heap::buildMinHeap()   {
    heap_size = array_size;
    for (int i = array_size/2; i >= 0; i--) {
        percolateDown(i);
    }
}

// Sorts an array using the heap property
void Heap::heapsort()   {
    buildMinHeap();
    for (int i = array_size-1; i > 0; i--) {
        swapAt(0, i);
        heap_size -= 1;
        percolateDown(0);
    }
    flipArray();
}

// Takes an element and inserts it properly in to a heap
void Heap::insert(int newElement)   {
    if (array_size+1 > capacity) {
        allocateMoreMemory();
    }
    
    // Here, we will add the element to the end. Then, while it
    // is still bigger than it's parent, then swap it with its parents
    heap_size++;
    array_size++;
    heap_array[heap_size-1] = newElement;
    int indexOfNew = heap_size-1;
    int indexOfParent = parent(indexOfNew);
    while(indexOfNew > 0 && heap_array[indexOfNew] < heap_array[indexOfParent])  {
        swapAt(indexOfNew, indexOfParent);
        indexOfNew = indexOfParent;
        indexOfParent = parent(indexOfNew);
    }

}

// returns the minimum element in the heap
void Heap::pop()    {
    // moves the heap array pointer up one memory address
    heap_array++;
    heap_size--;
    array_size--;
}


// displays the heap array
void Heap::displayHeapArray() {
    cout << "INDEX: ";
    for (int i = 1; i <= array_size; i++)    {
        cout << i << ", ";
    }
    cout << endl;
    cout << "ARRAY: ";
    for (int i = 0; i < array_size; i++)    {
        cout << heap_array[i] << ", ";
    }
    cout << endl;
}

// Allocates twice the amount of memory for the heap array
void Heap::allocateMoreMemory()   {
    int* newArray = new int[2 * capacity];

    for(int i = 0; i < array_size; i++) {
        newArray[i] = heap_array[i];
    }
    
    delete heap_array;
    heap_array = newArray;
    capacity = capacity * 2;
}

void Heap::flipArray()  {
    for (int i = 0; i < array_size/2; i++)  {
        swapAt(i, array_size-1-i);
    }
}

void Heap::swapAt(int a, int b)   {
    int swapA = heap_array[a];
    int swapB = heap_array[b];
    heap_array[a] = swapB;
    heap_array[b] = swapA;
}
