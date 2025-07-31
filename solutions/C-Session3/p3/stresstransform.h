#ifndef STRESSTRANSFORM_H
#define STRESSTRANSFORM_H


typedef struct stress {
  double sigX;
  double sigY;
  double tau;
  double theta;
  struct stress *next;
} STRESS;

void StressTransform(STRESS s, STRESS *sp, double theta);

#endif

