#include<stdio.h>
#include<stdlib.h>
#include "MultiQ"
#include<sys/time.h>



typedef FILE* File;

MulitiQ testDel(int num){

}

MultiQ loadData(File f){
  char buff[255];
  int data, int priority;
  MultiQ mq = newMQ(10);
  while(fscanf(f, "%d,%d",&taskid,&priority)){
    Task t=(Task){(Element){taskid,NULL}, priority};
    mq=insert(mq, t);
  } 
  return mq;
}

int main(){
  MultiQ mq;
  File f=fopen;
  mq=loadData();
  mq=testDel(10);
}
