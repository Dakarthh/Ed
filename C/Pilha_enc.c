#include<stdio.h>
#include<stdlib.h>


struct est_no {
    int valor;
    struct est_no *prox;
};
typedef struct est_no tipo_no;

void empilha(tipo_no **pl, int valor);
int desempilha(tipo_no**pl);
void imprimePilha(tipo_no*pl);


int main(){
 tipo_no *Ppilha;
 Ppilha = NULL;
 empilha(&Ppilha,10 );
 empilha(&Ppilha,1 );
 empilha(&Ppilha,120 );
 empilha(&Ppilha,103 );
 empilha(&Ppilha,104);
 imprimePilha(Ppilha);

}
 
tipo_no *aloca_novo_no(int vl) {
    tipo_no *novo_no;
    novo_no = (tipo_no*) malloc(sizeof(tipo_no));
    if (novo_no != NULL) { //Se alocacao de memoria ocorreu normalmente
        novo_no->valor = vl;
        novo_no->prox = NULL;
    } else { //Caso tenha ocorrido falha na alocacao de memoria
        printf("[ERRO] Falha na alocacao de memoria para um novo noh\n");
    }
    return novo_no;
}

void empilha(tipo_no **pl, int valor){
    tipo_no * novo_no;
    novo_no = aloca_novo_no(valor);

    if(novo_no != NULL){
        novo_no->prox = (*pl);
        (*pl) = novo_no;
            }
 return NULL;
}

int desempilha(tipo_no**pl){
    tipo_no * aux ;
    int valor;
    if ((*pl)==NULL){
        printf("[ERRO] Pilha vazia.\n");
        return -1;

    }else {
        valor = (*pl)->valor;
        aux =   (*pl);
        (*pl) = (*pl)->prox;
        free(aux);
        return valor;
    }

}

void imprimePilha(tipo_no *pl){
    printf("PILHA:\nTOPO->");
    while(pl != NULL){
    printf("[%d]\n", pl->valor);
    pl=pl->prox;
    }
    printf("[NULL]\n");
}