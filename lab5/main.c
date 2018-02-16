#include "merge_sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  Element *Ls=(Element *)malloc(1028*sizeof(Element));
  int currentMaxSize=1028;
  int currentSize=0;
  char name[20];
  float cgpa;

  FILE *fp=fopen("1024.txt","r");
  while(fscanf(fp,"%[^,]%*c%f\n",name,&cgpa)!=EOF){
    if(currentSize>=currentMaxSize-3){
      Element *Ls=(Element *)realloc(Ls, (sizeof(Element)*currentMaxSize*2));
      currentMaxSize*=2;
    }
    strcpy(Ls[currentSize].Name, name);
    Ls[currentSize++].CGPA=cgpa;
  }
  // printElements(Ls, currentSize);
  mergeSort(Ls, 0, 1024);
  printElements(Ls, currentSize);
}
