#include <stdio.h>
#include <stdlib.h>

#include "stresstransform.h"

int main(int argc, char **argv) {

	STRESS S0;
	STRESS Sp;

	S0.sigX = 12.0;
	S0.sigY = -5.5;
	S0.tau  =  3.5;

	StressTransform(S0, &Sp, 25.0);
	printf("sigx = %12.6f, sigY = %12.6f, tau  = %12.6f\n\n", Sp.sigX, Sp.sigY, Sp.tau);
}


