#include "teste_commons.h"
#include "unity/unity.h"
#include <stdio.h>
#include <stdlib.h>

int	elim(float **coef, float *b, int n, float tol)
{
	float f = 0; // fator para multiplicar cada linha
	
	//iterando por cada coluna, da primeira ate a penultima
	for (int j = 0; j <= n - 2; j++)
	{	

		// iterando a partir da proxima linha
		for(int i = j + 1; i <= n - 1; i++){
			
			f = coef[i][j]/coef[j][j];
			coef[i][j] = 0;

			//subtraindo linha por linha (iterando as colunas)
			for(int k = j + 1; k <= n - 1;k++)
			coef[i][k] -= coef[j][k]*f;
			
			//subtraindo da matriz dos valores:
			b[i] -= b[j]*f;
		}
	}
	return (0);
}

int	gauss_elim(float **coef, float *b, int n, float tol, float *resposta)
{
	float soma = 0;

	// realiza processo de eliminacao nas matrizes do sistema
	elim(coef, b, n, tol);

	for(int i = 0; i < 3;i++){
		for(int j = 0; j < 3;j++){

			printf("%f\t", coef[i][j]);

		}	
		printf("\n\n");
	}
	resposta[n - 1] = b[n - 1] / coef[n - 1][n - 1];
	// substituicao reversa
	
	for (int i = n - 2; i >= 0; i--)
	{
		printf("\n%d",i);
		soma = 0;
		for (int j = i + 1; j <= n - 1; j++)
		{
			soma += resposta[j] * coef[i][j];
		}
		resposta[i] = (b[i] - soma) / coef[i][i];
	}
	return 0;
	
}

// testando sistema de 3 variaveis, página 255 do Chapra.
void	teste_base(void)
{
	const float	tolerancia = 0.01 / 100;
	const int	n = 3;

	float	coef[3][3] = {{3, -0.1, -0.2}, {0.1, 7, -0.3}, {0.3, -0.2, 10}};
	float	b[3] = {7.85, -19.3, 71.4};
	float		resposta[3] = {0};
	int			result = 0;
	float		solucao[] = {3, -2.5, 7};

	float **c = (float **)malloc(sizeof(float*)*n);

	for(int i = 0; i < n;i++){
		c[i] = (float *)malloc(sizeof(float)*n);
	}

	for(int i = 0; i < n;i++){
		for(int j = 0; j < n;j++){
			c[i][j] = coef[i][j];
		}
	}

	

	result = gauss_elim(c, b, n, tolerancia, resposta);
	for (int i = 0; i < 3; i++)
		TEST_ASSERT_FLOAT_WITHIN(tolerancia, solucao[i], resposta[i]);
}

int	main(void)
{
	UNITY_BEGIN();

	RUN_TEST(teste_base);

	return (UNITY_END());
}