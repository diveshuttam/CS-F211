#include "List.h"

#define LESSTHAN -1
#define GREATERTHAN +1
#define EQUALTO 0

int compare(Node a, Node b)
{
    if(a->record->marks < b->record->marks)
        return LESSTHAN;
    if(a->record->marks == b->record->marks)
        return EQUALTO;
    if(a->record->marks > b->record->marks)
        return GREATERTHAN;
}


void insertAtEnd(List list,struct student s)
{
    //creating a new student record
    Student s1=(Student)myalloc(sizeof(struct student));
    *s1=s;  //value at s1 is s
    
    //creating a new node
    Node n=(Node)myalloc(sizeof(struct node));
    n->record=s1;
    n->next=NULL;
    
    //if list is empty
    if(list->count==0)
    {
        (list->count)++;
        list->first=list->last=n;
        return;
    }
    
    //all other cases
    (list->count)++;
    list->last->next=n;
    list->last=n;
    
    //nothing to return as modifying pointers only
    return;
}


List createList(Student studArray, int arraySize)
{
    //allocate and initialize a new list
    List l=myalloc(sizeof(struct list));
    l->count=0;
    l->first=NULL;
    l->last=NULL;
    
    //insert the records using insert at end
    for(int i=0;i<arraySize;i++)
    {
        insertAtEnd(l,studArray[i]);
    }
    
    
    //return the new list
    //printList(l);
    return l;
}

void insertInOrder(List list, Node newNode)
{
    newNode->next=NULL;
    //if the list is NULL
    if(list->count==0)
    {
        list->first=list->last=newNode;
        (list->count)++;
        return;
    }
    
    //if newNode < the first
    if(compare(newNode,list->first)==LESSTHAN)
    {
        newNode->next=list->first;
        list->first=newNode;
        (list->count)++;
        return;
    }
    
    //insert in the list after ptr
    Node ptr=list->first;
    int count=list->count;
    for(;ptr->next!=NULL;ptr=ptr->next)
    {
       if(compare(newNode,ptr->next)==LESSTHAN)
       {
            newNode->next=ptr->next;
            ptr->next=newNode;
            (list->count)++;
            return;
       }
    }
    
   //insert at end
   ptr->next=newNode;
   list->last=newNode;
   (list->count)++;
   return;
}

List insertionSort(List list)
{
    //initialize a new list
    List l2=(List)myalloc(sizeof(struct list));
    l2->first=NULL;
    l2->last=NULL;
    l2->count=0;
    
    //sort the list
    int count=list->count;
    Node ptr;
    while(l2->count!=count)
    {
        ptr=list->first;
        list->first=list->first->next;
        insertInOrder(l2,ptr);
    }
    myfree(list);
    return l2;
}

double measureSortingTime(List list)
{
    struct timeval a,b;
    struct timezone a1,b1;
    int start=gettimeofday(&a, &a1);
    insertionSort(list);
    time_t end=gettimeofday(&b,&b1);
    return (b.tv_sec-a.tv_sec)*1000.0+(b.tv_usec-a.tv_usec)/1000.0;
}

void * myalloc(int size)
{
    //allocating extra int on heap and storing size at first location
    int * ptr=(int *)malloc(size+sizeof(int));
    ptr[0]=size;
    
    //increasing the globalCounter
    //+sizeof(int) as i am also allocating an extra int on heap for storing size
    globalCounter+=(size+sizeof(int));
    
    //return the ptr+1 i.e ahead by sizeof(int)
    return (void*)(ptr+1); //typecast to void*
}

void myfree(void* ptr)
{
    //convert to int * for getting size of this segment
    int *ptr2=ptr;
    
    //get the size of this segment and update counter
    ptr2=ptr2-1;
    globalCounter-=ptr2[0]+sizeof(int);//size was stored at ptr2[0]
    
    //myfree the memory
    free(ptr2);    
}
