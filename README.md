# hpc-erad-2015
##ERAD 2015 Challenge - Parallelizing Gaussian elimination

###About
This is a solution for the challenge proposed in [ERAD 2015].
Check this PDF for the detailed description of the problem.

It was developed by
*Brunno Navarro
*Mario Camara Neto
*Victor Hugo Cândido
and written in C using the OpenMP API

###Executing
Generate the binary file for src/main.c with
```sh
gcc -o A src/main.c -fopenmp -mcmodel=large
```

###Input
The program accepts input from stdin (in the format described above)
OR
Inside data directory there is a generator of random systems. Compile it and
pass the matrix size as a parameter to the binary so it can generate
*arquivo.dat - formated input file
*resultado.dat - correct generated system's result

Run your main binary with
```sh
./A < data/arquivo.dat
```

Then compare the output in stdout with data/resultado.dat


[erad 2015]:http://www.dcce.ibilce.unesp.br/erad/desafio.html
[pdf]:http://www.dcce.ibilce.unesp.br/erad/problema.pdf
