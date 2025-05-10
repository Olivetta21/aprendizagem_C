#include <stdio.h>
void main()
{
	//variaveis para convers�o de polegadas para cm(_polemcm), e calcular a altura(_X):
	float _polemcm, _X;
	//variaveis exclusivamente para calcular a raiz quadrada aproximada:
	float _res = 0, _testar = 0, _maxres = 0, _minres = 0, _testeparar, _resfinal = 0;
	//variavel para controlar quando a raiz quadrada � suficientemente proxima do resultado esperado:
	float _ok = 0;
	//variaveis que ira fazer o calculo da raiz quadrada aproximada parar, no caso de looping infinito:
	float _bk01a = 1, _bk02a = 1, _bk03a = 1, _bk01 = 1, _bk02 = 2, _bk03 = 3, _somatorioBKUPS = 0, _bkupres = 0, _n = 1;
	_X = 99999;

	while (_ok == 0){
		printf("\nvezes rodados: %.0f\n", _n);
		_n++;
		_testar = (float)((int)(_testar * 100000)) / 100000;
		_res = (float)((int)(_res * 100000)) / 100000;
		_bkupres = (float)((int)(_bkupres * 100000)) / 100000;
		_minres = (float)((int)(_minres * 100000)) / 100000;
		_maxres = (float)((int)(_maxres * 100000)) / 100000;
		_testar = _res * _res * _res;
		if (_testar > _X){
			_maxres = _res;
			if (_minres == 0){
				_bkupres = _res;
				_res = _res - 1;
			}
			else{
				_bkupres = _res;
				_res = (_minres + _maxres) / 2;
			}
		}
		else{
			//Se o numero elevado a: 3, for menor que: 10
			if (_testar < _X){
				_minres = _res;
				if (_maxres == 0){
					_bkupres = _res;
					_res = _res + 1;
				}
				else{
					_bkupres = _res;
					_res = (_minres + _maxres) / 2;
				}
			}
			else{
				//Se o numero elevado a: 3, for igual a: 10
				if (_testar >= 99998 && _testar <= 100000){
					_resfinal = _res;
					_ok = 1;
					printf("\n\nAQUI: %f\n\n", _res);
				}
				else{
					//se nao for igual, menor ou maior, deu algum erro
					printf("\n\n\nErro\n\n\n");
				}
			}
		}
		if (_bk01a == 1){
			_bk01 = (float)((int)(_bkupres * 100000)) / 100000;
			_bk01a = 0;
			_bk02a = 1;
			_bk03a = 0;
		}
		else{
			if (_bk02a == 1){
				_bk02 = (float)((int)(_bkupres * 100000)) / 100000;
				_bk01a = 0;
				_bk02a = 0;
				_bk03a = 1;
			}
			else{
				if (_bk03a == 1){
					_bk03 = (float)((int)(_bkupres * 100000)) / 100000;
					_bk01a = 1;
					_bk02a = 0;
					_bk03a = 0;
				}
			}
		}
		_somatorioBKUPS = (float)((int)(((_bk01 + _bk02 + _bk03) / 3) * 100000)) / 100000;
		if (_somatorioBKUPS == (_bk01 && _bk03 && _bk03)){
			_resfinal = _bkupres;
			_ok = 1;
			printf("Utilizou o backup\n\n");
		}
		if (_testar > _X){
			_testeparar = _testar - 0.0001;
			if (_X > _testeparar){
				_resfinal = _bkupres;
				_ok = 1;
			}
		}
		else{
			if (_testar < _X){
				_testeparar = _testar + 0.0001;
				if (_X < _testeparar){
					_resfinal = _bkupres;
					_ok = 1;
				}
			}
		}
    printf("%f", _res);
	}
	printf("X: %f", _resfinal);
}
