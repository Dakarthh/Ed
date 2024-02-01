#include<stdio.h>
#include<stdlib.h>


struct est_no {
    int valor;
    struct est_no *prox;
};
typedef struct est_no tipo_no;

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

/* Funcao que insere no fim da lista */
void insereFim(tipo_no **lst, int vlr) {
    tipo_no * novo_noh, *aux;
    novo_noh = aloca_novo_no(vlr);

    //Inicializa valores do novo no
    novo_noh->valor = vlr;
    novo_noh->prox = NULL;

    //Acopla novo no na lista
    if ( (*lst) == NULL ) { //Trata o caso especial que é a lista vazia
        *lst = novo_noh;
    } else {
        //percorre a lista até o último no
        aux = *lst;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        //anexa o novo no ao último no
        aux->prox = novo_noh;
    }
}


/* Funcao que insere no inicio da lista encadeada */
void insereInicio(tipo_no **lst, int vlr) {
       tipo_no * novo_noh;
    novo_noh = aloca_novo_no(vlr);
        novo_noh->valor = vlr;
        novo_noh->prox = *lst;
        *lst = novo_noh;

}


/* Funcao que insere um valor em uma posicao especifica da lst */
void inserePos(tipo_no **lst, int pos, int vlr) {
    int cont;
    tipo_no *novo_noh, *aux, *aux_ant;;
    novo_noh = aloca_novo_no(vlr);
    novo_noh->valor = vlr;
    cont = 0;
    aux = (*lst);

    while ( (cont < pos) && (aux != NULL) ) {
        cont = cont + 1;
        aux_ant = aux;
        aux = aux->prox;
    }

    //Verifica o contexto da parada do while
    if ( (cont == pos) && (pos > 0) ) {
        novo_noh->prox = aux;
        aux_ant->prox = novo_noh;
    } else {
        novo_noh->prox = *lst;
        *lst = novo_noh;
    }
}
int removeInicio(tipo_no **lst) {
    tipo_no *aux;
    int valor;
     valor = (*lst)->valor;
        aux =   (*lst);
        (*lst) = (*lst)->prox;
        free(aux);
        return valor;
    
}


/* Funcao que remove o noh do fim da lista */
tipo_no removeFim(tipo_no **lst) {
    tipo_no *aux, *noRemover, noCopia;

    //trata o caso especial de haver apenas 1 no
    if ((*lst)->prox == NULL) {
        noCopia = **lst;
        free(*lst);
        (*lst) = NULL;
        return noCopia;
    } else {
        noRemover = (*lst);
        while( noRemover->prox != NULL) {
            aux = noRemover;
            noRemover = noRemover->prox;
        }
        noCopia = *noRemover;
        free(noRemover);
        aux->prox = NULL;
        return noCopia;
    }
}
void removePos(tipo_no **lst, int pos) {
    int cont;
    tipo_no *novo_noh, *aux, *aux_ant;
    novo_noh = (tipo_no*) malloc(sizeof(tipo_no));
    cont = 0;
    aux = (*lst);

    while ( (cont < pos) && (aux != NULL) ) {
        cont = cont + 1;
        aux_ant = aux;
        aux = aux->prox;
    }

    //Verifica o contexto da parada do while
    if ( (cont == pos) && (pos > 0) ) {
        
    
        
    }
}

void imprimelista(tipo_no*list){
    while (list!=NULL)
    {
          printf("[%d]", list->valor);
              list=list->prox;

    }
    
  
}

int main(){
    tipo_no*lista;
    lista= NULL;

    insereInicio(&lista, 1);
    printf("\ninserindo numero 12 no começo da lista \n");

    insereInicio(&lista, 12);
    imprimelista(lista);

    printf("\ninserindo numero 35 no fim da lista \n");
    insereFim(&lista, 35);
    imprimelista(lista);

    printf("\ninserindo numero 45 na posição 2 da lista \n");
    inserePos(&lista, 2, 45);
    imprimelista(lista);

    removeFim(&lista);
    printf("\nremovendo ultimo elemento da lista \n");
    imprimelista(lista);

     removeInicio(&lista);
    printf("\nremovendo primeiro elemento da lista \n");
    imprimelista(lista);

    removePos(&lista, 1);
    printf("\nremovendo elemnto 1  da lista \n");
    imprimelista(lista);

    
}