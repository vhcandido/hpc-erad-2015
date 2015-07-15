#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(){

	const int num = SIZE;
	int i, j;
	static int x[SIZE], A[SIZE][SIZE];
	srand(time(NULL));

	FILE *Afile, *result;
	Afile = fopen("arquivo.dat", "w");
	result = fopen("result.dat", "w");

	if (!Afile){
		printf("Deu merda");
		return 1;
	}
	if (!result){
		printf("Deu merda");
		return 1;
	}

	fprintf(Afile, "%d \n", num);

	for(i=0; i<num; i++)
	{
		x[i]=rand()%1000;
		fprintf(result, "%d\n", x[i]);
	}

	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++){
			A[i][j]=rand()%1000;
			fprintf(Afile, "%d ", A[i][j]);
		}
		fprintf(Afile,"\n");
	}


	float soma, aux;
	for(i=0; i<num; i++){
		soma=0;
		for(j=0; j<num; j++){
			aux=A[i][j] * x[j];
			soma=aux+soma;
		}
		fprintf(Afile, "%f ", soma);
	}

	fclose(Afile);
	fclose(result);

	return 0;
}
