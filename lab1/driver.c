//the main function for the SeqList program is contained in this file
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include "SeqList.h"

void sigint_handler(int dummy){
  printf("\nYou chose to exit!\n");
  exit(0);
}

int main(){
  //handle ctrl+c in driver itself
  signal(SIGINT,sigint_handler);

  int choice;
  SeqList sl=newList();
  do{
    printf("\nMain Menu:\n\
        1. printlist()\n\
        2. insertInOrder()\n\
        3. insertAtFront()\n\
        4. insertAtEnd()\n\
        5. delete()\n\
        6. deleteAtFront()\n\
        7. find()\n\
        Please enter a choice[1-6](Ctrl+C to exit)\n");
    scanf("%d", &choice);
    Key k;
    Element e;
    switch(choice)
    {
      case 1:
        printList(sl);
        break;
      case 2:
        e=askElement();
        sl=insertInOrder(sl,e);
        break;
      case 3:
        e=askElement();
        sl=insertAtFront(sl,e);
        break;
      case 4:
        e=askElement();
        sl=insertAtEnd(sl,e);
        break;
      case 5:
        sl=deleteAtFront(sl);
        break;
      case 6:
        k=askKey();
        e=*find(sl,k);
        printElement(e);
        break;
      default:
        printf("invalid choice");
    }
  }while(1);
  return 0;
}
