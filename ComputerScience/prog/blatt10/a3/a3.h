#ifndef A3_H
#define A3_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#endif

void enqueue(int **arr, int* lastElementIdx, int *length, int element);
int dequeue (int **arr, int* lastElementIdx, int *length);
void printQueue(const int arr[], int lastElementIdx);
int expandArray(int **arr, int length);
int shrinkArray(int **arr, int length, bool min);
void test1(int **arr, int* lastElementIdx, int *length);
void test2(int **arr, int* lastElementIdx, int *length);
