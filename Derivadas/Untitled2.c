#include <stdio.h>
void main(){
    float _nDeriv, _X, _i;
    printf("Derivada de ordem: ");
    scanf("%f", & _nDeriv);
    for (_i = 1;_i<= _nDeriv;_i++){
        _X = (int) _i % 7;
        printf("\n%.0f:  %f = ",_i, _X);
        if (_X == 0){printf("sen");
        }
        else{if (_X == 1)printf("cos");
            else{if (_X == 2)printf("-sen");
                else{if (_X == 3)printf("-cos");
                }
            }
        }
        printf("x");
    }
}
