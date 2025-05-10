#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int max = 10;
int _d, _e;
char _key;

void dir(){
	for(int i=1; i<=_d; i++){
		printf("-");
	}
}
void esq(){
	for(int i=1; i<=_e; i++){
		printf("-");
	}
}
void quadro(){
	for(int i=1; i<=5; i++){
		printf("\n|                     |");
	}
}

int main(){
	_d = max;
	_e = max;
	printf("_______________________");
	quadro();
	printf("\n");
	printf("|");
	esq();
	printf("O");
	dir();
	printf("|");
	for(int i=1; i<1000; i++){
		_key = getch();
		if(_key == 'd'){
			if (_d>0){
				_e++;
				_d--;
			}
			else{
				_d = max*2;
				_e = 0;
			}

		}
		else{if(_key == 'a'){
				if (_e>0){
					_e--;
					_d++;
				}
				else{
					_d = 0;
					_e = max*2;
				}
			}
			else{_e=max;_d=max;
			}
		}
		system("cls");
		printf("_______________________");
		quadro();
		printf("\n");
		printf("|");
		esq();
		printf("O");
		dir();
		printf("|");
	}
}
