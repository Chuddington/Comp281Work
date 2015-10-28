/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1041   : Dot Product of Two Matrices
 * RunID       : 22426 
 * Result      : Accepted
 */

#include<stdio.h>
#include<stdlib.h>

int** insMatrix(int*,  int*, int*, int*);       //create & empty a matrix
void  occMatrix(int**, int*, int*, int*, int*); //obtain user input for matrix
void  clnMatrix(int**, int*, int*);             //free matrix function

int main(void) {

  int m = 0, n = 0, p = 0;  //row and column variables
  int loop1 = 0, loop2 = 0, loop3 = 0; //loop variables
  int** matrix1;            //n * m
  int** matrix2;            //m * p
  int** output ;            //n * p

  scanf("%d", &n);          //m1 rows
  scanf("%d", &m);          //m1 columns & m2 rows
  scanf("%d", &p);          //m2 columns

  matrix1 = insMatrix(&n, &m, &loop1, &loop2); //make n * m matrix
  matrix2 = insMatrix(&m, &p, &loop1, &loop2); //make m * p matrix
  output  = insMatrix(&n, &p, &loop1, &loop2); //make n * p matrix for output

  occMatrix(matrix1, &n, &m, &loop1, &loop2);  //obtain matrix2 input
  occMatrix(matrix2, &m, &p, &loop1, &loop2);  //obtain matrix2 input

  //process matrices for the output matrix
  for(loop1 = 0; loop1 < n; ++loop1) {     //for each 'n' section
    for(loop2 = 0; loop2 < p; ++loop2) {   //for each 'p' section
      for(loop3 = 0; loop3 < m; ++loop3) { //for each 'm' section
        //output[n][p] += matrix1[n][m] * matrix2[m][p]
        output[loop1][loop2] += (matrix1[loop1][loop3] * matrix2[loop3][loop2]);
      }
    }
  }

  for(loop1 = 0; loop1 < n; ++loop1) {      //for every row in output
    for(loop2 = 0; loop2 < p; ++loop2) {    //for every column in output
      if(loop2 == (p - 1) ) printf("%d", output[loop1][loop2] );
      //^ if at the end of the column, print value without a space else...
      else printf("%d ", output[loop1][loop2] ); //print value with a space
    }
    printf("\n"); //newline when you get to the end of the row
  }

  clnMatrix(matrix1, &n, &loop1); //cleans matrix1
  clnMatrix(matrix2, &m, &loop1); //cleans matrix2
  clnMatrix(output , &n, &loop1); //cleans output

  return 0;
}

//function to create a double-pointer integer matrix
int** insMatrix(int* b, int* c, int* l, int* m) { //rows, columns, loop vars
  int** a;                                        //matrix var
  a = (int**)malloc(*b * sizeof(int*) );          //allocate rows
  for(*l = 0; *l < *b; ++*l) {                    //loop 'row' amount of times
    a[*l] = (int*)malloc(*c * sizeof(int) );      //allocate columns
  }

  for(*l = 0; *l < *b; ++*l) {   //for every column
    for(*m = 0; *m < *c; ++*m) { //for every row
      a[*l][*m] = 0;             //instantiate the matrix element
    }
  }
  return a; //output the matrix
}

//function to clean manually allocated memory
void clnMatrix(int** a, int* b, int* l) {
  for(*l = 0; *l < *b; ++*l) { //for each row in the double pointer
    free(a[*l] );              //free the memory taken by that row
  }
  free(a); //free the list of pointers
}

//gets scanned input for the matrix
void occMatrix(int** a, int* b, int* c, int* l, int* m) {
  for(*l = 0; *l < *b; ++*l) {   //for every column
    for(*m = 0; *m < *c; ++*m) { //for every row
      scanf("%d", &a[*l][*m] );  //obtain input
    }
  }
}

