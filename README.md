# Projeto: Estrutura de Dados - Fila com Alocação Dinâmica

Este projeto apresenta uma implementação de uma estrutura de dados do tipo Fila (FIFO - First In, First Out) em C, com gerenciamento dinâmico de memória para redimensionamento automático. A Fila permite a inserção e remoção de elementos, duplicando sua capacidade conforme necessário para otimizar o uso de memória e garantir que novos elementos possam ser adicionados quando a capacidade atual for atingida.

## Funcionalidades

O código implementa as seguintes funcionalidades:

1. **Criação de uma Fila**  
   - Função `criarFila`: inicializa uma nova Fila com uma capacidade inicial definida. A Fila utiliza alocação dinâmica para ajustar sua capacidade conforme novos elementos são adicionados.

2. **Inserção de Elementos na Fila**  
   - Função `inserirNaFila`: insere um novo elemento no final da Fila. Caso a Fila esteja cheia, a função dobra a capacidade da Fila antes de inserir o novo elemento, garantindo o espaço necessário.

3. **Remoção de Elementos da Fila**  
   - Função `removerDaFila`: remove o elemento que está no início da Fila, retornando-o. Caso a Fila esteja vazia, a função retorna `NULL`.

4. **Impressão do Estado da Fila**  
   - Função `imprimirFila`: exibe o conteúdo da Fila, incluindo informações sobre a capacidade atual, o tamanho, e os índices de início e fim.

5. **Redimensionamento Dinâmico da Fila**  
   - Função `dobrarCapacidade`: dobra a capacidade da Fila quando esta está cheia, realocando os elementos na nova área de memória e garantindo o funcionamento contínuo da estrutura.

## Estrutura do Código

### Arquivo Principal (`main`)

O arquivo principal do programa executa testes para verificar a funcionalidade de cada uma das operações acima. São realizados os seguintes testes:

- **Inserção e Exibição**: insere uma série de elementos na Fila e exibe o estado da Fila a cada inserção.
- **Remoção e Exibição**: remove elementos da Fila e exibe o estado da Fila após cada remoção.
- **Redimensionamento**: testa a inserção de elementos além da capacidade inicial para garantir o funcionamento do redimensionamento dinâmico.

## Colaboradores
- Giovanni Albino
- Isabella Caramigo
- Leticia Gonçalves
- Matheus Silva
- Noemi Benedito
