#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define t 50

void main(){
	double _X=0,_Y=0, _velocidade=0.5;
	float _paint[t][8], _erroDec=0.00001;
	int _radar[t][t], _parar=10000, _control=1, _tMenUm=t-1, _meio=_tMenUm/2;


	do{
	////////////////////////////INICIO MODULO 1////////////////////////////
		if (_control==1){
			if (_X+_velocidade >= _tMenUm){
				_X = _tMenUm;
				_control = 2;
			}
			else _X = _X + _velocidade;
		}
		else if (_control==2){
			if (_Y+_velocidade >= _tMenUm){
				_Y = _tMenUm;
				_control = 3;
			}
			else _Y = _Y + _velocidade;
		}
		else if (_control==3){
			if (_X-_velocidade <= 0){
				_X = 0;
				_control = 4;
			}
			else _X = _X - _velocidade;
		}
		else if (_control==4){
			if (_Y-_velocidade <= 0){
				_Y = 0;
				_control = 1;
			}
			else _Y = _Y - _velocidade;
		}
		/*///////////////////////////FIM MODULO 1////////////////////////////
		*	Responsavel por "fazer a volta" em torno do quadrado. Se o quadrado mede 15x15
		*	entao os lados vao de 0 a 14, o que totaliza em 15.
		*/



		////////////////////////////INICIO MODULO 2////////////////////////////
		for (int i=0; i<t; i++){
			for (int j=0; j<t; j++){
				_radar[i][j]=0;
			}

			_paint[i][0]=0;
			_paint[i][4]=0;
			if (i <= _meio){
				_paint[i][1]=0;
				_paint[i][2]=0;
				_paint[i][3]=t-(i*2);

				_paint[i][5]=0;
				_paint[i][6]=0;
				_paint[i][7]=t-(i*2);
			}
			else{
				_paint[i][1]=t;
				_paint[i][2]=t;
				_paint[i][3]=(t-((_meio-(i-_meio))*2));

				_paint[i][5]=t;
				_paint[i][6]=t;
				_paint[i][7]=(t-((_meio-(i-_meio))*2));
			}
		}
		/*///////////////////////////FIM MODULO 2////////////////////////////
		*	Isso ira resetar o radar e definir os valores da tabela de comparacao para cada
		*	linha e coluna.
		*
		*	TABELA DE COMPARACAO _paint:
		*	Piramides CIMA e BAIXO
		*	[i][0] isso vai interferir diretamente na hora de pintar o ponteiro do radar, eh
		*	       ele que vai definir onde pode pintar e onde nao pode na determinada linha.
		*	[i][1] ponto minimo, em que o X deve ser maior ou igual.
		*	[i][2] ponto maximo, em que o X deve ser menor.
		*	[i][3] tamanho da linha, e esse valor eh imutavel.
		*
		*	Piramides ESQUERDA e DIREITA
		*	[i][4] isso vai interferir diretamente na hora de pintar o ponteiro do radar, eh
		*	       ele que vai definir onde pode pintar e onde nao pode na determinada coluna.
		*	[i][5] ponto minimo, em que o Y deve ser maior ou igual.
		*	[i][6] ponto maximo, em que o Y deve ser menor.
		*	[i][7] tamanho da coluna, e esse valor eh imutavel.
		*/






		////////////////////////////INICIO MODULO 3////////////////////////////
		for (int i=0; i<t;){
			//CIMA
			if (i<_meio && _Y==0){
				_paint[i][2]=_paint[i][2]+((float)t/_paint[i][3]);
				if (_X >= _paint[i][1] && _X < _paint[i][2]){
					_radar[i][i+(int)_paint[i][0]] = 1;
					i++;
				}
				else {
					_radar[i][i+(int)_paint[i][0]] = 0;
					if (_paint[i][0]+1 < t) _paint[i][0]++;
					_paint[i][1]=_paint[i][2];
				}
			}


			//DIREITA
			else if (i>_meio && _X==_tMenUm){
				_paint[i][5]=_paint[i][5]-((float)t/_paint[i][7]);
				if (_Y >= _paint[i][5]-_erroDec && _Y < _paint[i][6]+_erroDec){
					_radar[i-(int)_paint[i][4]][i] = 1;
					i++;
				}
				else {
					_radar[i-(int)_paint[i][4]][i] = 0;
					if (_paint[i][4]+1 < t) _paint[i][4]++;
					_paint[i][6]=_paint[i][5];
				}
			}


			//BAIXO
			else if (i>_meio && _Y==_tMenUm){
				_paint[i][1]=_paint[i][1]-((float)t/_paint[i][3]);
				if (_X >= _paint[i][1]-_erroDec && _X < _paint[i][2]+_erroDec){
					_radar[i][i-(int)_paint[i][0]] = 1;
					i++;
				}
				else {
					_radar[i][i-(int)_paint[i][0]] = 0;
					if (_paint[i][0]+1 < t) _paint[i][0]++;
					_paint[i][2]=_paint[i][1];
				}
			}


			//ESQUERDA
			else if (i<_meio && _X==0){
				_paint[i][6]=_paint[i][6]+((float)t/_paint[i][7]);
				if (_Y >= _paint[i][5] && _Y < _paint[i][6]){
					_radar[i+(int)_paint[i][4]][i] = 1;
					i++;
				}
				else {
					_radar[i+(int)_paint[i][4]][i] = 0;
					if (_paint[i][4]+1 < t) _paint[i][4]++;
					_paint[i][5]=_paint[i][6];
				}
			}


			else{
				if (i==_meio) _radar[i][i]=2;
				i++;
			}
		}
		/*///////////////////////////FIM MODULO 3////////////////////////////
		*	Eh aqui que o ponteiro inteiro sera pintado, de "ponto-em-ponto". A pintura
		*	eh dividida em quatro partes, imagine um quadrado com duas linhas de uma
		*	ponta a outra formando duas linhas diagonais, isso formou quatro piramides, eh
		*	atraves disso que o ponteiro sera pintado.
		*	Primeiro movendo o ponteiro na piramide de cima, depois direita, depois baixo,
		*	depois esquerda e entao volta na de cima e continua o loop.
		*
		*	A LOGICA:
		*	Cada linha e coluna tem um tamanho, entao vai pegar o tamanho do radar(aqui
		*	representado por "t") e dividir pelo tamanho da linha ou coluna, o resultado sera
		*	basicamente as sessoes onde o ponteiro sera pintado de acordo com qual sessao
		*	o X ou Y estiver.
		*
		*	Por exemplo: um radar de 25x25, na ultima(da piramide de cima) linha(11) sera
		*	25(t)/3(a linha 11 na piramide mede 3) = 8.33, significa que esssa linha tera
		*	tres sessoes e cada uma de tamanho de 8.33, entao quando o X estiver entre
		*	0 e 8.33 pintara o primeiro "bloco" dessa linha, se estiver entre 8.33 e 16.66
		*	pintara o segundo "bloco", e se estiver entre 16.66 e 25 pintara o terceiro.
		*	Ja na primeira linha, ela tera um tamanho de 25, entao 25(t)/25=1, significa
		*	que a primeira linha tera 25 sessoes e cada um de tamanho 1, entao se o X
		*	estiver entre 0 e 1 vai pintar o primeiro "bloco" dessa linha e assim se
		*	repete para todas as linha e colunas, o que vai mudar eh somente o calculo de
		*	cada piramide, mas a ideia eh a mesma para todas.
		*/




		////////////////////////////INICIO MODULO 4////////////////////////////
		system("cls");
		for (int i=0; i<t; i++){
			for (int j=0; j<t; j++){
				if (_radar[i][j] == 1) printf(" O");
				else if (_radar[i][j] == 2) printf(" @");
				else printf(" .");
			}
			printf("\n");
		}
		_parar--;
		printf("X:%f\nY:%f\nParar:%d\n", _X,_Y,_parar);
        Sleep(50);
		/*///////////////////////////FIM MODULO 4////////////////////////////
		*	Aqui vai mostrar o radar, substituindo os numeros por simbolos, para
		*	dar um estilo, alem de mostrar o X, Y e quando o programa vai parar.
		*/




	}while (_parar>0);
}
