#include<stdio.h>
#include<stdlib.h>
#include "que.h"



int main(){
  Queue q=newQ();
  do{
    printf("Main Menu\n\
            1. isEmpty\n\
            2. delQ\n\
	    3. frontQ\n\
	    4. addQ\n\
	    5. lengthQ\n\
	    6. printQ\n");
    int choice;
    printf("Please enter your choice[1-5]\n");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        if(isEmptyQ())
      	  printf("queue is empty\n");
	else
	  printf("queue is not empty\n");
	break;
      case 2:
        q=delQ(q);
	printf("deleted\n");
	break;
      case 3:
        Element e=frontQ(q);
	printf("front of the queue is\n");
	print(e);
	break;
      case 4:
        int data;
        printf("please enter the data you want in your ele\n");
	scanf("%d",&data);
	Element e;
	e.data.key=data;
	q=addQ(q,e);
	printf("added\n");
	break;
      case 5:
        printf("length of the queue is\n", lengthQ(q));
    }while(choice<=5 && choice>=0);
  }
}
