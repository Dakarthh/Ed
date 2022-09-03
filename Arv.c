 #include<stdio.h>
#include<stdlib.h>

typedef struct no
{
int dado;
struct no *esquerda, *direita;

} No;

typedef struct
{
    No *raiz;
}Arvb;

void inserir_esquerda(No *no, int valor){
    if(no->esquerda == NULL){ // verifica se existe algum valor a esquerda
        No *novo = (No*)malloc(sizeof(No)); // cria um novo no
        novo->dado = valor; // o conteudo do novo no passa a ser o valor inserido no parametro da funcao
        novo->esquerda = NULL; // define direita e esquerda como nulo 
        novo->direita = NULL;
        no->esquerda = novo; // o no da esquerda passa a ser o novo no

    }
        else{ // se existir algum no na esquerda inicia uma comparacao
            if (valor < no->esquerda->dado){ // se for menor insere a esquerda
                inserir_esquerda(no->esquerda, valor); //  faz a chamada recursiva da funcao 
            }
                else{
                    inserir_direita(no->esquerda, valor); //  chama a funcao para inserir a direita
                }

        }

}
void inserir_direita(No *no, int valor){
    if(no->direita == NULL){ // verifica se existe algum valor a esquerda
        No *novo = (No*)malloc(sizeof(No)); // cria um novo no
        novo->dado = valor; // o conteudo do novo no passa a ser o valor inserido no parametro da funcao
        novo->esquerda = NULL; // define direita e esquerda como nulo 
        novo->direita = NULL;
        no->direita = novo; // o no da direita passa a ser o novo no
    }
            else{ // se existir algum no na direita inicia uma comparacao
            if (valor > no->direita->dado){ // se for menor insere a esquerda
                inserir_direita(no->direita, valor); //  faz a chamada recursiva da funcao 
            }
                else{
                    inserir_esquerda(no->direita, valor); //  chama a funcao para inserir a direita

}
    }
}

void inserir (Arvb *arv, int valor){
    if (arv->raiz == NULL){ //  verifica se a raiz da arvore está vazia
        No *novo = (No*)malloc(sizeof(No)); // cria um novo no
        novo->dado = valor; // o conteudo do novo no passa a ser o valor inserido no parametro da funcao
        novo->esquerda = NULL; // define direita e esquerda como nulo 
        novo->direita = NULL;
        arv->raiz = novo; // o no criado passa a ser a raiz
    }
    else{ //  se a raiz ja possuir valor, ou seja o teste anterior foi FALSO

        if (valor< arv->raiz->dado){ // verifica se o valor vai ser inserido na esquerda ou na direita usando como comparação a raiz
            inserir_esquerda(arv->raiz, valor);
        }
            else
            inserir_direita(arv->raiz, valor);

    }

}

int esquerda(Arvb *raiz){
    struct no *ant = NULL;
    struct no *atual = raiz;
    int o;
        ant = atual;
        atual = atual->esquerda;
        o = atual->dado;
        return o;
    }

    int direita(Arvb *raiz){
    struct no *ant = NULL;
    struct no *atual = raiz;
    int m;
        ant = atual;
        atual = atual->direita;
        m = atual->dado;
        return m;
    }


int main () {
    Arvb arv;
       
     int i, ran, opcao, opcaob, j, k, r, l;
     int over;
    arv.raiz =NULL;
     for (i=0; i < 15; i++){
                 ran = rand() % 30;
                 inserir(&arv, ran);
             }
    k=0;
    over = 0;
    while(over !=3){
  do  {
        if (arv.raiz->dado= NULL){
            over = 3;
        }
        printf("Jogador 1, esquerda(1) ou direita(2) ?");
        scanf("%d", &opcao);
;
        switch (opcao)
        {
        case 1:
        
        j = esquerda(arv.raiz);
        k = j+k;
            printf("%d\nPontuação: ", k);

            over = 1;    
            break;
        case 2:
        j = direita(arv.raiz);
        k = j+k;

        printf("%d\nPontuação: ", k);

            over = 1;    
            break;


        default:
            printf("\nOpcao invalida\n");

        }

    }while (over != 1);
     do  {
        
        if (arv.raiz->dado= NULL){
            over = 3;
        }
        printf("Jogador 2, esquerda(1) ou direita(2) ?");
        scanf("%d", &opcaob);
;
        switch (opcaob)
        {
        case 1:
        r   = esquerda(arv.raiz);
        l = r+l;
            printf("%d\nPontuação: ", l);
            
             over = 0;        
            break;
        case 2:
             r   = direita(arv.raiz);
        l = r+l;
            printf("%d\nPontuação: ", l);
             over = 0;   
            break;
             

        default:
            printf("\nOpcao invalida\n");
        }

    }while (over != 0);
}
 if (over = 3){
    printf("%d\nPontuação final do Jogador 1: ", k);
    printf("%d\nPontuação final do Jogador 2: ", l);
        }
}