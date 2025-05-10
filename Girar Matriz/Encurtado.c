#include <stdio.h>
#define t 7

void main(){
	int _matA[t][t], _matB[t][t],i ,j;
	float u,v;

	//Definir numeros da matriz principal.
	for (i=0, u=1; i<t; i++){
		for (j=0; j<t; j++){
			_matA[i][j]= u;
			u++;
			_matB[i][j]=0;
		}
	}

	//Girar os numeros da matriz no sentido horario.
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



	//Mostrar matriz principal.
	for (i=0; i<t; i++){
		for (j=0; j<t; j++){
			printf("%d\t", _matA[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n\n\n");
	//Mostrar a matriz depois de girada.
	for (i=0; i<t; i++){
		for (j=0; j<t; j++){
			printf("%d\t", _matB[i][j]);
		}
		printf("\n\n");
	}

}
