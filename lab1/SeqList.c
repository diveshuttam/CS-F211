#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>

void printElement(Element e){
  printf("Key:%d Next:%p\n",e.k.data, e.next);
}

void printList(SeqList sl){
  Element *ptr=sl.front;
  if(ptr==NULL){
    printf("There are no element in the list\n");
    return;
  }
  printf("Printing the list:\n");
  while(ptr!=NULL){
    printElement(*ptr);
    ptr=ptr->next;
  }
}

Key askKey(){
  int data;
  printf("Please enter the data value:");
  scanf("%d",&data);
  return (Key){.data=data};
}
Element askElement(){
  Key K=askKey();
  return (Element){.k=K, .next=NULL};
}

SeqList newList(){
  SeqList sl;
  sl.front=NULL;
  sl.rear=NULL;
  return sl;
}

//compare first is less than second
bool compare(Element e1, Element e2){
  if(e1.k.data<e2.k.data)
    return LESSTHAN;
  if(e1.k.data>e2.k.data)
    return GREATERTHAN;
  if(e1.k.data==e2.k.data)
    return EQUAL;
}

SeqList insertInOrder(SeqList sl, Element e){
  //case NULL and case before front
  if(sl.front==NULL || compare(e,*(sl.front))==LESSTHAN){
    return insertAtFront(sl,e);
  }
  else{
    //rest cases
    Element *ptr=sl.front;
    //move the pointer to the location after which to insert
    while(ptr->next!=NULL && !compare(e,*(ptr->next))==GREATERTHAN){
      ptr=ptr->next;
    }
    Element* e1=malloc(sizeof(e));
    e1->k=e.k;
    e1->next=ptr->next;
    ptr->next=e1;

    //update sl if inserting at end
    if(e1->next==NULL){
      sl.rear=e1;
    }
    return sl;
  }
}

SeqList insertAtFront(SeqList sl, Element e){
  Element *e1=malloc(sizeof(e));
  e1->next=NULL;
  e1->k=e.k;
  //case list is NULL
  if(sl.rear == NULL){
    sl.rear=sl.front=e1;
  }
  else{
    e1->next=sl.front;
    sl.front=e1;
  }
  return sl;
}

SeqList insertAtEnd(SeqList sl, Element e){
  Element *e1=malloc(sizeof(e));
  e1->next=NULL;
  e1->k=e.k;
  //case list is NULL
  if(sl.rear==NULL){
    sl.rear=sl.front=e1;
  }
  //rest cases
  else{
    sl.rear->next=e1;
    sl.rear=e1;
  }
  return sl;
}

SeqList delete(SeqList sl, Element e){
  //case null
  if(sl.rear==NULL)
    return sl;

  //case front
  if (compare(*(sl.front),e)==EQUAL){
    return deleteAtFront(sl);
  }

  //rest cases
  else{
    Element *ptr=sl.front;
    Element *ptr1=NULL;
    while(ptr->next != NULL){
      if(compare(*(ptr->next),e)){
        ptr1=ptr->next;
        ptr->next=ptr1->next;
        free(ptr1);
        break;
      }
      ptr=ptr->next;
    }
  }
  return sl;
}

SeqList deleteAtFront(SeqList sl){
  //case NULL
  if(sl.front==NULL){
    return sl;
  }
  //case only one element
  if(sl.front==sl.rear){
    free(sl.front);
    sl.front=sl.rear=NULL;
    return sl;
  }

  else{
    Element *ptr=sl.front;
    sl.front=sl.front->next;
    free(ptr);
    return sl;
  }
}

Element *find(SeqList sl, Key k){
  Element *ptr=sl.front;
  while(ptr->next!=NULL){
    if(compare(*ptr,(Element){.k=k,.next=NULL})==EQUAL)
      return ptr;
  }
  //not found return null
  return NULL;
}
