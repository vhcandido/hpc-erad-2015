#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 10000
double A[SIZE][SIZE+1];

int main() {
	int n, k, i, j;

        // READING DATA =======================================================
	// reads n
	scanf("%d", &n);

	//reads A matrix
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			scanf("%lf", &A[i][j]);
		}
	}
	// reads B array
	for(i=0; i<n; ++i) {
		scanf("%lf", &A[i][n]);
	}
	//=====================================================================

	// FORWARD ELIMINATION ================================================
	for(k=0; k<n-1; ++k) {
		#pragma omp parallel private(j)
		{
			#pragma omp for schedule(guided)
				for(i=k+1; i<n; ++i) {
					double m = A[i][k]/A[k][k];
					for(j=k+1; j<=n; ++j) {
						A[i][j] -= m * A[k][j];
					}
				}
		}
	}
	//=====================================================================

	//BACKWARD SUBSTITUTION ===============================================
	for(i=n-1; i>=0; --i) {
		#pragma omp parallel private(j)
		{
			#pragma omp for schedule(guided)
			for(j=i+1; j<=n; ++j) {
				double aux = A[i][j] * A[j][n];
				#pragma omp atomic
				A[i][n] -= aux;
			}
		}
		A[i][n] /= A[i][i];
		printf("%.5lf ", A[i][n]);
	}
	//=====================================================================

	return 0;
}
