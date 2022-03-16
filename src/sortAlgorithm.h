#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;

void swap(int* a, int* b);
void selectionSort(int* arr, int& n);
void bubbleSort(int* arr, int& n);
void insertionSort(int* arr, int n);
void heapify(int* arr, int n, int i);
void heapSort(int* arr, int n);
void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr,int l,int r);
int Partition(int* a, int low, int high);
int RandomPivotPartition(int* a, int low, int high);
int quickSort(int* a, int low, int high);
int binarySearch(int* a, int item,int low, int high);
void binaryInsertionSort(int* a, int& n);
void chooseAlgorithms(int* a, int i, int& DataSize);
#endif