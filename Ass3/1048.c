/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1048   : Sort and Search for Dates
 * RunID       : 36124 
 * Result      : Accepted
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
  int   day    ; //stores the input for day
  char* month  ; //stores the input for month
  char* year   ; //stores the input for year as a string, keeping the format
  long  dateNum; //numerical representation in format YYYYMMDD
} date;

date* insLog   (int*, int*)              ; //creates a date* array
void  clnMatrix(date*, int*, int*)       ; //calls free() on date* variable
void  getInput (date*, char*, int*, int*); //obtains user input for date* var
void  procsDate(date*, int*, int*)       ; //gets date in long form, for sorting
int   dtecmp   (const void*, const void*); //compare function for qsort/bsearch
int   mnthID   (date*, int)              ; //for switch/case; month into intVar


int main(void) {

  //variable declaration/initialisation
  int total = 0, loop1 = 0; 
  char* temp = (char*)malloc( (9 * sizeof(char) ) + 1);
  strcpy(temp, "thisThMax");

  scanf("%d",            &total        ); //get function size
  date*     log = insLog(&total, &loop1); //create date array for input
  getInput (log, temp,   &total, &loop1); //obtain input for the date array
  procsDate(log,         &total, &loop1); //create numeric timestamps

  qsort(&log[0], total, sizeof(date), dtecmp); //sort using timestamps

  int   srchTtl = 1                       ; //set size of search term date array
  date* sTrm    = insLog(&srchTtl, &loop1); //create search term date
  getInput  (sTrm, temp, &srchTtl, &loop1); //get input for search term
  procsDate  (sTrm,      &srchTtl, &loop1); //create timestamp for search term

  //search log using search term's timestamp
  int* o = bsearch( (sTrm), log, total, sizeof(date), dtecmp);

  //output loop with total+1 iterations
  for(loop1 = 0; loop1 < (total + 1); ++loop1) {
    //output sorted log entry if there are log entries still to go
    if(loop1 < total) {
      printf("%s %d %s\n", log[loop1].month, log[loop1].day,
                           log[loop1].year);

    //after log output, if bsearch couldn't find the log entry
    } else if(o == NULL) printf("No");
    else printf("Yes"); //if bsearch could  find the log entry
  }

  //clean malloc'd variables
  clnMatrix(log, &total, &loop1);
  clnMatrix(sTrm, &srchTtl, &loop1);
  free(temp);

  //end of program
  return 0;
}

//function to create a date* array for input
date* insLog(int* t, int* l) {
  //malloc the correct size of the array
  date* a = (date*)malloc(*t * sizeof(date) );
  for(*l = 0; *l < *t; ++*l) {
    a[*l].day     = 31      ;         //var. init. as highest potential value
    a[*l].month   = (char*)malloc( (9 * sizeof(char) ) + 1);
    strcpy(a[*l].month, "thisThMax"); //var init.
    a[*l].year    = (char*)malloc( (2 * sizeof(char) ) + 1);
    strcpy(a[*l].year, "80");         //var. init. as an error checker
    a[*l].dateNum = 0       ;         //var. init.
  }

  //return completed date array
  return a;
}

//function to obtain input for a date array
void getInput(date* a, char* tmp, int* t, int* l) {
  for(*l = 0; *l < *t; ++*l) { //loop for the number of entries required
    strcpy(tmp, "thisThMax");  //reset char* tmp
    scanf("%s", tmp);          //obtain input for month; store in tmp

    //dynamically allocate memory for month using tmp's length
    a[*l].month = realloc(a[*l].month, strlen(tmp) + 1);
    strcpy(a[*l].month, tmp); //transfer tmp's data to the entry's month var
    scanf ("%d", &a[*l].day); //obtain input for entry's day  var
    scanf ("%s", a[*l].year); //obtain input for entry's year var
  }
}

//function to generate a numeric version of the input; used for sort/searching
void procsDate(date* a, int* t, int* l) {
  for(*l = 0; *l < *t; ++*l) {       //for each entry in date array
    a[*l].dateNum = (long)a[*l].day; //store day in timestamp var.
    switch(mnthID(a, *l) ) {  
      //function to create numeric month ID code. ranges 0-11 for each month
      case 0: //Jan.
        a[*l].dateNum += 100; //add month to the timestamp
        break;
      case 1:
        a[*l].dateNum += 200;
        break;
      case 2:
        a[*l].dateNum += 300;
        break;
      case 3:
        a[*l].dateNum += 400;
        break;
      case 4:
        a[*l].dateNum += 500;
        break;
      case 5:
        a[*l].dateNum += 600;
        break;
      case 6:
        a[*l].dateNum += 700;
        break;
      case 7:
        a[*l].dateNum += 800;
        break;
      case 8:
        a[*l].dateNum += 900;
        break;
      case 9:
        a[*l].dateNum += 1000;
        break;
      case 10:
        a[*l].dateNum += 1100;
        break;
      case 11:
        a[*l].dateNum += 1200;
        break;
    }
    switch(atol(a[*l].year) ) {    //obtain year as a long
      case 90: //1990
        a[*l].dateNum += 19900000; //add year to timestamp
        break;
      case 91:
        a[*l].dateNum += 19910000;
        break;
      case 92:
        a[*l].dateNum += 19920000;
        break;
      case 93:
        a[*l].dateNum += 19930000;
        break;
      case 94:
        a[*l].dateNum += 19940000;
        break;
      case 95:
        a[*l].dateNum += 19950000;
        break;
      case 96:
        a[*l].dateNum += 19960000;
        break;
      case 97:
        a[*l].dateNum += 19970000;
        break;
      case 98:
        a[*l].dateNum += 19980000;
        break;
      case 99:
        a[*l].dateNum += 19990000;
        break;

      case 0:  //2000
        a[*l].dateNum += 20000000;
        break;
      case 1:
        a[*l].dateNum += 20010000;
        break;
      case 2:
        a[*l].dateNum += 20020000;
        break;
      case 3:
        a[*l].dateNum += 20030000;
        break;
      case 4:
        a[*l].dateNum += 20040000;
        break;
      case 5:
        a[*l].dateNum += 20050000;
        break;
      case 6:
        a[*l].dateNum += 20060000;
        break;
      case 7:
        a[*l].dateNum += 20070000;
        break;
      case 8:
        a[*l].dateNum += 20080000;
        break;
      case 9:
        a[*l].dateNum += 20090000;
        break;
      case 10:
        a[*l].dateNum += 20100000;
        break;
      case 11:
        a[*l].dateNum += 20110000;
        break;
      case 12:
        a[*l].dateNum += 20120000;
        break;
    }
  }
}

//function to generate numerical ID from an entry's month
int mnthID(date* a, int b) {
  if(strcmp(a[b].month, "January"  ) == 0) return 0 ;
  if(strcmp(a[b].month, "February" ) == 0) return 1 ;
  if(strcmp(a[b].month, "March"    ) == 0) return 2 ;
  if(strcmp(a[b].month, "April"    ) == 0) return 3 ;
  if(strcmp(a[b].month, "May"      ) == 0) return 4 ;
  if(strcmp(a[b].month, "June"     ) == 0) return 5 ;
  if(strcmp(a[b].month, "July"     ) == 0) return 6 ;
  if(strcmp(a[b].month, "August"   ) == 0) return 7 ;
  if(strcmp(a[b].month, "September") == 0) return 8 ;
  if(strcmp(a[b].month, "October"  ) == 0) return 9 ;
  if(strcmp(a[b].month, "November" ) == 0) return 10;
  if(strcmp(a[b].month, "December" ) == 0) return 11;
  else return 0;
}

//timestamp compare function for qsort/bsearch
int dtecmp(const void* a, const void* b) {
  date* c = (date*)a;
  date* d = (date*)b;
  long  x = (c->dateNum - d->dateNum); //store difference in native datatype
  
  if(x == 0) return  0; //return  0 if they are the same    timestamp
  if(x > 0)  return -1; //return -1 if a/c is a more recent timestamp
  if(x < 0)  return  1; //return  1 if b/d is an older      timestamp
  else return (int)x;   //otherwise return the difference as an int
}

//function to clean a date array
void clnMatrix(date* a, int* t, int* l) {
  for(*l = 0; *l < *t; ++*l) {
    free(a[*l].month);
    free(a[*l].year );
  }
  free(a);
}
