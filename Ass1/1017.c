/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1017   : Product of integers in columns
 * RunID       : 14220
 * Result      : Wrong Answer
 * Side Note   : Computes everything except the very last input
 */

#include<stdio.h>
#include<stdlib.h>
typedef enum{false, true} bool;
//bool taken from: http://stackoverflow.com
//                 /questions/1921539/using-boolean-values-in-c
bool isOccupied(int[] );
int colCount = 0, loopVar = 0, loop2 = 0, x = 0, totalEntries = 0;

int main(void) {

  scanf("%d", &colCount); //input of columns
  int entryCount[colCount]; //storing the entry amounts
  int entries[colCount];

  for(loopVar = 0; loopVar < colCount; ++loopVar) {
    entries[loopVar]    = 1; //cleaning the arrays
    entryCount[loopVar] = 0;
  }

  for(loopVar = 0; loopVar < colCount; ++loopVar) { //loop to get entries/col.
    scanf("%d", &entryCount[loopVar]); //obtaining the entries per column
    totalEntries += entryCount[loopVar];
  }

  for(loopVar = 0; loopVar < totalEntries; ++loopVar) { //no. of repetitions
    if(entryCount[loopVar % colCount] != 0 && isOccupied(entryCount) ) {
      //current column's remaining entries
      scanf("%d", &x); //get entry input
      entries[loopVar % colCount] *= x; //create product w/ entry
      --entryCount[loopVar % colCount]; //decrement the no. of entries left in
                                        //the column
      }
  }

  for(loopVar = 0; loopVar < colCount; ++loopVar) { //loop for output
    printf("%d ", entries[loopVar] ); //output product of current column
  }

    return 0; //end of program
}

bool isOccupied(int a[] ) { 
  bool b = false; //flag to show that the array is empty
  for(loop2 = 0; loop2 < colCount; ++loop2) { //go through the array
    if(a[loop2] != 0) { //if the array is not empty
      b = true; //flag to show that the array is not empty
    }
  }
  return b;
}
