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

	/*A logica: 
	1- Em um quadrado, sao formadas quatro piramides(desenhe um para melhor compreensao).
	2- Se o quadrado for impar, tera uma linha central onde	o meio nao tem como ser rotacionado, se for par, nao
	tera linha central.
	3- A rotacao em um quadrado tem quatro direcoes: ir para cima, ir para direita, ir para baixo, ir para esquerda... e
	volta no primeiro. Tendo isso em mente, e sabendo que um quadrado ha quatro piramides, basta fazer cada piramide exercer
	uma funcao. Entao: 
	piramide da esquerda("u")-> pegue o de baixo;
	piramide de cima(gerado automaticamente conforme a piramide "u" e "v" vao aumentando)-> pegue o da esquerda;
	piramide da direita("v")-> pegue o de cima;
	piramide de	baixo(gerado automaticamente conforme a	piramide "u" e "v" vao aumentando) -> pegue o da direita.
	4-Mas quando o quadrado eh impar, existe um ponto central, onde ele obviamente nao rotaciona, entao esse ponto nao
	pode fazer parte de nenhuma piramide.*/



	//Girar os numeros da matriz no sentido horario.
	for (i=0, u=0, v=0; i<t; i++){
		/*MODULO 1-------------------------------------------------------------------------------------------------------
		Usar esse modulo para todas as linhas que estiverem acima da linha central da matriz.*/
		if (i < t/2){
			for (j=0; j<t; j++){
				/*Nesse momento, o "u" representa o triangulo da esquerda, onde a casa da nova matriz deve ser a de baixo.
				A cada nova linha (enquando a linha estiver acima da linha central da matriz), o "u" aumenta 1 (mas nao
				pode aumentar ao ponto de chegar no meio da matriz --por isso a verificacao--.), formando uma piramide.
				Ou seja, se o "J"(coluna da atual linha) estiver dentro dessa piramide da esquerda, a casa da nova matriz
				sera o da posicao abaixo(na mesma coluna).*/
				if (j <= u) _matB[i][j]=_matA[i+1][j]; 
				
				/*No caso do "J"(coluna da atual linha) estiver fora da piramide da esquerda, mas estiver dentro da
				piramide de cima, a casa na nova matriz sera o da posicao da esquerda(na linha atual).
				Conforme o "u" aumenta a parte esquerda piramide de cima(a piramide de cima esta de ponta cabeca) vai
				chegando para direita, e conforme o "v"(o v representa a piramide da direita) aumenta (esses aumentos
				ocorrem a cada nova linha, --e so assim que as piramides vao criando forma--), a parte direita da piramide
				vai chegando para esquerda(isso faz a piramide de cima comecar com a base grande e ir diminuindo)*/
				else if (j<=t-1-v) _matB[i][j]=_matA[i][j-1];
				
				/*Por ultimo(lembrando que aqui vale somente para as linhas que estiverem acima da linha central da matriz),
				se o "J" nao estiver na piramide da esquerda, e nao estiver na piramide de cima, significa que ele esta na
				piramide da direita(representado por "v"), neste caso a nova casa da matriz deve ser a de cima.*/
				else _matB[i][j]=_matA[i-1][j];
			}
			
			/*O "u"(piramide da esquerda) aumenta em 1 a cada nova linha, mas somente se ele nao estiver no centro da
			matriz.*/
			if (u<((float)t/2)-1) u++;
			
			/*O "v"(piramide da direita) aumenta em 1 a cada nova linha, mas somente se ele nao estiver no centro da
			matriz. Aqui nao esta usando o "-1" pois a piramide "u" comeca a ser gerada antes da "v", e por causa disso
			o "ponta" chega ao centro mais rapido que a do "v", entao ela precisa ser parada antes.*/
			if (v<((float)t/2)) v++;
		}



		/*MODULO 2-------------------------------------------------------------------------------------------------------
		Usar esse modulo para a linha que estiver na linha central da matriz, ou as que estiverem abaixo dela.*/
		else{
			u--; /*Como agora estamos na parte debaixo da linha central da matriz, as piramides laterais precisam diminuir*/
			
			/*Aqui identifica se a linha atual eh a linha central da matriz (no caso da matriz ser impar, quando
			esta na linha central, ao adicionar "a metade do valor total", ele ultrapassa o valor total, ->E<- se diminuir
			"a metade do valor total", ele sera menor que 0).*/
			if ((i + ((float)t/2) > (float)t-1) && (i - ((float)t/2) < 0)){
				for (j=0; j<t; j++){
					/*Se "j"(coluna atual), estiver dentro da piramide "u" -> a nova casa da matriz sera a linha de
					baixo(na mesma coluna).*/
					if (j <= u) _matB[i][j]=_matA[i+1][j];
					
					/*Aqui, por ser o meio da linha central, ele verificara se o "j" esta fora da piramide "u"(a verificacao
					desta, ocorre no "if" acima) e da "v". Nao foi necessario verificar se tambem esta fora das piramides
					superiores e inferiores, pois elas nao "entram" na linha central de um quadrado impar. Enfim, se estiver
					fora de todas as piramides(isso so acontece em quadrados impares, no meio da linha central da
					matriz) -> a nova casa da matriz sera ela mesma(ponto central nao rotaciona).*/
					else if (j <= t-1-v) _matB[i][j]=_matA[i][j];
					
					/*Na linha central de um quadrado impar, so e possivel haver a piramide "u", o ponto central e, piramide "v".
					Entao se o "j" nao estiver na "u" e nem no meio da linha, ele so pode estar na piramide "v" -> a nova casa
					da matriz sera a linha acima(na mesma coluna)*/
					else _matB[i][j]=_matA[i-1][j];
				}
			}

			/*MODULO 3---------------------------------------------------------------------------------------------------
			Se nao for a linha central da matriz, usar esse modulo.*/
			
			/*Essas funcoes sao para quando estiver na linha abaixo da central. E elas sao bem parecidas com o MODULO1
			a diferenca eh que na piramide inferior pega a casa da direita(ao inves da esquerda como na piramide superior)*/
			else {
				for (j=0; j<t; j++){
					/*Se "j" estiver na piramide "u" -> pegar casa a baixo.*/
					if (j <= u) _matB[i][j]=_matA[i+1][j];
					
					/*Se "j" nao estiver na "u", mas estiver na "piramide inferior" -> pegar casa a direita.*/
					else if (j <= t-1-v) _matB[i][j]=_matA[i][j+1];
					
					/*Se nao estiver nem na "u" nem na "inferior", so pode estar na "v" -> pegar casa a cima.*/
					else _matB[i][j]=_matA[i-1][j];
				}
				
				/*A partir do momento que esta abaixo da linha central, as piramides laterais precisam ir diminuindo(afinal
				de contas, se nao diminuir iria gerar uma escada ao inves de uma piramide).
				A "v" diminui aqui em baixo e o "u" la em cima(no comeco do codigo), pois a "u" comeca a ser gerada antes
				da "v"(isso ja foi dito anteriormente), se voce fizer um quadrado com as quatro piramides, vera isso.*/
				v--;
			}
		}
	}



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
