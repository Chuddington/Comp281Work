/* Student ID: 200882675
 * Student Name: Michael Chadwick
 * Task ID: 1060 - Sorting Even Integers
 * RunID: 14228
 * Result: Accepted
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int input[10], evenOnly[10];
  int loopVar = 0, x = 0, temp = 0;

  for(loopVar = 0; loopVar < 10; ++loopVar) {
    scanf("%d", &input[loopVar] ) ; //obtain input
    evenOnly[loopVar] = 0; //cleaning the evenOnly array for use
  }

  for(loopVar = 0; loopVar < 10; ++loopVar) {
    if(input[loopVar] % 2 == 0) { //if an even number
      evenOnly[x] = input[loopVar];
      ++x;
      //stores only even numbers and the index within the input array
    }
  }

  //bubble sorting
  for(loopVar = 0; loopVar < 10; ++loopVar) {
    for(x = 0; x < 10 - loopVar; ++x) {
      if(evenOnly[x] > evenOnly[x + 1] && evenOnly[x + 1] != 0) {
        temp = evenOnly[x];
        evenOnly[x] = evenOnly[x + 1];
        evenOnly[x + 1] = temp;
      } 
    }
  }

  x = 0;
  for(loopVar = 0; loopVar < 10; ++loopVar) {
    if(input[loopVar] % 2 == 0) {
      input[loopVar] = evenOnly[x]; //changes the even number to a sorted one
      ++x; //increments the sorted array index
    }
    printf("%d ", input[loopVar] ); //output result
  }

  return 0;
}
