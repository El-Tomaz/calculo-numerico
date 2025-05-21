#ifndef CALCULO_NUMERICO 
#define CALCULO_NUMERICO



void gauss_jordan(float **p, int lin, int col){
	
	//escalona cada coluna
	for(int i = 0; i < col; i ++){
		
		//divir a linha pelo elemento da diagonal principal
		for(int j = 0; j < lin + 1; j++){
			p[i][j] = p[i][j]/p[i][i];
		}
		
		//zerar elementos que não estejam na diagonal principal
		for(int j = 0; j < lin; j++){
			if(j == i) continue;
			
			for(int k = 0; k < col + 1; k++){
				p[j][k] = p[j][k] - p[i][k]*p[j][i];
			}

		}
	

	}
}










#endif 
