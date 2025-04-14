#ifndef STRESSTRANSFORM_H
#define STRESSTRANSFORM_H

typedef struct stress {
	double sigx;
	double sigy;
	double tau;
        struct stress *next;
} STRESS ;

void StressTransform(STRESS s, STRESS *sp, double theta);

#endif

