#include <stdio.h>
#include <stdlib.h>

void print_system(int n, double A[n][n+1]) {
	int i, j;

	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			printf("%.5lf + ", A[i][j]);
		}
		printf(" = %.5f\n", A[i][n]);
	}
}

int main() {
	int n, k, i, j;

        // READING DATA =======================================================
	// reads n
	scanf("%d", &n);

	double A[n][n+1];
	//double **A = (double **)malloc(n*sizeof(double *));
	//reads A matrix
	for(i=0; i<n; ++i) {
		//A[i] = (double *)malloc((n+1)*sizeof(double *));
		for(j=0; j<n; ++j) {
			scanf("%lf", &A[i][j]);
			//printf("n: %lf\tA[%d][%d]\n", A[i][j], i, j);
		}
	}
	// reads B array
	for(i=0; i<n; ++i) {
		scanf("%lf", &A[i][n]);
		//printf("n: %lf\tA[%d][%d]\n", A[i][n], i, n);
	}

	//print_system(n, A);
	//=====================================================================

	//puts("");

	// FORWARD ELIMINATION ================================================
	for(k=0; k<n-1; ++k) {
		for(i=k+1; i<n; ++i) {
			A[i][k] = A[i][k]/A[k][k];
			for(j=k+1; j<=n; ++j) {
				A[i][j] -= A[i][k] * A[k][j];
			}
		}
	}
	//print_system(n, A);
	//=====================================================================

	//BACKWARD SUBSTITUTION ===============================================
	for(i=n-1; i>=0; --i) {
		for(j=i+1; j<=n; ++j) {
			A[i][n] -= A[i][j] * A[j][n];
		}
		A[i][n] /= A[i][i];
		printf("%.5lf ", A[i][n]);
	}
	//print_system(n, A);
	//=====================================================================

	return 0;
}
