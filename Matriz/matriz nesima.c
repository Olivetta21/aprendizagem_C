#include <stdio.h>

int main(){
	int linha, coluna;
	printf("Quantidades de linhas: ");
	scanf("%d", &linha);
		linha--;
	printf("Quantidades de colunas: ");
	scanf("%d", &coluna);

	int matriz[linha+1][coluna+1], i, j, k, l, m, anuz;

	for (i=0; i<=(linha); i++){
		for (j=0; j<=(coluna); j++){
			if(j<coluna){
				printf("%d-%d-Numero: ", i,j);
				scanf("%d", &k);
				matriz[i][j]=k;
			}
			else{
				for(m=0, l=1; m<coluna; m++){
					l = (matriz[i][m])*l;

				}
				matriz[i][j]=l;
			}
		}
	}
	for (i=0; i<=(linha); i++){
		for (j=0; j<=(coluna); j++){
			if(j<coluna){
			printf("|%d|\t", matriz[i][j]);
			}
			else{
				printf("=\t|%d|\t", matriz[i][j]);
			}
		}
		printf("\n-------------------------------------------\n");
	}
	do{
		printf("\n\n\n\n");
		scanf("%d", &anuz);
	}while(anuz>0);
}
