#include <stdio.h>

int main(){
    int _op, _exp;
    float _num1, _num2, _res;
    do{
        //TABELA PARA O USUARIO ESCOLHER UMA OPCAO
        printf("Tabela:\n");
        printf("0 - Sair\n");
        printf("1 - Adicao\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Potenciacao\n");
        printf("\nEscolha uma das opcoes acima: ");
        scanf("%d", &_op);
        //SE O USUARIO DIGITAR 0 A CALCULADORA E FECHADA
        if (_op == 0){
            break;
        }
        printf("Digite o primeiro numero: ");
        scanf("%f", &_num1);
        printf("Digite o segundo numero: ");
        scanf("%f", &_num2);
        switch(_op){
            //ADICAO
            case 1:
                printf("%.2f mais %.2f:\n", _num1, _num2);
                _res = _num1 + _num2;
                break;
            //SUBTRACAO
            case 2:
                printf("%.2f menos %.2f:\n", _num1, _num2);
                _res = _num1 - _num2;
                break;
            //MULTIPLICACAO
            case 3:
                printf("%.2f multiplicado por %.2f:\n", _num1, _num2);
                _res = _num1 * _num2;
                break;
            //DIVISAO
            case 4:
                printf("%.2f dividido por %.2f:\n", _num1, _num2);
                //SE O DIVISOR FOR 0, INFORMAR QUE DIVISAO POR ZERO NAO EXISTE E REINICIAR O PROGRAMA
                if (_num2 == 0){
                    printf("Erro: divisao por zero nao existe!\n");
                }
                else{
                    _res = _num1 / _num2;
                }
                break;
            //POTENCIACAO
            case 5:
                printf("%.2f elevado a %.2f:\n", _num1, _num2);
                //AO DECLARAR O RESULTADO COMO 1, SE O USUARIO DIGITAR 0 NO EXPOENTE, O RESULTADO RETORNA 1
                _res = 1;
                //SE O USUARIO DIGITAR 0 NO EXPOENTE, O CALCULO DE POTENCIA NAO SERA REALIZADO, MOSTRANDO 1 COMO RESULTADO, QUE FOI DECLARADO ANTERIORMENTE
                _exp = 1;
                //ENQUANTO A QUANTIDADE DE VEZES EM QUE O PRIMEIRO_NUMERO_DIGITADO FOR MULTIPLICADO POR ELE MESMO, FOR MENOR OU IGUAL AO SEGUNDO_NUMERO_DIGITADO, CONTINUAR MULTIPLICANDO-O
                while (_exp <= _num2){
                    _res = _res * _num1;
                    _exp++;
                }
                break;
            //SE O USUARIO DIGITAR UMA OPCAO QUE NAO ESTA NA TABELA
            default:
                printf("Escolha uma opcao que esta dentro da tabela!\n\n");
                break;
        }
        //MOSTRAR O RESULTADO SOMENTE SE O USUARIO ESCOLHER UMA OPCAO QUE ESTA DENTRO DA TABELA, EXCETO ZERO
        if (_op >=1 && _op<=5){
            printf("Resultado: %.2f\n\n", _res);
            //CERTIFICAR-ME QUE O RESULTADO ANTERIOR NAO SERA UTILIZADO PELOS CODIGOS NA PROXIMA VEZ QUE FOR EXECUTADO
            _res = 0;
        }
    //REPETIR TUDO O QUE ESTA ACIMA, DESDE QUE O USUARIO NAO DIGITE ZERO
    }while(_op != 0);
    //SE O USUARIO DIGITAR ZERO, SINALIZAR QUE O PROGRAMA ESTA FECHANDO
    printf("Saindo...");
}
