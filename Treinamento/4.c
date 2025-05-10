/*
Faça um programa para ler uma matriz 5x5 de números inteiros e ler um número
inteiro x. A seguir, o programa deve multiplicar os elementos da segunda coluna da
matriz por x e exibir a matriz modificada.
*/
#include <stdio.h>
#define tam 3

void main(){
	int _matriz[tam][tam][2], _x;

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
			_matriz[i][j][1] = _matriz[i][j][0];
		}
	}

	//fazer a multiplicacao da secunda coluna por x.
	printf("Multiplicar por: ");
	scanf("%d", &_x);
	for (int i=0; i<tam; i++){
			_matriz[i][1][1] = _x * _matriz[i][1][0];
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
