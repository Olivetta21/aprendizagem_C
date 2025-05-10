#include <stdio.h>
#define tam 7
void main(){
	int _matriz[tam][2][3];
	for (int i=0; i<tam; i++){
		for (int j=0; j<2; j++){
			for (int k=0; k<3; k++){
				_matriz[i][j][k] = 0;}}}
	for (int i=0; i<tam; i++){
		printf("Numero: ");
		scanf("%d", &_matriz[i][0][0]);}
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			if (_matriz[i][0][0] <= _matriz[j][0][0]){
				_matriz[i][1][0]++;}}
		_matriz[i][1][0]--;}
	for (int i=0; i<tam; i++){
		if (_matriz[(_matriz[i][1][0])][0][1] == 0){
			_matriz[(_matriz[i][1][0])][0][1] = 1;
			_matriz[(_matriz[i][1][0])][1][1] = _matriz[i][0][0];}
		else{
			for (int j=1; j != 0;){
				if (_matriz[(_matriz[i][1][0])-j][0][1] == 0){
					_matriz[(_matriz[i][1][0])-j][0][1] = 1;
					_matriz[(_matriz[i][1][0])-j][1][1] = _matriz[i][0][0];
					j=0;				}
				else j++;}}}
	for (int i=0; i<tam; i++){
		_matriz[i][0][2] = _matriz[tam-1-i][1][1];
		_matriz[i][1][2] = _matriz[i][1][1];}
	int _cORd, r;
	do{
		do{
			printf("Crescente:0 / Decrescente:1\n\t: ");
			scanf("%d", &_cORd);
		}while (_cORd != 0 && _cORd != 1);
		for (int i=0; i<tam; i++){
			printf("-->\t%d\n", _matriz[i][_cORd][2]);}
		do{
			printf("\n\nRepetir = 1\nSair = 0\n\t: ");
			scanf("%d", &r);
		} while (r!=0 && r!=1);
	}while (r==1);}
