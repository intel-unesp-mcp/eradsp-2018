#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	//recebe a dimensão da matriz quadrada a ser transposta no primeiro parametro da execução
        int tamanho = atoi(argv[1]);
        double *a , *b;
        int i,j;

        //Alocando dinamicamente as matrizes A (entrada) e B (saída) utilizando malloc
        a = (double*)malloc(tamanho*tamanho*sizeof(double));
        b = (double*)malloc(tamanho*tamanho*sizeof(double));

        //Iniciando matrizes
        for (i = 0; i < tamanho; i++) {
                for (j = 0; j < tamanho; j++) {
                        a[i*tamanho+j] = (float)i+j+10000;
                        b[i*tamanho+j] = 0.0;
                }
        }

        //Iniciando contador do tempo
        double tempo = omp_get_wtime();

        //Loop para transpor a matriz A em B
        #pragma omp parallel shared(a,b) private(i,j)
        {
                #pragma omp for schedule(static)
                for(i=0;i<tamanho;i++){
                	for(j=0;j<tamanho;j++){
                        	b[j*tamanho+i]+=a[i*tamanho+j];
                        }
                }
        }

        //Diferença do tempo
        tempo = omp_get_wtime() - tempo;

        //Escrever o tempo
        printf("%f\n",tempo);

        //Liberando memória
        free(a);
        free(b);

        return 0;
}

