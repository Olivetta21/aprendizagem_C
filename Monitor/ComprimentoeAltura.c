#include <stdio.h>
    //variaveis para convers�o de polegadas para cm(_polemcm), e calcular a altura(_X):
    float _polemcm;
    //variaveis exclusivamente para calcular a raiz quadrada aproximada:
    float _n = 2, _c;
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
	_v0_umSobren = 1 / _n;
	_v1_nMenUm = _n - 1;

	while(1){
		printf("Polegadas: ");
		scanf("%f'^\n'", &_polemcm);

		if(_polemcm >= 0){
		//converter polegadas digitado pelo usuario em cm:
		_polemcm *= 2.54;
		//usando o teorema de pitagoras, _polemcm elevado ao quadrado, dividido pela soma dos quadrados das dimensoes da tela (16:9),
		//o resultado correspondera ao "X", que sera substituido na express�o(no final de tudo): altura=9*_X e comprimento=16*_X.
		_c = (_polemcm * _polemcm)/337;

		//o resultado anterior de "_X", o "x" na verdade e _X ao quadrado. Se esta elevando, entao passa para o outro lado como raiz.
		//por isso o codigo abaixo ira calcular a raiz aproximada de "_X":
		for(_p=1;_testeResposta!=_c && _p <= 10;_p++){
			_v2_nMenUmVezX = _v1_nMenUm * _x;
			potenciacao();
			_v3_xElevAnMenUm = _resPotenciacao;
			_v4_CDivPorxElevAnMenUm = _c / _v3_xElevAnMenUm;
			_v5_nMenUmVezXMaisCDivPorxElevAnMenUm = _v2_nMenUmVezX + _v4_CDivPorxElevAnMenUm;
			_x = _v0_umSobren * _v5_nMenUmVezXMaisCDivPorxElevAnMenUm;
		}

		printf("\nAltura aproximada em cm: %.2f\nComprimento aproximado em cm: %.2f\n\n----------------------\n", _x*9, _x*16);
		}
		else{
			if(_polemcm < 0){
				printf("\n---Fechando programa---\n");
				break;
			}
			else{
				if ((char)_polemcm){
					printf("\n---Erro22!---\n");
					_polemcm = 0;
				}
			}
		}
		while ((_polemcm = getchar()) != '\n' && _polemcm != EOF);
	}
}
/*
Este c�digo � um programa em linguagem C que calcula a altura e comprimento de uma tela com
base na sua diagonal em polegadas, que � fornecida pelo usu�rio atrav�s do comando scanf. O programa
utiliza uma f�rmula matem�tica para calcular o valor da diagonal em cent�metros e em seguida, aplica
uma s�rie de c�lculos e verifica��es para encontrar os valores aproximados de altura e comprimento da tela.

O programa utiliza vari�veis float para armazenar valores num�ricos e utiliza algumas vari�veis de
controle para gerenciar o fluxo do programa, como por exemplo, _ok que controla o loop principal do programa.

O programa utiliza um loop while para verificar se o resultado do c�lculo da altura est� dentro de uma
faixa de erro aceit�vel em rela��o ao valor fornecido pelo usu�rio. O programa utiliza a t�cnica de bissec��o
para encontrar o valor aproximado da altura, que � armazenado na vari�vel _resfinal. O programa tamb�m utiliza
algumas vari�veis de backup (_bk01, _bk02 e _bk03) para armazenar valores anteriores de _res e utiliza uma
m�dia dos valores de backup para verificar se houve converg�ncia no c�lculo.

O programa finalmente imprime os valores aproximados da altura e comprimento em cent�metros, que s�o calculados
com base no valor aproximado da altura encontrado anteriormente. O programa tamb�m imprime uma mensagem de erro
caso algo inesperado aconte�a durante a execu��o.
*/
