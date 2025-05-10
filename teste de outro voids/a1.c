#include <stdio.h>
//variaveis para convers�o de polegadas para cm(_polemcm), e calcular a altura(_X):
float _polemcm, _X;
//variaveis exclusivamente para calcular a raiz quadrada aproximada:
float _res = 0, _testar=0, _maxres=0, _minres=0, _testeparar, _resfinal=0;
//variavel para controlar quando a raiz quadrada � suficientemente proxima do resultado esperado:
int _ok=0, _podecalcular=0, _podetestar = 1;
//variaveis que ira fazer o calculo da raiz quadrada aproximada parar, no caso de looping infinito:
float _bk01a=1, _bk02a=1, _bk03a=1, _bk01=1, _bk02=2, _bk03=3, _somatorioBKUPS=0, _bkupres=0;

void testerespostaraiz(){
    printf("\n-----\nvoid testerespostaraiz\n-----\n");
    /*if (_podetestar == 1){
        printf("\n-----\nif testerespostaraiz\n-----\n");
        _testar = _res * _res;
        _podetestar = 0;
        _podecalcular = 1;
    }*/
}

void calcularraiz(){
    printf("\n-----\nvoid calcularraiz\n-----\n");
    if (_podecalcular == 1){
        printf("\n-----\nif calcularraiz\n-----\n");
        if (_testar>_X){
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
            if (_testar<_X){
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
                if (_testar==_X){
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
        _podetestar = 1;
    }
}

void main(){
    printf("Polegadas: ");
    scanf("%f", &_polemcm);
    //converter polegadas digitado pelo usuario em cm:
    _polemcm *= 2.54;
    //usando o teorema de pitagoras, _polemcm elevado ao quadrado, dividido pela soma dos quadrados das dimensoes da tela (16:9),
    //o resultado correspondera ao "X", que sera substituido na express�o(no final de tudo): altura=9*_X e comprimento=16*_X.
    _X = (_polemcm * _polemcm)/337;
    _podecalcular = 1;
    //o resultado anterior de "_X", o "x" na verdade e _X ao quadrado. Se esta elevando, entao passa para o outro lado como raiz.
    //por isso o codigo abaixo ira calcular a raiz aproximada de "_X":
    _testerespostaraiz();
    //_calcularraiz();

    while (_ok == 0){

        if (_bk01a == 1){
            _bk01 = (float)((int)(_bkupres*10000))/10000;
            _bk01a = 0;
            _bk02a = 1;
            _bk03a = 0;
        }
        else{
            if (_bk02a == 1){
                _bk02 = (float)((int)(_bkupres*10000))/10000;
                _bk01a = 0;
                _bk02a = 0;
                _bk03a = 1;
            }
            else{
                if (_bk03a == 1){
                    _bk03 = (float)((int)(_bkupres*10000))/10000;
                    _bk01a = 1;
                    _bk02a = 0;
                    _bk03a = 0;
                }
            }
        }
        _somatorioBKUPS = (float)((int)(((_bk01+_bk02+_bk03)/3)*10000))/10000;
        if (_somatorioBKUPS == (_bk01 && _bk03 && _bk03)){
            _resfinal = _bkupres;
            _ok = 1;
            printf("Utilizou o backup\n\n");
        }
        if (_testar > _X){
            _testeparar = _testar - 0.001;
            if (_X > _testeparar){
                _resfinal = _bkupres;
                _ok = 1;
            }
        }
        else{
            if (_testar < _X){
                _testeparar = _testar + 0.001;
                if (_X < _testeparar){
                    _resfinal = _bkupres;
                    _ok = 1;
                }
            }
        }
    }
    _X = _resfinal;
    printf("\nAltura aproximada em cm: %.2f\nComprimento aproximado em cm: %.2f\n\n----------------------\n", _X*9, _X*16);
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
