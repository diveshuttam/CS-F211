#include "merge_sort.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//compare is used for the sorting condition
int compare(Element E1, Element E2){
  return E1.CGPA>E2.CGPA;
}
int min(int a, int b){
  return (a<b)?a:b;
}

//merge is the function that implements merge operation
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
  int p1=0;
  int p2=0;
  int p=0;

  while(p1<sz1 && p2<sz2){
    if(compare(Ls1[p1],Ls2[p2])){
      Ls[p++]=Ls2[p2++];
    }
    else{
      Ls[p++]=Ls1[p1++];
    }
  }

  if(p1<sz1){
    while(p1!=sz1){
      Ls[p++]=Ls1[p1++];
    }
  }
  else{
    while(p2!=sz2){
      Ls[p++]=Ls2[p2++];
    }
  }
  return;
}


//recursive version of merge sort that calls itself as well as merge
void mergeSort(Element Ls[], int start, int end){
  if(start==end)
    return;
  int mid=(start+end)/2;
  mergeSort(Ls, start, mid);
  mergeSort(Ls, mid+1, end);
  Element *New=(Element*)malloc(sizeof(Element)*(end-start+1));
  merge(Ls+start, mid-start+1, Ls+mid+1, end-mid, New);
  memcpy(Ls+start,New,sizeof(Element)*(end-start+1));
  //copy new back into the original array
  //for(int i=start, j=0;i<=end; i++, j++){
  //  Ls[i]=New[j];
  //}
  free(New);
}


//print the entire array
void printElements(Element Ls[], int size){
  for(int i=0;i<size;i++){
    printf("%s %f\n",Ls[i].Name, Ls[i].CGPA);
  }
}

void mergeSortIterative(Element Ls[], int start, int end){
  printf("in merge sort1\n");
  int size=end-start+1;
  int arr_size=1;
  Element *New=(Element *)malloc(sizeof(Element)*size);
  for(arr_size=1; arr_size<size; arr_size*=2){
    printf("in for loop\n");
    fflush(stdout);
    int arr1=0; int arr2=arr_size;
    while(arr2<=end){
      printf("sorting %d %d %d %d\n", arr1,arr1+arr_size-1,arr2,arr2+min(arr_size, end-arr2+1)-1);
      fflush(stdout);
      merge(Ls+arr1, arr_size, Ls+arr2, min(arr_size, end-arr2+1), New+arr1);
      arr1+=2*arr_size;
      arr2+=2*arr_size;
    }
  }
  //copy new back into the original array
  for(int i=0; i<size; i++){
    Ls[i]=New[i];
  }
}
