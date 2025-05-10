#include <stdio.h>
#define t 15

void main(){
	int _matrizP[t][t], _matrizS[t][t];

	for (int i=0, x=1; i<t; i++){
		for (int j=0; j<t; j++){
			_matrizP[i][j]=x;
			x++;
			_matrizS[i][j]=0;
		}
	}



	printf("\n\n\n");
	for (int i=0, u=1; i<t-1; i++){
		for (int j=u; j<t; j++){
			_matrizS[i][j]=_matrizP[i][j];
		}
		u++;
	}

	for (int i=0; i<t; i++){
		_matrizS[i][i]=_matrizP[i][i]*100;
	}

	for (int i=1, u=1; i<t; i++){
		for (int j=0; j<u; j++){
			_matrizS[i][j]=_matrizP[i][j]*-1;
		}
		u++;
	}











	printf("\n\n\n");
	for (int i=0; i<t; i++){
		for (int j=0; j<t; j++){
			printf("|%d|\t", _matrizS[i][j]);
		}

		printf("\n");
	}

	#include <stdio.h>

    printf("\2588[2J");  // Limpa a tela
    printf("\033[H");   // Move o cursor para a posição inicial (canto superior esquerdo)



}
