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

void HeapInit(Heap* ph, HPDataType* a, int n);
void HeapDestory(Heap* ph);
void HeapPush(Heap* ph, HPDataType x);
void HeapPop(Heap* ph);
HPDataType HeapTop(Heap* ph);
void HeapSort(int* a, int n);
void Print(Heap* ph);