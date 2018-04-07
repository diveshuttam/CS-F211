#ifndef __BANK_H

#define __BANK_H

typedef struct date{
  int mm;
  int yyyy;
} date;


typedef struct record{
  long long int card_no;
  char bank_code[5];
  char fname[5];
  char lname[5];
  date exp_date;
} record;

char *date_tostring(date d);
record *myread(char *filename);

#endif
