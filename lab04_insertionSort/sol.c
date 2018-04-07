#include "bank.h"
#include<stdio.h>
#include<stdlib.h>

char* date_tostring(date d){
  static char s[7];
  sprintf(s,"%02d/%4d",d.mm, d.yyyy);
  return s;
}

record* myread(char *filename){
  long long int card_no;
  char bank_code[5], fname[5], lname[5];
  int exp_mo,exp_year;
  FILE *fp = fopen(filename, "r");
  int current_alloc_size = 10;
  int current_record = 0;
  record * init = (record *)malloc(sizeof(record)*current_alloc_size);
  while(fscanf(fp, "%lld%*c%5s%*c%d%*c%d%*c%5s%*c%5s",
        &card_no, bank_code, &exp_mo, &exp_year, fname, lname)!=EOF){

    if(current_record == current_alloc_size){
      init=(record *)realloc(init, sizeof(record)*current_alloc_size*2);
      current_alloc_size*=2;
    }

    init[current_record++]=(record){.card_no=card_no, .bank_code=*bank_code,
      .fname=*fname, .lname=*lname,.exp_date=(date){.mm=exp_mo, .yyyy=exp_year}};
   /* printf("%lld %s %s %s %s\n",
        card_no, bank_code, date_tostring(init[current_record-1].exp_date), fname, lname) ;
  */}
  return init;
}

int main(){
  char s[10];
  for (int i=10; i<=10000000; i*=10)
  {
    sprintf(s, "%d", i);
    record *init = myread(s);
  }
}
