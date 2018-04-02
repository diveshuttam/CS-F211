#include "employee.h"
#include "quickSort.h"
#include "insertionSort.h"
int partition();
int pivot();
void quickSort(Employee *Ls, int lo, int hi, int S){
  Stack S=push(newStack(), Pair{.lo=lo,.hi=hi});
  while(!isEmpty(s)){
    Pair current=top(s);
    s=pop(s);
    while(current.lo<current.hi){
      p=pivot(Ls, p.lo, p.hi);
      p=part(Ls, p.lo, p.hi, p);
      s=push(s, Pair{.lo=lo, .hi=hi});
      current.lo=p+1;
    }
  }
}
