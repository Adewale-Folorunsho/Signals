#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int time;
void sigAlrm(int signum){
  time++;
  alarm(1);
}
void sigInt(int signum){
  printf("The code ran for %d seconds and there were %d alarms\n", time, time);
  exit(0);
}
int main(){
  time = 0;
  signal(SIGALRM,sigAlrm);
  signal(SIGINT,sigInt);
  alarm(1);
  while(1);
}