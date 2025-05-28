#include <stdio.h>
#include "../calculo_numerico.h"
#include <math.h>

float p(float x){
    return pow(x,2) - 1;
}

int main(){

    float xi, xf, tol;
    printf("Put interval xi\n:");
    scanf("%f", &xi);


    printf("Put interval xf\n:");
    scanf("%f", &xf);

    
    printf("Put tolerance\n:");
    scanf("%f", &tol);
    
 
    float x_root = bisection(xi, xf, p, tol);
    printf("root is: %f", x_root);

}

