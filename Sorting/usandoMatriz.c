/*
Fazer um programa de ordenacao, usando matrizes
*/
#include <stdio.h>
#include <time.h>
#define tam 3000


void main(){
	//[000]:numero digitado, [010]:vezes menor/igual que os outros, [001]: se ja foi utilizado, [011]: ordenado
	int _matriz[tam][2][3];
	clock_t inicioX, fimX, inicioOrd, fimOrd;
	double _tempoX, _tempoOrd;

	//resetar matriz
	for (int i=0; i<tam; i++){
		for (int j=0; j<2; j++){
			for (int k=0; k<3; k++){
				_matriz[i][j][k] = 0;
			}
		}
	}

	//ler numeros do usuario.
	for (int i=0; i<tam; i++){
		printf("Numero: ");
		scanf("%d", &_matriz[i][0][0]);
	}

	inicioX = clock();
	//registrar vezes que x foi menor que todos os outros
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (_matriz[i][0][0] <= _matriz[j][0][0]){
				_matriz[i][1][0]++;    //se a posicao for menor/igual os outros numeros digitados, ir aidicionando 1.
			}
		}
		_matriz[i][1][0]--; //nao contar ele mesmo
	}
	fimX = clock();
	inicioOrd = clock();
	//formar a matriz ordenada
	for (int i=0; i<tam; i++){
		if (_matriz[(_matriz[i][1][0])][0][1] == 0){
			_matriz[(_matriz[i][1][0])][0][1] = 1;    //se a posicao ja nao tiver preenchido marcar como preemchida
			_matriz[(_matriz[i][1][0])][1][1] = _matriz[i][0][0]; //e definir essa posicao para o numero digitado
		}
		else{ //se a posicao ja estiver preenchida...
			for (int j=1; j != 0;){
				if (_matriz[(_matriz[i][1][0])-j][0][1] == 0){ //verificar se a posicao-j esta preenchida
					_matriz[(_matriz[i][1][0])-j][0][1] = 1; //se estiver vazia, marcar que foi preenchida
					_matriz[(_matriz[i][1][0]-j)][1][1] = _matriz[i][0][0]; // e definir para o numero digitado
					j=0;
				}
				else j++; //senao, aumentar o J e procurar posicoes anteriores ate achar uma casa vazia
			}
		}
	}

	//mostrar
	/*for (int i=0; i<2; i++){
		for (int j=0; j<tam; j++){
			for (int k=0; k<2; k++){
				printf("-%d:%d:%d  =  %d\t",j,k,i, _matriz[j][k][i]);
			}
			printf("\n");
		}
		printf("---------\n\n");
	}*/
	for (int i=0; i<tam; i++){
		_matriz[i][0][2] = _matriz[tam-1-i][1][1];
		_matriz[i][1][2] = _matriz[i][1][1];
	}
	fimOrd = clock();

	_tempoX = (double)(fimX - inicioX) / CLOCKS_PER_SEC;
	_tempoOrd = (double)(fimOrd - inicioOrd) / CLOCKS_PER_SEC;

	printf("\n\nX:%f\nOrd:%f\n\n", _tempoX, _tempoOrd);

	int _cORd, r;

	do{
		do{
			printf("Crescente:0 / Decrescente:1\n\t: ");
			scanf("%d", &_cORd);
		}while (_cORd != 0 && _cORd != 1);

		for (int i=0; i<tam; i++){
			printf("-->\t%d\n", _matriz[i][_cORd][2]);
		}

		do{
			printf("\n\nRepetir = 1\nSair = 0\n\t: ");
			scanf("%d", &r);
		} while (r!=0 && r!=1);
	}while (r==1);
}
