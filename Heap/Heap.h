#pragma once 

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap 
{
    HPDataType* _a;
    int _size;
    int _capacity; 
} Heap;

// init destory
void HeapInit(Heap* php, HPDataType* a, int n);
void HeapDestory(Heap* php);

// push pop
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);

// Top
HPDataType HeapTop(Heap* php);

void Print(Heap* php);

// heap sort
void HeapSort(int* a, int n);
