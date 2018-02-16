#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H


typedef struct Element{
  char Name[20];
  float CGPA;
} Element;
int min(int a, int b);
int compare(Element E1, Element E2);
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void mergeSort(Element Ls[], int start, int end);
void mergeSortIterative(Element Ls[], int start, int end);
void printElements(Element Ls[], int size);
#endif
