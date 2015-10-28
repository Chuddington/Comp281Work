/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task No.    : 1025 - LCM & HCF 
 * RunID       : 14225
 * Result      : Accepted
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int loopVar  = 0, hcf      = 1; //used for looping and HCF computation
  int inputOne = 0, inputTwo = 0; //used for user input
  int multOne  = 0, multTwo  = 0; //used for LCM

  scanf("%d %d", &inputOne, &inputTwo); //obtain the numbers to operate on

  for(loopVar = 1;  loopVar     <     inputOne;++loopVar) {
    if( (inputOne % loopVar) == 0 && (inputTwo % loopVar)==0) {
      hcf     =     loopVar;
    } else {}
  }

  printf("%d ", hcf); //output the HCF

  multOne = inputOne;
  multTwo = inputTwo;  
  while(multOne != multTwo && multOne > (inputOne - 1) ) {
    if( multOne <= multTwo) {
      multOne += inputOne;
      //adds inputOne to multOne, simulating a multiplication
    } else if(multOne == multTwo) {
      break; //moves out the while loop
    } else if(multOne > multTwo)  {
      multTwo += inputTwo;
      //adds inputTwo to multTwo, simulating a multiplication
    } else if(multOne == multTwo) {
      break; //moves out the while loop
    } else {}
  }
  printf("%d", multOne); //output the LCM
  return 0;
}
