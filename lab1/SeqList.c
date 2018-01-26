#include "SeqList.h"

SeqList *newList(){
  SeqList *sl=(SeqList*)malloc(sizeof(SeqList));
  sl->front=NULL;
  sl->rear=NULL;
  return sl;
}

//compare first is less than second
bool compare(Element e1, Element e2){
  return (e1.key.data<e2.key.data);
}

SeqList *insertInOrder(SeqList *sl, Element *e){  
  //case NULL
  if(sl->front==NULL){
    return insertAtFront(sl,e);
  }
  
  //case front
  if(compare(*e,*ptr)){
    return insertAtFront(sl,e);
  }
  
  //rest cases
  else{
    Element *ptr=sl->front;
  
    while(ptr->next!=NULL && !compare(*e,*(ptr->next)){
      ptr=ptr->next;
    }
    e->next=ptr->next;
    ptr->next=e;
    return sl;
  }
}

SeqList *insertAtFront(SeqList *sl, Element *e){  
  //case NULL
  if(sl->rear == NULL){
    sl->rear=sl->front=e;
  }
  else{
    e->next=sl->front;
    sl->front=e;
  }
  return sl;
}


SeqList *insertAtEnd(SeqList *sl, Element *e){
  //case list is NULL
  if(sl->rear==NULL){
    sl->rear=sl->front=e;
  }
  //rest cases
  else{
    sl->rear->next=e;
    e->next=NULL;
    sl->rear=e;
  }
  return sl;
}

SeqList *delete(SeqList *sl, Element *e){
  //case null
  if(sl->front==NULL)
    return sl;
  
  //case front
  if (sl->front==ele){
    return deleteAtFront(s);
  }
  //rest cases
  else{
  while(ptr->next != sl->rear){
    if(e==ptr->next){
      ptr->next=e->next;
      free(e);
      break;
    }
    ptr=ptr->next;
  }
}

SeqList *deleteAtFront(SeqList *sl){
  //case NULL
  if(sl->front==NULL){
    return sl;
  }
  //case only one element
  if(sl->front==sl->rear){
    free(sl->front);
    sl->front=sl->rear=NULL;
    retrun sl;
  }
  
  else{
    Element *ptr=sl->front;
    sl->front=sl->front->next;
    free(ptr);
    return sl;
  }
}

Element *find(SeqList *sl, Key k){
  while(ptr->next!=NULL){
    if(ptr->key==k)
      return e;
  }
}
