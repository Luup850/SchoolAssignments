/* A dummy program to test execution time for given input size */

#include <stdlib.h> // Required for atoi
#include <stdio.h>
#include <time.h>   // Required for timing
#include <unistd.h> // Required for Sleep

int main(int argc, char *argv[]){
  if(argc!=2){
	printf("The program expects exactly one command-line argument!\n");
	return 0;
  }
  int n=atoi(argv[1]);

  // Record the starttime
  struct timespec startTime, endTime;
  clock_gettime(CLOCK_MONOTONIC, &startTime);
  
  for(int a=0; a<n; a++){
	for(int b=0; b<n; b++){
	  for(int c=0; c<n; c++){
		for(int d=0; d<n; d++){
		  // Sleep for 1ms
		  // Think of this as simulating actual work
		  usleep(1);
		}
	  }
	}
  }

  // Record the end time, and print the total execution time
  clock_gettime(CLOCK_MONOTONIC, &endTime);
  double duration = (double)(endTime.tv_sec-startTime.tv_sec) +
	1e-9*(endTime.tv_nsec-startTime.tv_nsec);
  printf("Time elapsed: %.3fs\n", duration);
  
  return 0;
}