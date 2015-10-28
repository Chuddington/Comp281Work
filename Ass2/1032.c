/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1032   : String Search
 * RunID       : 21763
 * Result      : Accepted
 */

#define MAXSTRINGLENGTH 1000 //maximum size of the string

#include<stdio.h>
#include<stdlib.h>

int stringLength(char*);         // personal implementation for strlen()
int isExact(char*, char*, int*); // function to check if 'y' is in 'x'

int main(void) {
  
  char* a;
  char* b;
  char* c; //input vars
  int bCount = 0, cCount = 0, loopVar = 0;
  a = malloc(MAXSTRINGLENGTH * sizeof(char) ); //create size for input
  b = malloc(MAXSTRINGLENGTH * sizeof(char) ); //create size for input
  c = malloc(MAXSTRINGLENGTH * sizeof(char) ); //create size for input

  fgets(a, MAXSTRINGLENGTH, stdin); //obtain input for string 1
  fgets(b, MAXSTRINGLENGTH, stdin); //obtain input for string 2
  fgets(c, MAXSTRINGLENGTH, stdin); //obtain input for string 3

  while(a[0] != '\0' && a[0] != '\n') {        //if there's content in  'a'
    if(isExact(a, b, &loopVar) == 0) ++bCount; //increment if 'b' is in 'a'
    if(isExact(a, c, &loopVar) == 0) ++cCount; //increment if 'c' is in 'a'
    ++a;                                       //increment pointer 'a'
  }
  printf("%d %d", bCount, cCount); //output to console
  return 0;
}

int stringLength(char* d) { //personal implementation of strlen()
  int x = 0;                //stores number of characters in the pointer
  while(d[x] != '\0') {     //while not 'EOF'
    ++x;                    
  }
  if(d[x - 1] == '\n') --x; //if newline is found, omit it from the count
  return x;                 //give string length
  
}

int isExact(char* e, char* f, int* loop) {
  int exact = 0, len = 0; //variable initialisation
  len = stringLength(f);  //obtain string length for second string (b || c)
  for(*loop = 0; *loop < len; ++*loop) { //run stringLength no. of times
    if(e[*loop] != f[*loop] ) {          //when values are not equal
      exact = 1;                         //create false flag and break from loop
      break;
    }
  }
  return exact; //0 = true, 1 = false
}
