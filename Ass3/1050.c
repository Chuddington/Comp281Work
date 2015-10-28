/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1050   : Flight Planner
 * RunID       : 44069
 * Result      : Wrong Answer
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int cOne;
  int cTwo;
} conn; //stores connections, which is the user input

conn* insList(int*, int*)      ; //create a conn array
void filList(conn*, int*, int*); //obtain input for a conn array
void srtList(conn*, int*, int*); //qsort the conn array
void srtElem(conn); //swaps cOne & cTwo if cTwo is higher
int  conncmp(const void*, const void*)      ; //function for qsort
void chkList(conn*, conn*, int*, int*, int*); //checks if sTrm is in the array

int main(void) {
  //variable instantiation
  int cityTot = 0, conTot = 0, loop1 = 0, srchTtl = 1, result = 0;

  //obtain n and m
  scanf("%d", &cityTot);
  scanf("%d", &conTot );

  //create the space for the connection array and search term
  conn* list = insList(&conTot,  &loop1);
  conn* sTrm = insList(&srchTtl, &loop1);
  
  //obtain input for the connection array and search term
  filList(list, &conTot,  &loop1);
  filList(sTrm, &srchTtl, &loop1);

  //sort the connection array and the search term
  srtList(list, &conTot,  &loop1);
  if(sTrm[0].cOne < sTrm[0].cTwo) srtElem(sTrm[0] );

  //check if there is a in/direct route to the destination in the conn array
  chkList(list, sTrm, &conTot, &loop1, &result);

  //output search results
  if(result == 1) printf("Yes");
  else printf("No");

  //End of program
  return 0;
}

//function to create a conn array; returns the pointer
conn* insList(int* t, int* l) {
  conn* a = (conn*)malloc(*t * sizeof(conn) ); //malloc required space for array
  for(*l = 0; *l < *t; ++*l) { //for each element in the array
    //variable instantiation
    a[*l].cOne = 0;
    a[*l].cTwo = 0;
  }
  //send the created array back to the variable who called it
  return a;
}

//function to obtain input from the user, filling each element in a conn array
void filList(conn* a, int* t, int* l) {
  for(*l = 0; *l < *t; ++*l) { //for each element
    scanf("%d %d", &a[*l].cOne, &a[*l].cTwo);
  }
}

//function to sort into numerical order
void srtList(conn* a, int* t, int* l) {
  for(*l = 0; *l < *t; ++*l) { //for each element
    if(a[*l].cOne < a[*l].cTwo) { //if the first input is smaller
      srtElem(a[*l] ); //swap them around
    }
  }
  //sort the entire array
  qsort(&a[0], *t, sizeof(conn), conncmp);
}

//function to swap element values from a conn array
void srtElem(conn a) {
  int temp = a.cOne;
  a.cOne   = a.cTwo;
  a.cTwo   = temp;
}

//function used in srtList's qsort
int conncmp(const void* a, const void* b) {
  conn* c = (conn*)a;
  conn* d = (conn*)b;

  return (c->cOne - d->cOne);
}

//function to check if there is an in/direct route
void chkList(conn* a, conn* s, int* t, int* l, int* r) {
  //variable instantiation
  int nextVal = 0, temp = 0;

  for(*l = 0; *l < *t; ++*l) { //for each element
    //when you reach the first element with the same value in cOne, stop looping
    if(a[*l].cOne == s[0].cOne) break;
  }

  temp = *l; //store this index for later
  for(*l = temp; *l < *t; ++*l) { //working through the array
    //find the end of that numerical section
    //e.g. stop when you have found all of the 5s in the array
    if(a[*l].cOne != s[0].cOne) break;
  }

  nextVal = *l; //store this to allow recursive function use
  for(*l = nextVal; *l >= 0; --*l) { //work backwards in the array
    //if the values are the same as the search term
    if( (a[*l].cOne == s[0].cOne) && (a[*l].cTwo == s[0].cTwo) ) {
      *r = 1; //set result flag; end the function
      return;
    }
  }

  s[0].cOne = a[nextVal].cOne; //check the next cityID by calling chkList again
  if(s[0].cOne >= 0) chkList(a, s, t, l, r);

  return; //end function
}
