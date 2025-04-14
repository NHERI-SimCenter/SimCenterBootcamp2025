#ifndef STRESSTRANSFORM_H
#define STRESSTRANSFORM_H


typedef struct stress {
  double sigX;
  double sigY;
  double tau;
} STRESS;

void StressTransform(STRESS s, STRESS *sp, double theta);

#endif

