/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1029   : ROT R 3
 * RunID       : 21443
 * Result      : Accepted
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSTRINGLENGTH 1000

int main(void) {

  char* inputVar;     //var for input
  int iNo = 0, c = 0; //var for input ASCII value, total characters past
  
  inputVar = malloc(MAXSTRINGLENGTH * sizeof(char) ); //create size for input
  fgets(inputVar, MAXSTRINGLENGTH, stdin);            //obtain input

  while(inputVar[0] != '\0' && inputVar[0] != '\n') {
    iNo = (int)inputVar[0]; //ASCII value of current character
    
    if(       (iNo > 64 && iNo < 88) || (iNo > 96  && iNo < 120) ) {
      inputVar[0] += 3;  //adds 3 to letters a-w & A-W, becoming d-z & D-Z

    }else if( (iNo > 87 && iNo < 91) || (iNo > 119 && iNo < 123) ) {
      inputVar[0] -= 23; //makes x-z & X-Z into a-c & A-C
    }
    ++c;        //counter to find out how many characters have past
    ++inputVar; //moves pointer to the next character
  }
  inputVar -= c;           //get back to the beginning of the string
  fputs(inputVar, stdout); //output to console
  free(inputVar);          //clean up the malloc
  return 0;

}
