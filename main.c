#include <stdio.h>
#include <stdlib.h>
#include "calculo_numerico.h"
/*
Metodo eliminaçãod e gauss

*/


int main(){

	float **p;
	int linhas, colunas;
	
	printf("Digite o número de equações:");
	scanf("%d", &linhas);
	
	printf("Digite o número de variáveis:");
	scanf("%d", &colunas);


	p = malloc(sizeof(float*)*linhas);
	
	//iteration variables
	int i = 0;
	int j = 0;

	for(i = 0; i < linhas; i++){
		p[i] = malloc(sizeof(float)*(colunas+1));
	}
	

	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas + 1; j++){
			printf("P[%d][%d] = ", i,j);
			scanf("%f", &p[i][j]);

		}
	}

	
	//calculating result vvvv
	gauss_jordan(p, linhas, colunas);
	
	for(i = 0; i < linhas; i++){
		printf("|\t%g\t|\n", p[colunas][i]);
	}

	//dealocating memory
	for(int i = 0; i < linhas; i++){
		free(p[i]);
	}
	free(p);
	
	return 0;
}
