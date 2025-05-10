#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define t 25

void main(){
    int i,j, _matA[t][t], _matB[t][t], _matBK[t][t], _rodar=0;
    float u,v;

	for (i=0, u=1; i<t; i++){
		for (j=0; j<t; j++){
            if (i==j) _matA[i][j]= 1;
            else if (t-1-i == j) _matA[i][j]= 1;
            else _matA[i][j]=0;
			u++;
			_matB[i][j]=_matA[i][j];
			_matBK[i][j]=_matA[i][j];
		}
	}

	do{

        for (i=0; i<t; i++){
            for (j=0; j<t; j++){
                if (_matB[i][j] == 0) printf(" \t");
                else printf("@\t");
            }
            printf("\n\n\n");
        }

        if (_rodar > 0) Sleep(250);

        for (i=0, u=0, v=0; i<t; i++){
            if (i < t/2){
                for (j=0; j<t; j++){
                    if (j <= u) _matB[i][j]=_matA[i+1][j];
                    else if (j<=t-1-v) _matB[i][j]=_matA[i][j-1];
                    else _matB[i][j]=_matA[i-1][j];}
                if (u<((float)t/2)-1) u++;
                if (v<((float)t/2)) v++;}
            else{
                u--;
                if ((i + ((float)t/2) > (float)t-1) && (i - ((float)t/2) < 0)){
                    for (j=0; j<t; j++){
                        if (j <= u) _matB[i][j]=_matA[i+1][j];
                        else if (j <= t-1-v) _matB[i][j]=_matA[i][j];
                        else _matB[i][j]=_matA[i-1][j];}}
                else {
                    for (j=0; j<t; j++){
                        if (j <= u) _matB[i][j]=_matA[i+1][j];
                        else if (j <= t-1-v) _matB[i][j]=_matA[i][j+1];
                        else _matB[i][j]=_matA[i-1][j];}
                    v--;}}}

        for (i=0; i<t; i++){
            for (j=0; j<t; j++){
                _matA[i][j]=_matB[i][j];
            }
        }

        if (_rodar <= 0){
            printf("\nRodar: ");
            scanf("%d", &_rodar);
        }

        _rodar--;

        system("cls");

	}while (_rodar > -1);

	printf("\n\n\n\n\nFechando....\n\n\n\n\n\n");
}
