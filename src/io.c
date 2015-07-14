#include "io.h"

int read_input(double **A, double **B) {
	int n, i;
	double *a, *b;

	// read number of variables
	scanf("%d", &n);

	// allocate matrix n*n
	a = (double *)malloc(sizeof(double)*n*n);
	// read data from matrix
	for(i=0; i<n*n; i++) {
		scanf("%lf", (a+i));
	}

	// allocate array n
	b = (double *)malloc(sizeof(double)*n);
	// reads data from array
	for(i=0; i<n; i++) {
		scanf("%lf", (b+i));
	}

	*A = (double *)a;
	*B = (double *)b;
 	return n;
}

void print_system(int n, double *A, double *B) {
	int i, j;

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%.5lf + ", A[i*n+j]);
		}
		printf(" = %.5f\n", B[i]);
	}
}
