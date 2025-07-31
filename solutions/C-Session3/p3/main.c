#include <stdio.h>
#include <stdlib.h>

#include "stresstransform.h"

int main(int argc, char **argv) {

  if (argc != 3) {
    printf("ERROR: app dTheta? binFileName?");
    return 1;
  }
    
  double dTheta = atof(argv[1]);

  // initial stress
  STRESS *s0 = (STRESS *)malloc(sizeof(STRESS));
  if (s0 == 0)
    return -1;

  s0->sigX = 12.0;
  s0->sigY = -5.5;
  s0->tau  =  3.5;
  s0->theta = 0.0;
  s0->next = 0;    

  // variable to hold pointer to starting list element
  STRESS *theStresses = s0;

  //
  // add the stress to list
  //

  //  STRESS *tail = theStresses;
  
  for (double theta = dTheta; theta <= 180; theta+=dTheta) {
    STRESS *newStress = (STRESS *)malloc(sizeof(STRESS));
    if (newStress == 0)
      return -1;
    StressTransform(*s0, newStress, theta);
    newStress->theta = theta;

    //tail->next = newStress;
    //newStress->next = 0;
    //tail = newStress;
    
    newStress->next=theStresses;
    theStresses = newStress;
  }

  //
  // loop over and print
  //
  
  STRESS *currentStress = theStresses;
  while (currentStress != 0) {
    printf("%12.6f, %12.6f, %12.6f, %12.6f\n",
	   currentStress->theta,
	   currentStress->sigX,
	   currentStress->sigY,
	   currentStress->tau);
    
    currentStress = currentStress->next;
  }

  // do something usefule here
  
  //
  // write to binary
  //
  
  FILE *fileOUT = fopen(argv[2],"wb");
  
  currentStress = theStresses;
  while (currentStress != 0) {
    double out[4];
    out[0] = currentStress->theta;
    out[1] = currentStress->sigX;
    out[2] = currentStress->sigY;
    out[4] = currentStress->tau;
    fwrite(out, sizeof(double), 4, fileOUT);    
    currentStress = currentStress->next;
  }  

  fclose(fileOUT);    
  
}


