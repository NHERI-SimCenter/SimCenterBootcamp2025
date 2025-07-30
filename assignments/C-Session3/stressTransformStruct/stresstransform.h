#ifndef STRESSTRANSFORM_H
#define STRESSTRANSFORM_H

void StressTransform(double sigx,
		     double sigy,
		     double tau,
		     double *sigxp,
		     double *sigyp,
		     double *taup,
		     double theta);

#endif

