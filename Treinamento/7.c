/*
Faça um programa para ler uma matriz A de ordem 5x5 de números inteiros e
verificar se a matriz é ou não simétrica. Dizemos que uma matriz é simétrica quando
todo elemento aij é igual ao elemento aji, para todo i, j ≤ 5. Exemplo para matriz
simétrica de ordem 4 (apenas um exemplo!!!):
*/
#include <stdio.h>
#define tam 10

void main(){
	int _matriz[tam][tam][2], _p=0;

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

	//Procurar i,j diferente de j,i. Sem a necessidade de procurar duas vezes no mesmo lugar.
	for (int i=0; i<(tam-1) && _p==0; i++){
		for (int j=i+1; j<tam && _p==0; j++){
			if (_matriz[i][j][0] != _matriz[j][i][0]){
				_p=1;
			}
			_matriz[i][j][1]= 1;
		}
	}

	//mostrar matriz.
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			printf("%d\t", _matriz[i][j][0]);
		}
		printf("\n");
	}

	printf("\n\n\n");
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (_matriz[i][j][1] == 0) printf("%d\t", _matriz[i][j][0]);
			else printf("@\t");
		}
		printf("\n");
	}

	if (_p==0) printf("\nA matriz e simetrica\n");
	else printf("\nA matriz nao e simetrica\n");
}
