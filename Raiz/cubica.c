#include<stdio.h>
void main(){
    float _permitir=0, _tester, _RCde = 7, _res = 0, _minres = 0, _maxres = 0, _resfinal;
    float _bk01a=1, _bk02a=1, _bk03a=1, _bk01=1, _bk02=2, _bk03=3, _somatorioBKUPS=0, _bkupres=0;
    while (_permitir == 0){
        printf("Resultado: %f\n", _res);
        //O numero elevado a: 3
        _tester = _res * _res * _res;
        printf("Tester: %f\n", _tester);
        //Se o numero elevado a: 3, for maior que: 10
        if (_tester>_RCde){
            _maxres = _res;
            if (_minres==0){
                _bkupres = _res;
                _res = _res-1;
            }
            else{
                _bkupres = _res;
                _res = (_minres + _maxres)/2;
            }
        }



        else{
            //Se o numero elevado a: 3, for menor que: 10
            if (_tester<_RCde){
                _minres = _res;
                if (_maxres==0){
                    _bkupres = _res;
                    _res = _res+1;
                }
                else{
                    _bkupres = _res;
                    _res = (_minres + _maxres)/2;
                }
            }




            else{
                //Se o numero elevado a: 3, for igual a: 10
                if (_tester==_RCde){
                    printf("\n\nAQUI: %f\n\n", _res);
                    //break;
                }
                else{
                    //se nao for igual, menor ou maior, deu algum erro
                    printf("\n\n\nErro\n\n\n");
                    //break;
                }
            }
        }
        if (_bk01a == 1){
            _bk01 = _bkupres;
            _bk01a = 0;
            _bk02a = 1;
            _bk03a = 0;
        }
        else{
            if (_bk02a == 1){
                _bk02 = _bkupres;
                _bk01a = 0;
                _bk02a = 0;
                _bk03a = 1;
            }
            else{
                if (_bk03a == 1){
                    _bk03 = _bkupres;
                    _bk01a = 1;
                    _bk02a = 0;
                    _bk03a = 0;
                }
            }
        }
        printf("\nBK1: %f\nBK2: %f\nBK3: %f\n", _bk01, _bk02, _bk03);
        _somatorioBKUPS = (_bk01+_bk02+_bk03)/3;
        printf("\nSomattttt: %f", _somatorioBKUPS);
        printf("\n\n\n\n!!!\nbk1: %f\nbk2: %f\nbk3: %f\nSomat: %f\n!!!\n\n\n\n", _bk01, _bk02, _bk03, _somatorioBKUPS);
        _somatorioBKUPS = (float)((int)(_somatorioBKUPS*10000))/10000;
        _bk01 = (float)((int)(_bk01*10000))/10000;
        _bk02 = (float)((int)(_bk02*10000))/10000;
        _bk03 = (float)((int)(_bk03*10000))/10000;
        if (_somatorioBKUPS == _bk01 && _somatorioBKUPS == _bk03 && _somatorioBKUPS == _bk03){
            _resfinal = _bkupres;
            _permitir = 1;
            printf("Utilizou o backup\n\n");
        }
    }
    printf("RESFINAL: %f", _resfinal);
}
