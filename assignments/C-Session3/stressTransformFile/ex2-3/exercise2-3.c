#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"


int main(int argc, char **argv) {

	// get dth from the first argument.  This is given in degrees!
	  
	// might be smart to set a default value, just in case the user
	// forgets when calling this  program;)


	// set the initial stress state
	STRESS S0;

	S0.sigx = 12.0;
	S0.sigy = -5.5;
	S0.tau  =  3.5;
	S0.next =  0;

	
	STRESS *results = &S0;

	// MISSING CODE

	
	STRESS *current = results;
	while (current != NULL) {
	  printf("sigx = %12.6f sigy' = %12.6f tau'  = %12.6f\n", current->sigx, current->sigy, current->tau);
	  current = current->next;
	}
}

