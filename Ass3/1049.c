/* Student ID  : 200882675
 * Student Name: Michael Chadwick
 * Task 1049   : Priority Queue
 * RunID       : 41454
 * Result      : Runtime Error - Segmentation Fault
 * 
 * This program attempts to implement a binary heap as a priority queue.
 * The sorting efficiency would be N Log(N), as opposed to N^2 or worse.
 */

 
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int value;
  int priority;
} queue;

void   addRecord(queue*,    int*)      ; //extend queue array & obtain values
queue* recQ(queue*, int*); //reallocate space for queue pointer
void   popQ(queue*, int*,   int*, int*); //output q[1], sort values
void   srtQ(queue*, int*); //move queue items to correct space
void   switchValues(queue*, int,  int) ; //swap values between two queue's

int main(void) {

  char* cmd = (char*)malloc( (6 * sizeof(char) ) + 1); //size of "Insert\0"
  strcpy(cmd, "Pop"); //instantiate cmd variable

  //store on the heap
  int* total  = malloc(sizeof(int) );
  int* looper = malloc(sizeof(int) );
  int* loop1  = malloc(sizeof(int) );

  *looper = 1; //used in the while loop as a kill switch
  *total  = 1; //number of query elements
  *loop1  = 0; //variable used in for loops

  //malloc space for the queue array
  queue* list = (queue*)malloc(*total * sizeof(queue) );

  scanf("%s", cmd); //obtain "Insert" or "Pop" with this command
  //obtain values if the command was insert
  if(strcmp(cmd, "Insert") == 0) addRecord(list, total);
  //if the command was pop
  else if(strcmp(cmd, "Pop") == 0) {
    printf("-1"); //print -1 to show the end of the queue
    looper = 0  ; //apply while-loop kill-switch
  }

  //loop until at the end of the queue array
  while(looper != 0) {
    scanf("%s", cmd); //obtain command work
    //obtain values if the command was insert
    if(strcmp(cmd, "Insert") == 0) addRecord(list, total);
    //function to sort values then output correct value
    if(strcmp(cmd, "Pop"   ) == 0) popQ(list, total, loop1, looper);
  }
  //end of program
  return 0;
}

//function to add input to the queue array
void addRecord(queue* a, int* t) {
  ++*t; //increase the total size variable
  a = recQ(a, t); //reallocate the queue variable
  
  int* listEnd = (int*)malloc(sizeof(int) );

  *listEnd = *t - 1; //the final element in the array
  //obtain values and store in the end of the array
  scanf("%d %d", &a[*listEnd].value, &a[*listEnd].priority);
//  srtQ(a, listEnd); //function to sort the queue array

  free(listEnd); //free listEnd
}

//function to reallocate the memory for the queue array
queue* recQ(queue* a, int* t) {
  int loop = 0;
  queue* b = (queue*)malloc(*t * sizeof(queue) ); //change array size

  //loop to copy over the values
  for(loop = 1; loop < *t - 2; ++loop) {
    b[loop].value = a[loop].value;
    b[loop].priority = a[loop].priority;
  }
  return b; //return the modified queue array
}

//function to output highest priority value and sort the array
void popQ(queue* a, int* t, int* l, int* z) {
  //if the total shows the queue is technically 'empty,' as q[0] is NULL
  if(*t == 1) {
    printf("-1"); //output to show the end of the array
    *z = 0; //activate the 'looper' (kill-switch) variable
    return; //end the function
  }
  for(*l = *t-1; *l > 1; --*l) srtQ(a, l); //sort the queue array
  --*t; //lower the total
  printf("%d\n", a[1].value); //print the correct value
  //set the first queue item to the values of the last queue item
  a[1].value = a[*t].value, a[1].priority = a[*t].priority;
  a = recQ(a, t); //reallocate the array, cutting out the 'last' queue item

}

//function to sort the queue array
void srtQ(queue* a, int* t) {
  int* parent = (int*)malloc(sizeof(int) );
  int  state = 0;
  parent = 0;

  //if the 't' value, indicating index, is even, the parent node is half of t
  if(*t % 2 == 0) *parent = (*t / 2);
  //otherwise it is half of t-1
  else *parent = ( (*t-1) / 2 ), state = 1;

  //when state is 1, check adjacent node as well
  if(state == 1 && a[*t].priority > a[*t-1].priority && (*t-1) > 0) {
    //switch values if the right node in the tree is higher priority
    switchValues(a, *t, *t-1);
  }
  
  state = 0; //clean state variable
  //if the child node has higher priority than the parent
  if(a[*t].priority > a[*parent].priority && *parent > 0) {
    switchValues(a, *t, *parent); //switch parent/child values

    //sort the queue, using the parent as the index.  This causes a 
    //Log(N) sorting algorithm, which would be called 'N' times in popQ
    srtQ(a, parent);
  }
}

//function to swap values between two queue nodes
void switchValues(queue* a, int b, int c) {
  queue temp; //used to temporarily store a queue node's values
  temp.value    = 0;
  temp.priority = 0;

  //t = b
  temp.value    = a[b].value   ;
  temp.priority = a[b].priority;
  //b = c
  a[b].value    = a[c].value   ;
  a[b].priority = a[c].priority;
  //c = t
  a[c].value    = temp.value   ;
  a[c].priority = temp.priority;
}

