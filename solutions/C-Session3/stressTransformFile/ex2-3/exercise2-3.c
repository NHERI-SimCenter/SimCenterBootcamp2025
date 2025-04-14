#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"

//
// NOTE: the linked list not neede for working of this application
//    JUST there to allow you too work with a linked list!!
//

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Usage: appName dTheta\n");
    return 0;
  }
    
  // get dth from the first argument.  This is given in degrees!
  float dTheta = atof(argv[1]);
  if (dTheta <= 0) {
    printf("ERROR: appName dTheta : dTheta must be >= 0!\n");
    return 0;
  }
  
  // set the initial stress state
  STRESS S0;
  
  S0.sigx = 12.0;
  S0.sigy = -5.5;
  S0.tau  =  3.5;
  S0.next =  0;
  

  // linked list results
  STRESS *results = &S0;

  //
  // loop over valid theta, create STRESSm transform it and add to linked list
  //
  
  double theta = 0;
  for (theta = dTheta; theta <= 180.0; theta += dTheta) {
    STRESS *current = (STRESS *)malloc(sizeof(STRESS));
    StressTransform(S0, current, theta);

    // add at start of list
    current->next = results;
    results = current;
  }

  //
  // now linked list contains all values
  //  - iterate from start to finish, printing result and freeing space, don;t free S0
  //
  
  STRESS *current = results;
  while (current != NULL) {
    theta -= dTheta;    
    printf("%12.6f, %12.6f, %12.6f, %12.6f\n", theta, current->sigx, current->sigy, current->tau);
    STRESS *oldStress = current;
    current = current->next;

    // free memory
    if (oldStress != &S0)
      free(oldStress);
  }
  
  results = &S0;
}

