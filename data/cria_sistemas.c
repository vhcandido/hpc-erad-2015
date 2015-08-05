#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(int argc, char **argv){
	int size = SIZE;
	if(argc>1) {
		size = atoi(argv[1]);
	}
	const int num = size;
	int i, j;
	int x[size], **A;
	srand(time(NULL));

        A = (int **)malloc(sizeof(int *) * num);

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
		A[i] = (int *)malloc(sizeof(int) * num);
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
