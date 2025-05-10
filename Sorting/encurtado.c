#include <stdio.h>
void main(){
	int _max;
	printf("Tamanho do vetor: ");
	scanf("%d", &_max);
	int _nums[_max], _ordenado[_max], _posiOrdem[_max],_preenchido[_max];
	for (int i=0; i<_max; i++){
		_posiOrdem[i] = 0;
		_ordenado[i] = 0;
		_preenchido[i] = 0;}
	for (int i=0; i<_max; i++){
		for (int j=0; j<_max; j++){
			if (_nums[i] <= _nums[j]){
				_posiOrdem[i]++;}}
		_posiOrdem[i]--;}
	for (int i=0; i<_max; i++){
		if (_preenchido[_posiOrdem[i]] == 0){
			_preenchido[_posiOrdem[i]] = 1;
			_ordenado[_posiOrdem[i]] = _nums[i];}
		else{
			for (int descer=1; descer!=0;){
				if (_preenchido[_posiOrdem[i]-descer]==0){
					_preenchido[_posiOrdem[i]-descer] = 1;
					_ordenado[_posiOrdem[i]-descer] = _nums[i];
					descer=0;}
				else{
					descer++;}}}}
	int _cORd;
	printf("\nNumeros do usuario organizados:\n1 para crescente ou 2 para decrescente... ");
	scanf("%d", &_cORd);
	if (_cORd >= 2){
		for (int i=0; i<_max; i++){
		printf("-> %d\n", _ordenado[i]);}}
	else{
		for (int i=_max-1; i>=0; i--){
		printf("-> %d\n", _ordenado[i]);}}}