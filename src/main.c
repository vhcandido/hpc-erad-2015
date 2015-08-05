#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
	int n, k, i, j;
	double **A;

        // READING DATA =======================================================
	// reads n
	scanf("%d", &n);

	A = (double **)malloc(sizeof(double*) * n);

	//reads A matrix
	for(i=0; i<n; ++i) {
		A[i] = (double *)malloc(sizeof(double) * (n+1));
		for(j=n-1; j>=0; --j) {
			scanf("%lf", &A[i][j]);
		}
	}
	// reads B array
	for(i=0; i<n; ++i) {
		scanf("%lf", &A[i][n]);
	}
	//=====================================================================
        /*
	for(i=0; i<n; ++i) {
		for(j=0; j<=n; ++j) {
			printf("%.5lf ", A[i][j]);
		}
		printf("\n");
	}
	puts("");
        */
	// FORWARD ELIMINATION ================================================
	for(k=0; k<n-1; ++k) {
		if(A[k][k]==0){
			// swap lines
			for(i=k; i<n; ++i) {
				if(A[i][k] != 0) break;
			}
			
			#pragma omp parallel
			{
				#pragma omp for schedule(guided)
				for(j=k; j<=n; ++j) {
					double aux = A[i][j];
					A[i][j] = A[k][j];
					A[k][j] = aux;
				}
			}
		}
		#pragma omp parallel private(j)
		{
			#pragma omp for schedule(guided)
				for(i=k+1; i<n; ++i) {
					double m = A[i][k]/A[k][k];
					if (m==0) continue;
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
			for(j=i+1; j<n; ++j) {
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
