#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <stdio.h>
#include <math.h>

//
// f(x) Function to integrate
//

double f(double x) {
  return 4.0 / (1.0 + x * x);
}

//
// integration of f(x) from 0->1 by simpsons  rule
//

double simpsons_rule(long int n) {
  if (n % 2 != 0) {
    n++; // Simpson's rule requires an even number of intervals                                                                                    
  }

  double sum = 0.0;
  double step = 1.0 / n;

  for (long int i = 0; i <= n; i++) {
    double x = i * step;
    if (i == 0 || i == n) {
      sum += f(x);
    } else if (i % 2 == 0) {
      sum += 2 * f(x);
    } else {
      sum += 4 * f(x);
    }
  }

  return sum * step / 3.0;
}

//
// integration of f(x) from 0->1 by trapezoidal rule
//

double trapezoidal_rule(long int n) {
  double sum = 0.0;
  double step = 1.0 / n;

  for (long int i = 0; i <= n; i++) {
    double x = i * step;
    if (i == 0 || i == n) {
      sum += f(x) / 2.0;
    } else {
      sum += f(x);
    }
  }

  return sum * step;
}

//
//
//

double basic(long int n) {
  double sum = 0.0;
  double step = 1.0 / n;

  for (long int i = 0; i <= n; i++) {
    double x = (i+.5)*step;
    sum += f(x);
  }

  return sum * step;
}

int main(int argc, char **argv) {

  // read args
  
  if (argc != 2) {
    printf("Usage: appName numSteps\n");
    exit(-1);
  }
  char *endptr;
  long int numSteps = strtol(argv[1], &endptr,10);

  double piBasic = basic(numSteps);
  double piSimpson = simpsons_rule(numSteps);
  double piTrapezoidal = trapezoidal_rule(numSteps);

  printf("PI basic:  %16.14f, diff(%16.14f), simpson %16.14f, (%16.14f), trap %16.14f, (%16.14f)\n",
	 piBasic, fabs(piBasic-M_PI),
	 piSimpson, fabs(piSimpson-M_PI),
	 piTrapezoidal, fabs(piTrapezoidal-M_PI));
  
  return 0;
}
