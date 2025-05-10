#include <stdio.h>

void main(){
	int _max;
	printf("Tamanho do vetor: ");
	scanf("%d", &_max);/*
	Isso serve para definir a quantidade de numeros que serao digitados
	*/

	int _nums[_max], _ordenado[_max], _posiOrdem[_max],_preenchido[_max];/*
	Vetores de tamanho definido pelo usuario que irao ser utilizads para:
	_nums -> sao os numeros que o usuario digitara;
	_ordenado -> sera onde o resultado final ficara;
	_posiOrdem -> sera armazenado a quantidade de vezes em que cada um dos _nums digitados foi menor ou igual a todos os outros _nums;
	_preenchido -> serve para definir quando uma posicao do _ordenado ja foi utilizada, para que ela nao possa ser sobscrevida;
	*/

	for (int i=0; i<_max; i++){
		_posiOrdem[i] = 0;
		_ordenado[i] = 0;
		_preenchido[i] = 0;
	}/*
	Isso fara com que todas as posicoes dos vetores _posiOrdem, _ordenado e _preenchido ficam em 0.
	*/

	printf("\nExecutando modulo(1) de leitura de numeros do usuario...\n");
	for (int i=0; i<_max; i++){
		printf("Vetor[%d]: ", i);
		scanf("%d", &_nums[i]);
	}/*
	Leitura dos numeros digitados pelo usuario.
	*/

	printf("\nExecutando modulo(2) para verificacao de quantas vezes cada numero do\n    usuario foi menor ou igual a todos os outros numeros digitados\n");
	for (int i=0; i<_max; i++){
		for (int j=0; j<_max; j++){
			if (_nums[i] <= _nums[j]){
				_posiOrdem[i]++;
			}
		}
		_posiOrdem[i]--; //isso foi necessario porque nao pode contar ele mesmo(e porque o vetor comeca de 0...)

	}/*
	Contar a quantidade de vezes que cada _nums foi menor ou igual a todos os outros _nums digitados
	Por exemplo foi digitado [0]=1, [1]=2, [2]=1, [3]=3, [4]=2 então fara:
	_posiOrdem[0](no caso o numero 1)= 1+1+1+1+1 = 5 -> -1(exeto ele mesmo) = 4 <- isso será armazenado em _posiOrdem[0]
	_posiOrdem[1](no caso o numero 2)= 0+1+0+1+1 = 3 -> -1(exeto ele mesmo) = 2 <- isso será armazenado em _posiOrdem[1]
	_posiOrdem[2](no caso o numero 1)= 1+1+1+1+1 = 5 -> -1(exeto ele mesmo) = 4 <- isso será armazenado em _posiOrdem[2]
	_posiOrdem[3](no caso o numero 3)= 0+0+0+1+0 = 1 -> -1(exeto ele mesmo) = 0 <- isso será armazenado em _posiOrdem[3]
	_posiOrdem[4](no caso o numero 2)= 0+1+0+1+1 = 3 -> -1(exeto ele mesmo) = 2 <- isso será armazenado em _posiOrdem[4]

	Atraves disso da para ver que o 3 ficara na posicao 0 do _ordenado, pois ele nao foi menor que nenhum outro numero
	e nao foi repetido nenhuma vez.
	Ja os 2 disputarao as posicoes [2] e [2-1]([1]) do _ordenado, pois eles sao os segundo maiores, e foi repetido duas vezes.
	E o 1 disputara as posicoes [4] e [4-1]([3]) do _ordenado, pois eles sao os terceiros maiores, e tambem foi repetido duas vezes.
	(a disputa acontece somente quando ha numeros repetidos)
	No modulo abaixo explica como isso funciona.
	*/

	printf("\nExecutando o modulo(3) para organizar os numeros do usuario\n");
	for (int i=0; i<_max; i++){
		if (_preenchido[_posiOrdem[i]] == 0){
			_preenchido[_posiOrdem[i]] = 1;
			_ordenado[_posiOrdem[i]] = _nums[i];
		}/*
		Se _ordenado na posicao _posiOrdem[i] nao estiver ja preenchido (ou seja, o _nums nao esta
		repetido, e _preenchido=0 "falso"), ele vai receber o valor da posicao _nums[i], e
		marcar que esta posicao ja foi preenchida.
		*/

		else{
			for (int descer=1; descer!=0;){
				if (_preenchido[_posiOrdem[i]-descer]==0){
					_preenchido[_posiOrdem[i]-descer] = 1;
					_ordenado[_posiOrdem[i]-descer] = _nums[i];
					descer=0;
				}
				else{
					descer++;
				}
			}
		}/*
		Se _ordenado(na posicao _posiOrdem[i]) ja estiver preenchido(significa que o usuario digitou numeros repetidos),
		entao tera que colocar o valor em uma posicao abaixo, e se a de baixo tambem ja estiver preenchida descer mais
		um, e assim por diante.
		Isso funciona pois: (usando o exemplo do modulo(2))
			Somente as posicoes 4,2, e 0 serao utilizadas, entao com certeza o 3 e 1 sera um repetido que foi usado no 4 e 2.
			Por isso se colocar o valor do repetido do 4 no 3 e do 2 no 1 faz sentido.

		Supondo que o usuario digite [0]=2, [1]=2, [2]=2, [3]=1, [4]=2:
			Somente as posicoes 4 e 3 seriam utilizadas, sendo que o tamanho do vetor vai de 0..4. Entao com certeza as
			posicoes 2, 1 e 0 seria um repetido do 3. Por isso colocar o valor do repetido 3 no 2, 1 e 0 faz sentido.
		*/
	}/*
	O modulo(3) acima tem a seguinte ideia:
	Primeiramente o que e _posiOrdem: atraves dessa variavel que a ordem sera realizada, um exemplo de vetores de 5 numeros (0..4):
		_posiOrdem[0] vai receber a quantidade de vezes que o _nums[0] foi menor ou igual a todos os outros numeros digitados.
		_posiOrdem[1] vai receber a quantidade de vezes que o _nums[1] foi menor ou igual a todos os outros numeros digitados.
		_posiOrdem[2] vai receber a quantidade de vezes que o _nums[2] foi menor ou igual a todos os outros numeros digitados.
		_posiOrdem[3] vai receber a quantidade de vezes que o _nums[3] foi menor ou igual a todos os outros numeros digitados.
		_posiOrdem[4] vai receber a quantidade de vezes que o _nums[4] foi menor ou igual a todos os outros numeros digitados.
		Aa logica aqui e :
			Nao importa quantos numero forem digitados, um sempre sera menor ou igual ao outro, portanto, isso por si so, vai
			criar uma ordem pois -> o numero que for menor todas as vezes(mesma quantidade que o tamanho do vetor) sera com certeza
			o menor de todos e por isso ficara em uma das extremidades(no caso, no maior valor do vetor), se nao tiver numeros
			repetidos, tera um segundo menor e ele ficara na penultima posicao das extremidades(no caso, um atras do ultimo valor
			do vetor) e assim por diante ate chegar no maior numero que nao sera menor que nenhum outro, assim ele ficara na outra
			extremidade do vetor(no caso, no primeiro numero do vetor).

			No caso de houver numeros repetidos, eles usarao a mesma posicao do vetor, o que vai inutilizar proporcionalmente
			as proximas posicoes, por isso a funcao de baixo sabe que colocar o numero repetido da posicao "X" nas proximas
			posicoes nao sera um problema.
	*/

	int _cORd;
	printf("\nNumeros do usuario organizados:\n1 para crescente ou 2 para decrescente... ");
	scanf("%d", &_cORd);
	if (_cORd >= 2){
		for (int i=0; i<_max; i++){
		printf("-> %d\n", _ordenado[i]);
		}
	}
	else{
		for (int i=_max-1; i>=0; i--){
		printf("-> %d\n", _ordenado[i]);
		}
	}/*
	Apenas mostrar em ordem crescente ou decrescente o resultado final
	*/
}
