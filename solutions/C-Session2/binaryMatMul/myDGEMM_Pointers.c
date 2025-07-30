/*
 * This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are lda-by-lda matrices stored in column-major format.
 * On exit, A and B maintain their input values.
 */

void myDGEMM(int n, double* A, double* B, double* C) {

    double *cPtr = C;
    
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            double sum = 0;
	    double *bPtr = &B[col*n];
            for (int k = 0; k < n; k++) {
	      sum += A[row + k * n] * *bPtr++;
            }
            //C[row + col * n] += sum;
	    *cPtr++ += sum;	    
        }
    }
}
