/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1046   : Sum of Adjacent Numbers
 * RunID       : 34060
 * Result      : Accepted
 */

#include<stdio.h>
#include<stdlib.h>

int** insMatrix(int*,  int*, int*)      ;  //create & empty a matrix
void  occMatrix(int**, int*, int*, int*);  //obtain user input for matrix
void  clnMatrix(int**, int*, int*)      ;  //free matrix function
void  gScan(int**, int*, int*, int*, int*, int*, int*, int*); //check grid

int (*sumP[4] ) (int**, int*, int*, int*); //f. pointer to sum functs
int xSum(int**, int*, int*, int*); //returns     column-adjacent numbers
int ySum(int**, int*, int*, int*); //returns        row-adjacent numbers
int dSum(int**, int*, int*, int*); //returns tl-br diag adjacent numbers
int eSum(int**, int*, int*, int*); //returns bl-tr diag adjacent numbers

int (*checkP[4] ) (int*, int*, int*, int*); //f. pointer to check functs
int xCheck(int*, int*, int*, int*); //checks if col+offset is lower than grid
int yCheck(int*, int*, int*, int*); //checks if row+offset is lower than grid
int dCheck(int*, int*, int*, int*); //checks if tl-br diag is lower than grid
int eCheck(int*, int*, int*, int*); //checks if bl-tr diag is lower than grid


int main(void) {

  //variable creation
  int** grid;
  int gridSize = 0, adjacentVar = 0, output = 0;
  int loop1 = 0, loop2 = 0, loop3 = 0;
  int fN = 0; //function pointer state - 0 is for columns using xSum

  sumP[0] = &xSum;
  sumP[1] = &ySum;
  sumP[2] = &dSum;
  sumP[3] = &eSum;
  checkP[0] = &xCheck;
  checkP[1] = &yCheck;
  checkP[2] = &dCheck;
  checkP[3] = &eCheck;

  scanf("%d %d",   &gridSize, &adjacentVar)  ; //get grid size and adjacent var
  grid = insMatrix(&gridSize, &loop1, &loop2); //create int matrix for input
  occMatrix(grid,  &gridSize, &loop1, &loop2); //obtain user input

  fN = 0; //set gScan to obtain the sum of the cols using xCheck/Sum
  gScan(grid, &gridSize, &adjacentVar, &output, &fN, &loop1, &loop2, &loop3);
  fN = 1; //set gScan to obtain the sum of the rows using yCheck/Sum
  gScan(grid, &gridSize, &adjacentVar, &output, &fN, &loop1, &loop2, &loop3);
  fN = 2; //set gScan to obtain sum of tl-br  diags using dCheck/Sum
  gScan(grid, &gridSize, &adjacentVar, &output, &fN, &loop1, &loop2, &loop3);
  fN = 3; //set gScan to obtain sum of bl-tr  diags using eCheck/Sum
  gScan(grid, &gridSize, &adjacentVar, &output, &fN, &loop1, &loop2, &loop3);

  printf("%d\n", output)            ; //output the highest value from gScan
  clnMatrix(grid, &gridSize, &loop1); //free() the matrix

  return 0;
}

//function to create a double-pointer integer matrix
int** insMatrix(int* b, int* l, int* m) { //rows, columns, loop vars
  int** a;                                        //matrix var
  a = (int**)malloc(*b * sizeof(int*) );          //allocate rows
  for(*l = 0; *l < *b; ++*l) {                    //loop 'row' amount of times
    a[*l] = (int*)malloc(*b * sizeof(int) );      //allocate columns
  }

  for(*l = 0; *l < *b; ++*l) {   //for every column
    for(*m = 0; *m < *b; ++*m) { //for every row
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
void occMatrix(int** a, int* b, int* l, int* m) {
  for(*l = 0; *l < *b; ++*l) {   //for every column
    for(*m = 0; *m < *b; ++*m) { //for every row
      scanf("%d", &a[*l][*m] );  //obtain input
    }
  }
}

void gScan(int** a, int* b, int* c, int* d, int* f, int* l, int* m, int* n) {
  int temp = 0;

  for(*l = 0; *l < *b; ++*l) {     //For each row
    for(*m = 0; *m < *b; ++*m) {   //for each column
      for(*n = 0; *n < *c; ++*n) { //gets the offset
        if( (*checkP[*f] ) (b, l, m, n) ) temp += (*sumP[*f]) (a, l, m, n);
      //if correct checkFunction returns true, add to temp 
      //else break from the offset loop
        else break;
      }
      if(*d < temp) *d = temp, temp = 0;
    //^if the highest output so far is smaller than the temp, get the value
    //V otherwise reset the temp variable
      else temp = 0;
    }
  }
}

int xSum(int** a, int* b, int* c, int* d) {
  return a[*b][*c + *d];
  //grid[loop1][loop2 + offset] -> y = 'loop1' graph
}
int ySum(int** a, int* b, int* c, int* d) {
  return a[*b + *d][*c];
  //grid[loop1 + offset][loop2] -> x = 'loop2' graph
}
int dSum(int** a, int* b, int* c, int* d) {
  return a[*b + *d][*c + *d];
  //grid[loop1 + offset][loop2 + offset] -> y = 'n' - x graph
}
int eSum(int** a, int* b, int* c, int* d) {
  return a[*b - *d][*c + *d];
  //grid[loop1 - offset][loop2 + offset] -> y = x graph
}

int xCheck(int* b, int* c, int* d, int* e) {
  if( (*d + *e) < *b ) return 1;
  //(col-loop + offset) < grid size
  else return 0;
}
int yCheck(int* b, int* c, int* d, int* e) {
  if( (*c + *e) < *b ) return 1;
  //(row-loop + offset) < grid size
  else return 0;
}
int dCheck(int* b, int* c, int* d, int* e) {
  if(xCheck(b, c, d, e) && yCheck(b, c, d, e) ) return 1;
  //( (col-loop + offset) & (row-loop + offset) ) < grid size
  else return 0;
}
int eCheck(int* b, int* c, int* d, int* e) {
  if( (*c - *e) >= 0 && xCheck(b, c, d, e) ) return 1;
  //if rows are within the array & xCheck()
  else return 0;
}
