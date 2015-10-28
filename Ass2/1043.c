/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1043   : Sort Strings
 * RunID       : 26926 
 * Result      : Accepted
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSTRINGLENGTH 100 //maximum string input per line

char** insMatrix(int*, int*)                    ; //create a character matrix
void   getInput(char**, char*, int*, int)       ; //obtain user defined strings
void   cpyMatrix(char**, char**, int*, int*)    ; //copy matrix values
void   recMatrix(char**, int*, int*, int*)      ; //realloc a matrix
void   srtInput(char**, char*, int*, int*, int*); //bubble sort matrix
void   outInput(char**, int*, int*)             ; //output / clean matrix

int main(void) {

  int rowTotal = 0, newRows = 0, loop1 = 0, loop2 = 0              ;
  char* tempString = (char*)malloc(MAXSTRINGLENGTH * sizeof(char) );

  scanf("%d\n", &rowTotal)                 ;     //obtain first  int   input
  char** in1 = insMatrix(&rowTotal, &loop1);     //create smaller matrix
  getInput(in1, tempString, &rowTotal, 0)  ;     //obtain first string inputs

  scanf("%d\n", &newRows);                       //obtain second int input
  newRows += rowTotal    ;                       //obtain total row number

  char**in2 = insMatrix(&newRows, &loop1);       //create larger matrix 
  cpyMatrix(in1, in2, &rowTotal, &loop1) ;       //move values to larger matrix
  free(in1)                              ;       //clean smaller matrix

  getInput(in2, tempString, &newRows, rowTotal); //obtain new strings
  srtInput(in2, tempString, &newRows, &loop1, &loop2);

  recMatrix(in2, &newRows, &loop1, &loop2); //realloc char matrix
  outInput(in2, &newRows, &loop1)         ; //output       matrix

  free(tempString);
  free(in2)       ;

  return 0;
}

//creates a character matrix (rowNum, loopVar)
char** insMatrix(int* b, int* l) {                //no of strings, loop var
  char** a = (char**)malloc(*b * sizeof(char*) ); //allocate no. of strings
  for(*l = 0; *l < *b; ++*l) {
    //allocate space for each string
    a[*l] = (char*)malloc(MAXSTRINGLENGTH * sizeof(char) );
  }
  return a; //output matrix
}

//obtains user input (matrix, rowNum, loopVar)
void getInput(char** a, char* t, int* b, int l) {
  for(l; l < *b; ++l) {                  //loop for the number of strings
    scanf("%s", a[l] );
  }
}

//copies values from smaller matrix into larger one; frees smallMatrix memory
void cpyMatrix(char** a, char** b, int* x, int* l) {
  for(*l = 0; *l < *x; ++*l) { //go through original matrix rows
    strcpy(b[*l], a[*l] );     //copy strings over
    free(a[*l] )         ;     //clean smaller matrix element - not needed
  }
}

//reallocates memory of a matrix, removes new line chars
void recMatrix(char** a, int* b, int* l, int* m) {
  for(*l = 0; *l < *b; ++*l) {  //each matrix element
    if(a[*l][strlen(a[*l] ) - 1] == '\n') { //if it's a newline char
      a[*l][strlen(a[*l] ) - 1] = '\0'; //change to EOF char
    }
    a[*l] = (char*)realloc(a[*l], ( (strlen(a[*l] ) * sizeof(char) ) + 1) );
    //allocate just enough memory for the string
  }
}

//bubble sort using string length (matrix, rowTotal, tempString, loop1, loop2)
void srtInput(char** a, char* t, int* b, int* l, int* m) {
  for(*l = 0; *l < *b - 1; ++*l) {
    for(*m = 0; *m < (*b - *l) - 1; ++*m) {
      if(strlen(a[*m] ) < strlen(a[*m + 1] ) ) {

        t = a[*m]        ; //smaller value stored temporarily
        a[*m] = a[*m + 1]; //previous element stores the larger  string
        a[*m + 1] = t    ; //current  element stores the smaller string
        
      }
    }
  }
}

//runs through a matrix and outputs the data - free()'s the element afterwards
void outInput(char** a, int* b, int* l) { for(*l = 0; *l < *b; ++*l) { //for each string in the matrix
    printf("%s\n", a[*l] );
    free(a[*l] )          ; //clean matrix element
  }
}
