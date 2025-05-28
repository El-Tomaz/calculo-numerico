#ifndef CALCULO_NUMERICO 
#define CALCULO_NUMERICO
#include <stdio.h>
#include <math.h>

#define MAX_ITE 100 //max iterations 

void gauss_jordan(float **p, int lin, int col){
    printf("olha o jordan\n");
	//escalona cada coluna
	for(int i = 0; i < col; i ++){
		
		//divir a linha pelo elemento da diagonal principal
		for(int j = 0; j < col + 1; j++){
			p[i][j] = p[i][j]/p[i][i];
		}
	    printf("eita, deu bom!\n");

		//zerar elementos que não estejam na diagonal principal
		for(int j = 0; j < lin; j++){
			if(j == i) continue;
			
			for(int k = 0; k < col + 1; k++){
				p[j][k] = p[j][k] - p[i][k]*p[j][i];
            }

		}
	
    
			    if(i == 2)printf("nyaaa\n");
	}
}



float bisection(float xi, float xf, float (*f)(float), float tol){
    
    float xl = xi;
    float xu = xf;
    
    for(int i = 0; i < MAX_ITE; i++){
        
        float xr = (xu + xl)/2;
        printf("%f\n", xr); 
        
        if(fabs(f(xl)*f(xr)) < tol) return xr;
        
        if(f(xl)*f(xr) < 0) xu = xr;
        else if(f(xl)*f(xr) > 0) xl = xr;
    
    }

    printf("Error MAX ITERATIONS ACHIVIED");
}







#endif 
