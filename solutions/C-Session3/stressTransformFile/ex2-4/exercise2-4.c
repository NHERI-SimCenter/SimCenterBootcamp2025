
#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"

//
// writing to binary theta, sigX, sigY, tau
// 

int main(int argc, char **argv) {

  if (argc != 3) {
    printf("Usage: appName dTheta binaryFile\n");
    return 0;
  }
    
  // get dth from the first argument.  This is given in degrees!
  float dTheta = atof(argv[1]);
  if (dTheta <= 0) {
    printf("ERROR: appName dTheta : dTheta must be >= 0!\n");
    return 0;
  }

  // FILE *fpASCII = fopen(argv[2], "w");  
  FILE *fpBINARY = fopen(argv[2], "wb");
  
  // set the initial stress state
  STRESS S0, S1;
  
  S0.sigx = 12.0;
  S0.sigy = -5.5;
  S0.tau  =  3.5;
  S0.next =  0;

  //
  // loop over valid theta, transform & write out
  //
  
  STRESS *current = &S1;
  double theta = 0;
  double dataOut[4];
  
  for (theta = dTheta; theta <= 180.0; theta += dTheta) {
    StressTransform(S0, current, theta);
    dataOut[0] = theta;
    dataOut[1] = current->sigx;
    dataOut[2] = current->sigy;
    dataOut[3] = current->tau;
    fwrite(dataOut, sizeof(double), 4, fpBINARY);
    //    fprintf(fpASCII, "dataOut[0], dataOut[1], dataOut[2], dataOut[3]); 
  }

  //fclose(fpAscii);
  fclose(fpBINARY);
}

