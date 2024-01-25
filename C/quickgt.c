#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 10

void quick(int vet[], int inicio, int fim) {
    int i, j, pivo, aux;

    if (inicio < fim) {
        i = inicio;
        j = fim;
        pivo = vet[(inicio + fim) / 2];

        while (i <= j) {
            while (vet[i] < pivo) i++;
            while (vet[j] > pivo) j--;
            if (i <= j) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                i++;
                j--;
            }
        }

        if (inicio < j)
            quick(vet, inicio, j);
        if (i < fim)
            quick(vet, i, fim);
    }
}

int main() {
    int vett[TAM];
    time_t t; 
    srand((unsigned) time(&t));

    // Preencher o vetor com números aleatórios
    for (int n = 0; n < TAM; n++) {
        vett[n] = rand() % 10;
    }

    // Imprimir o vetor antes da ordenação
    printf("Vetor antes da ordenação:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vett[i]);
    }
    printf("\n");

    // Ordenar o vetor
    quick(vett, 0, TAM - 1);

    // Imprimir o vetor depois da ordenação
    printf("Vetor após a ordenação:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vett[i]);
    }
    printf("\n");

    return 0;
}
