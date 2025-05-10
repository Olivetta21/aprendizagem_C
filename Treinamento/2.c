/*
Faça um programa para ler uma matriz 5x5 de números inteiros. A seguir, o
programa deve calcular e mostrar a soma dos elementos da diagonal principal.
Exemplo para uma matriz de ordem 4 (apenas uma exemplo!!!).
*/
#include <stdio.h>
#define tam 3

void main(){
	int _matriz[tam][tam], _sDiagPrin=0, _sDiagSec=0;

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

	//soma das diags.
	for (int i=0; i<tam; i++){
		_sDiagPrin+= _matriz[i][i];
		_sDiagSec+= _matriz[i][tam-1-i];
	}

	//mostrar a matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			printf("%d\t", _matriz[i][j]);
		}
		printf("\n");
	}


	//mostrar o resultado.
	printf("Diagonal principal: %d\nDiagonal Secundaria: %d", _sDiagPrin, _sDiagSec);
}
