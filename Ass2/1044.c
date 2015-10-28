/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1044   : 2^x
 * RunID       : 31970
 * Result      : Accepted
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXCAPACITY 3020 //apparently 2^10000 = 1.99 * 10^3010

void insIntArray(int*, int, int*);

int data[MAXCAPACITY];

int main(void) {

  int input = 0, loop1 = 0, loop2 = 0, temp = 0, remainder = 0;
  scanf("%d", &input); //obtain input

  insIntArray(data, (int)MAXCAPACITY, &loop1); //fill array with 0
  data[MAXCAPACITY - 1] = 1; //used to start the 'power' loop below

  for(loop1 = 0; loop1 < input; ++loop1) { //loop 'input' no. of times
    for(loop2 = MAXCAPACITY - 1; 0 <= loop2; --loop2) {
      //start at the end of the array and work back
      temp = (data[loop2] * 2) + remainder;
      //multiply data[loop2] then add the remainder gained from data[loop2+1]
      data[loop2] = temp % 10;
      //get the unit from the multiplication
      remainder = temp / 10;
      //obtain the rest of the integer that the modulo removes
    }

    temp = 0, remainder = 0; //clean variables
  }

  input = 0; //use as an output variable now

  //find where the number begins in the array
  for(loop1 = 0; loop1 < MAXCAPACITY; ++loop1) {
    if(data[loop1] > 0) break;
  }

  //start from that point - add ints together
  for(loop2 = loop1; loop2 < MAXCAPACITY; ++loop2) {
//    printf("%d", data[loop2] );
    input += data[loop2];
  }

  printf("%d", input); //output value

  return 0;
}

void insIntArray(int* a, int b, int* l) {
  for(*l = 0; *l < b; ++*l) a[*l] = 0;
}
