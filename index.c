#include <stdio.h>
#include <stdlib.h>

// define a estrutura fila com os campos necessários para gerenciar os elementos
typedef struct {
    void **dados;      // ponteiro duplo para armazenar elementos de qualquer tipo na fila
    int inicio;        // índice do primeiro elemento da fila
    int fim;           // índice do último elemento da fila
    int tamanho;       // quantidade atual de elementos na fila
    int capacidade;    // capacidade total atual da fila
} Fila;

// função para criar uma nova fila com capacidade inicial especificada
Fila* criarFila(int capacidadeInicial) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));  // aloca memória para a estrutura da fila
    if (fila == NULL) return NULL;  // verifica se a alocação foi bem-sucedida

    // aloca memória para armazenar os dados (elementos) da fila
    fila->dados = (void **) malloc(sizeof(void*) * capacidadeInicial);
    if (fila->dados == NULL) {  // se a alocação falhar
        free(fila);             // libera a memória alocada para a estrutura
        return NULL;            // retorna NULL para indicar falha
    }
    fila->inicio = 0;                // define o índice de início como 0
    fila->fim = -1;                  // define o índice de fim como -1, pois a fila está vazia
    fila->tamanho = 0;               // inicia com 0 elementos
    fila->capacidade = capacidadeInicial;  // define a capacidade inicial fornecida

    return fila;  // retorna o ponteiro para a fila criada
}

// função que dobra a capacidade da fila quando ela está cheia
void dobrarCapacidade(Fila *fila) {
    int novaCapacidade = fila->capacidade * 2;  // define a nova capacidade como o dobro da capacidade atual
    void **novosDados = (void **) malloc(sizeof(void*) * novaCapacidade);  // aloca memória para a nova capacidade

    // realoca os elementos da fila antiga para a nova área de memória
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + i) % fila->capacidade;  // calcula o índice circularmente
        novosDados[i] = fila->dados[index];                 // copia o elemento para a nova posição
    }

    free(fila->dados);         // libera a memória antiga da fila
    fila->dados = novosDados;  // aponta os dados para a nova área de memória alocada
    fila->inicio = 0;          // redefine o início como 0
    fila->fim = fila->tamanho - 1;  // redefine o fim para o último elemento
    fila->capacidade = novaCapacidade;  // atualiza a capacidade da fila
    printf("Capacidade dobrada para: %d\n", novaCapacidade);  // exibe a nova capacidade
}

// função para inserir um novo elemento na fila
int inserirNaFila(Fila *fila, void *elemento) {
    if (fila->tamanho == fila->capacidade) {  // verifica se a fila está cheia
        dobrarCapacidade(fila);               // chama a função para dobrar a capacidade se necessário
    }

    fila->fim = (fila->fim + 1) % fila->capacidade;  // move o índice fim para o próximo índice disponível
    fila->dados[fila->fim] = elemento;  // armazena o elemento no fim da fila
    fila->tamanho++;                    // aumenta o tamanho da fila
    return 1;  // retorna 1 para indicar sucesso
}

// função para exibir o conteúdo da fila
void imprimirFila(Fila *fila) {
    printf("Fila: ");
    for (int i = 0; i < fila->tamanho; i++) {          // percorre os elementos atuais na fila
        int index = (fila->inicio + i) % fila->capacidade;  // calcula o índice usando o índice circular
        if (fila->dados[index] != NULL) {                   // verifica se o dado não é NULL
            printf("%p ", fila->dados[index]);              // exibe o endereço do elemento
        }
    }
    printf("\nCapacidade: %d, Tamanho: %d, Inicio: %d, Fim: %d\n",
           fila->capacidade, fila->tamanho, fila->inicio, fila->fim);  // exibe os detalhes da fila
}

int main() {
    int capacidadeInicial = 3;                 // define a capacidade inicial da fila
    Fila *fila = criarFila(capacidadeInicial); // cria a fila com a capacidade inicial
    if (fila == NULL) {                        // verifica se a criação foi bem-sucedida
        printf("Erro ao criar a fila.\n");     // exibe mensagem de erro se necessário
        return 1;                              // retorna 1 para indicar erro
    }

    int elementos[] = {10, 20, 30, 40, 50};  // define alguns elementos para inserir na fila
    for (int i = 0; i < 5; i++) {            // insere cada elemento no array
        inserirNaFila(fila, &elementos[i]);  // chama a função de inserção
        printf("Inserindo elemento %d na fila:\n", elementos[i]);  // exibe o valor inserido
        imprimirFila(fila);  // chama a função de impressão para ver o estado atual da fila
    }

    free(fila->dados);  // libera a memória alocada para os dados da fila
    free(fila);         // libera a memória alocada para a estrutura da fila
    return 0;           // retorna 0 para indicar sucesso
}
