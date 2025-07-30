#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void myDGEMM(int n, double *A, double *B, double *C);

int main(int argc, char** argv) {

  int result = 0;
  
  if (argc != 3) {
    printf("Correct usage: app fileIn? fileOut?\n");
    exit(0);
  }

  char *filenameIN = argv[1];
  char *filenameOUT = argv[2];

  //
  // open input file & read n and matrix 
  //

  // Open file for binary input
  FILE* fpIN = fopen(filenameIN, "rb");
  if (fpIN == NULL) {
    printf("FAILED TO OPEN: %s\n", filenameIN);
    return 1;
  }

  // Write matrix size & matrix
  int n;  
  fread(&n, sizeof(int), 1, fpIN);


  // malloc arrays
  double *A = (double *)malloc(n*n*sizeof(double));
  double *C = (double *)malloc(n*n*sizeof(double));  

  
  if (A == 0 || C == 0) {
    printf("NO MEMORY ALLOCATED FOR ARRAYS\n");
    exit(0);
  }

  fread(A, sizeof(double), n*n, fpIN);
  
  // close 
  fclose(fpIN);    

  //
  // zero C as using DGEMM
  //

  double *cPtr = C;
  for (int i=0; i<n*n; i++)
    *cPtr++ = 0;

  //
  // perform C = A * A using DGEMM
  //
  
  myDGEMM(n, A, A, C);

  //
  // write C to filenameOUT
  // 

  // Open file for binary writing
  FILE* fpOUT = fopen(filenameOUT, "wb");
  if (fpOUT == NULL) {
    printf("FAILED TO OPEN: %s\n", filenameOUT);
    free(A);
    free(C);
    return 1;
  }

  // Write matrix size & matrix
  fwrite(&n, sizeof(int), 1, fpOUT);
  fwrite(C, sizeof(double), n*n, fpOUT);
  
  // close 
  fclose(fpOUT);  

  //
  // free matrices
  //
  
  free(A);
  free(C);

  if (result == 0)
    printf("SUCCESS\n");
  else
    printf("FAIL\n");    
	   
  return 0;
}
