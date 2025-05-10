#include <stdio.h>

int main() {
    int i, _iniciar;
    printf("Iniciar...");
    scanf("%d", &_iniciar);

    for (i = 0; i < 100; i++) {
        for (int j=0; j<100; j++){
            printf("Contador: %d\n", i);
            //fflush(stdout); // Limpa o buffer e força a exibição imediata dos dados
        }
    }
}
