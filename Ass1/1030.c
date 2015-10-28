/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task No.    : 1030 - Precise Division
 * RunID       : 13222
 * Result      : Accepted
 */
 
#include <stdio.h>
#include <stdlib.h>

unsigned int a = 0, b = 0, n = 0, x = 0; //variable initialisation
float        y = 0.0; 

int main(void) {
  scanf("%d %d %d", &a, &b, &n); //obtain user input
  y = (float)a / (float)b; //create result

  for(x = 0; x < n; ++x) { 
    y *= 10; //loop to get the required decimal place
  }
  a = (int)y % 10; //find the remainder from dividing by 10 to
                   // get the decimal place
  printf("%d", (a) );
  return;

}
