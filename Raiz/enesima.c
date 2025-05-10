#include <stdio.h>

float _n, _c;
float _x=1, _v0_umSobren, _v1_nMenUm, _v2_nMenUmVezX, _v3_xElevAnMenUm, _v4_CDivPorxElevAnMenUm, _v5_nMenUmVezXMaisCDivPorxElevAnMenUm, _testeResposta;

float _resPotenciacao;
int _i, _p;

void potenciacao(){//printf("\n--------------\n--------------\nVoid potenciacao\n");
	for(_i=1, _testeResposta=0, _resPotenciacao = 1;_i<=_n;_i++){
		if (_i<=_v1_nMenUm){
			_resPotenciacao = _resPotenciacao * _x;
		}
		else {
			_testeResposta = _resPotenciacao * _x;
		}
		//printf("\n_v1_nMenUm: %f", _v1_nMenUm);
		//printf("\n_resPotenciacao: %f", _resPotenciacao);
		//printf("\n_testeResposta: %f", _testeResposta);
	}
	//printf("\n\nVoid potenciacao\n--------------\n--------------");
}

void main(){
	printf("IndiceRaiz: ");
	scanf("%f", &_n);
	_v0_umSobren = 1 / _n;
	_v1_nMenUm = _n - 1;

	printf("RaizDe: ");
	scanf("%f", &_c);

	for(_p=1;_testeResposta!=_c && _p <= 10;_p++){
		_v2_nMenUmVezX = _v1_nMenUm * _x;
		potenciacao();
		_v3_xElevAnMenUm = _resPotenciacao;
		_v4_CDivPorxElevAnMenUm = _c / _v3_xElevAnMenUm;
		_v5_nMenUmVezXMaisCDivPorxElevAnMenUm = _v2_nMenUmVezX + _v4_CDivPorxElevAnMenUm;
		_x = _v0_umSobren * _v5_nMenUmVezXMaisCDivPorxElevAnMenUm;
	}
	printf("\n\n\n\n\n--------------Resposta: %f--------------\n\n\n\n\n\n", _x);
}
