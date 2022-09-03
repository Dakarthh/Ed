#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>
#ifndef listae
#define listae

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void insereFim(Lista *, int );
void inserePos(Lista *, int , int );
void insereInicio(Lista *, int );



void inicializaLista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void insereInicio(Lista *lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void insereFim(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(lista->inicio == NULL)
            lista->inicio = novo;
        else{
            aux = lista->inicio;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserePos(Lista *lista, int num, int pos){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->valor != pos && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimeLista(Lista lista){
    No *no = lista.inicio;
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
    printf("\nelementos: %d ", lista.tam);

}
#endif
