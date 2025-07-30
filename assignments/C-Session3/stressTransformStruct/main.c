#include <stdio.h>
#include <stdlib.h>

#include "stresstransform.h"

int main(int argc, char **argv) {

  if (argc != 2) {
    printf("Error: want app theta?\n");
    return 0;
  }
      
  double theta = atof(argv[1]);
  double sigx = 12.0;
  double sigy = -5.5;
  double tau = 3.5;
  double sigxp, sigyp, taup;

  StressTransform(sigx, sigy, tau, &sigxp, &sigyp, &taup, theta);
  printf("sigx' = %12.6f\nsigy' = %12.6f\ntau'  = %12.6f\n\n", sigxp, sigyp, taup);

  return 1;
}


