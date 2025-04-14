#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  // read a long int
  long int numSteps = 100;
  if (argc == 2) {
    char *endPtr;
    numSteps = strtol(argv[1], &endPtr, 10);
  }

  //
  // perform calculation
  //
  
  double pi   = 0;
  double dx = 1./numSteps;
  double x = dx;

  for (int i=0; i<numSteps; i++) {
    x = (i+.5)*dx;    
    pi += 4./(1.+x*x);
    //x += dx; not as accurate
  }
  
  pi *= dx;
  
  printf("PI = %16.14f, diff(%16.14f) %ld\n",pi, fabs(pi-M_PI), numSteps);
  return 0;
}
