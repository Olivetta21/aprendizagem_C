/*
Faça um programa para ler uma matriz 5x5 de números inteiros e verificar se a soma
da diagonal principal é igual ou não a soma da diagonal secundária.
*/
#include <stdio.h>
#define tam 3

void main(){
	int _matriz[tam][tam], _sumPrin=0, _sumSec=0;

	//resetar matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			_matriz[i][j]= 0;
		}
	}

	//leitura da matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			printf("[%d][%d]: ", i+1,j+1);
			scanf("%d", &_matriz[i][j]);
		}
	}

	//fazer a soma da vertical principal e secundaria.
	for (int i=0; i<tam; i++){
		_sumPrin+= _matriz[i][i];
		_sumSec+= _matriz[i][tam-1-i];
	}

	//mostrar matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			printf("%d\t", _matriz[i][j]);
		}
		printf("\n");
	}

	if (_sumPrin == _sumSec) printf("\nAs verticais sao iguais\n");
	else printf("\nAs verticais nao sao iguais\n");
}
