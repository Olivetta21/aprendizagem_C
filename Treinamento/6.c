/*
Faça um programa para ler uma matriz 5x5 de inteiros e calcular a sua transposta
AT. Exemplo para matriz de ordem 4 (apenas um exemplo!!!):
*/
#include <stdio.h>
#define tam 3

void main(){
	int _matriz[tam][tam][2];

	//resetar matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			_matriz[i][j][0]= 0;
			_matriz[i][j][1]= 0;
		}
	}

	//leitura da matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			printf("[%d][%d]: ", i+1,j+1);
			scanf("%d", &_matriz[i][j][0]);
		}
	}

	//transpor a matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			_matriz[j][i][1] = _matriz[i][j][0];
		}
	}

	//mostrar matriz.
	for (int i=0; i<tam; i++){
		for (int m=0; m<=1; m++){
			for (int j=0; j<tam; j++){
				printf("%d\t", _matriz[i][j][m]);
			}
			printf("|\t");
		}
		if (i < (tam-1)) printf("\n\t\t\t|\t\t\t\t|\n\t\t\t|\t\t\t\t|\n");
	}
}
