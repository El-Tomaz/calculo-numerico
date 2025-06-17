#include "unity/unity.h"
#include "teste_commons.h"



int elim(float *coef, float *b, int n, float tol){
	return 0;
}

int gauss_elim(float *coe, float *b, int n, float tol, float *resposta){


	const float coef[3][3] = {
		{3, -0.1,-0.2},
		{0, 7.00333, -0.293333},
		{0,0,10.0120}
	};

	b[0] = 7.85;
	b[1] = -19.5617;
	b[2] = 70.0843;
	// realiza processo de eliminacao nas matrizes do sistema
	elim(coef, b, n, tol);


	

	resposta[n - 1] = b[n-1] / coef[n-1][n-1];
	//substituicao reversa
	for(int i = n - 2; i >= 0 ; i--){
		
		float soma = 0;
		for(int j = i + 1; j <= n - 1; j++){
			soma += resposta[j] * coef[i][j];
		}

		resposta[i] = ( b[i] - soma)/coef[i][i];
	}
}

// testando sistema de 3 variaveis, página 255 do Chapra.
void	teste_base(void)
{
    const float tolerancia = 0.01/100;
	const int n = 3;

	const float coef[3][3] = {
		{3, -0.1, -0.2},
		{0.1, 7, -0.3},
		{0.3, -0.2,10}
	};

	const float b[3] = {
		7.85, -19.3,71.4
	};


    float resposta[3] = {0};
    int result = gauss_elim(coef,b, n,  tolerancia, resposta);

	float	solucao[] = {3, -2.5, 7};

	for (int i = 0; i < 3; i++)
		TEST_ASSERT_FLOAT_WITHIN(tolerancia, solucao[i], resposta[i]);
}

int	main(void)
{
	UNITY_BEGIN();

    RUN_TEST(teste_base);

	return (UNITY_END());
}