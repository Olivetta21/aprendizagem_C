#include <stdio.h>

int main() {
    float _x, _x2, _cima, _baixo, _res;
    printf("De: ");
    scanf("%f", &_x);
    printf("A: ");
    scanf("%f", &_x2);
    while (_x <= _x2){
        //_cima = (_x*_x);
        //_baixo = (_x * _x) -25;
        //_res = _cima;
        if (_x <= 0){
            printf("\n\nX:%g Y=%g", _x, (-3*_x)+3);
            //printf("\n\nPara X: %g\nResultado: %g", _x, _res);
            //printf(" E 0");
        }
        else {
            if (_x>0 && _x<=1){
                printf("\n\nX:%g Y=%g", _x, (-_x)+3);
                //printf("\n\nPara X: %g, Nao funciona: %g", _x, _res);
                }
            else{
                if (_x>1 && _x<=2){
                    printf("\n\nX:%g Y=%g", _x, _x+1);
                }
                else {
                    printf("\n\nX:%g Y=%g", _x, (3*_x)-3);
                }
                //printf("\n\nPara X: %g, Inexistente", _x);
            }
        }
        _x ++;
    }
}
