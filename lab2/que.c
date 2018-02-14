#include "que.h"


Queue newQ(){
  Queue q;
  q.front=NULL;
  q.rear=NULL;
  return q;
}


int isEmptyQ(Queue q){
return (q.front==NULL && q.rear==NULL);
}


Queue delQ(Queue q){
  //empty queue
  if(isEmptyQ(q))
    return q;
  //single element in queue
  else if(q.front == q.rear){
    q.front=q.rear=NULL;
    return q;
  }
  //all other cases
  else{
    Element *temp=q.front;
    q.front=(q.front)->next;
    free(temp);
    return q;
  }
}


Element front(Queue q){
  return *(q.front);
}


Queue addQ(Queue q, Element e){
  Element *e1=(Element *)malloc(sizeof(Element));
  if(isEmptyQ(q)){
    q.front=q.rear=NULL;
    return q;
  }
  else{
    (q.rear)->next=e1;
    q.rear=e1;
  }
}

int lengthQ(Queue q){
   int i=0;
   Element *trace=q.front;
   while(trace!=NULL){
     ++i;
     trace=trace->next;
   }
   return i;
}
