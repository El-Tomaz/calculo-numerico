#include "unity/unity.h"
#include <stdio.h>
#include <math.h>


void	setUp(void)
{
}
void	tearDown(void)
{
}


int gauss_jordan(float *sistema[], float tolerancia){



}

// sistema pegado de CHAPRA p. 241
void	test_base(void)
{
	float	sistema[3][4] = {
        {   3,     -0.1,   0.2,    7.85    }, 
        {   0.1,   7,      -0.3,   -19.3   }, 
        {   0.3,   -0.2,   10.71,  4       }
    };

    float tolerancia = 0.000001;
	// (matriz expandida)
	gauss_jordan(sistema, tolerancia);


    float resultado[3];

    //pegando a ultima coluna de cada linha
    for(int i = 0; i < 3; i++){
        resultado[i] = sistema[i][3];
    }

    float resultado_esperado[] = {3, -2.5, 7};

    for(int i = 0; i < 3; i++){
        TEST_ASSERT_FLOAT_WITHIN(tolerancia, resultado_esperado[i], resultado[i]);
    }
}

void teste_singularidade(void){

}

int	main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_base);
	return (UNITY_END());
}