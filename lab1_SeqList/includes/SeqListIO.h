//this module has functionality which is dependent on the defination of
//various structures
#ifndef __SEQLISTIO_H
#define __SEQLISTIO_H
extern int checkRedirect;
#include "../SeqList.h"
Key askKey ();
Element askElement ();
void printElement (Element e);
void printList (SeqList sl);
void setRedirection ();
void clrerr ();
SeqList randomElements (SeqList sl, int noOfElements,
                        SeqList (*f) (SeqList, Element));
#endif
