#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stresstransform.h"

// 
// check out the new function header:
// ... much more compact
// ... much easier to adapt to 3d states of stress (just change STRESS)
//

void StressTransform(STRESS s, STRESS *sp, double theta) {

	double pi = 4.0*atan(1.);
	double th = theta * pi/180.;

	double sn = sin(th);
	double cs = cos(th);

	sp->sigX = s.sigX*cs*cs + s.sigY*sn*sn + 2.*s.tau*sn*cs;
	sp->sigY = s.sigX*sn*sn + s.sigY*cs*cs - 2.*s.tau*sn*cs;
	sp->tau  = (s.sigY - s.sigX)*sn*cs + s.tau*(cs*cs - sn*sn);
}

