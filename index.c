// Online C compiler to run C program online
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **dados;      //ponteiro genérico para os elementos da fila
    int inicio;        //índice do primeiro elemento
    int fim;           //índice do último elemento
    int tamanho;       //número de elementos na fila
    int capacidade;    //capacidade total da fila
} Fila;

//função para criar a fila
Fila* criarFila(int capacidadeInicial) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila == NULL) return NULL;  //verifica se a alocação foi bem-sucedida

    fila->dados = (void **) malloc(sizeof(void*) * capacidadeInicial);
    if (fila->dados == NULL) {
        free(fila);  //libera a estrutura principal se a alocação dos dados falhar
        return NULL;
    }
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
    fila->capacidade = capacidadeInicial;

    return fila;
}

//função para limpar e liberar a fila
void limparFila(Fila *fila) {
    if (fila != NULL) {
        free(fila->dados);  //libera a memória alocada para os dados
        free(fila);         //libera a memória da estrutura da fila
    }
}

//função para imprimir o estado atual da fila (para testes)
void imprimirFila(Fila *fila) {
    if (fila == NULL) {
        printf("fila inexistente.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + i) % fila->capacidade;
        printf("%p ", fila->dados[index]);  //imprime o endereço de cada elemento
    }
    printf("\ncapacidade: %d, tamanho: %d, inicio: %d, fim: %d\n",
           fila->capacidade, fila->tamanho, fila->inicio, fila->fim);
}

int main() {
    int capacidadeInicial = 3;
    Fila *fila = criarFila(capacidadeInicial);
    if (fila == NULL) {
        printf("erro ao criar a fila.\n");
        return 1;
    }
    
    imprimirFila(fila);
    limparFila(fila);

    return 0;
}
