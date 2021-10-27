/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
bool check;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  check = true; 
}

int main(int argc, char * argv[])
{
  check = false;
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){//busy wait for signal to be delivered
    while(!check){
    };
    printf("Turing was right!\n");
    check = false;
    alarm(1);
  }
  return 0; //never reached
}