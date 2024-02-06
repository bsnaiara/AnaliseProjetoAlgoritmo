#include <stdio.h>
#include <string.h>

// Definindo a estrutura do produto
typedef struct {
    char nome[50];
    int identificador;
} Produto;

// Função de busca binária otimizada para a lista ordenada
int buscaBinariaOtimizada(Produto estoque[], int tamanho, char produtoBuscado[]) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        int comparacao = strcmp(estoque[meio].nome, produtoBuscado);

        if (comparacao == 0) {
            return estoque[meio].identificador;  // Produto encontrado
        } else if (comparacao < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1;  // Produto não encontrado
}

// Função de ordenação por inserção
void ordenarPorInsercao(Produto estoque[], int tamanho) {
    int i, j;
    Produto chave;

    for (i = 1; i < tamanho; i++) {
        chave = estoque[i];
        j = i - 1;

        // Move os elementos do estoque[0..i-1] que são maiores que a chave para uma posição à frente
        while (j >= 0 && strcmp(estoque[j].nome, chave.nome) > 0) {
            estoque[j + 1] = estoque[j];
            j = j - 1;
        }
        estoque[j + 1] = chave;
    }
}

// Função para exibir o estoque
void exibirEstoque(Produto estoque[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Produto: %s, Identificador: %d\n", estoque[i].nome, estoque[i].identificador);
    }
}

int main() {
    // Exemplo de uso
    Produto estoque[] = {
        {"banana", 2},
        {"apple", 1},
        {"grape", 3},
        {"orange", 4},
        {"pear", 5}
    };

    int tamanhoEstoque = sizeof(estoque) / sizeof(estoque[0]);

    char produtoBuscado[] = "orange";

    printf("Estoque antes da ordenação:\n");
    exibirEstoque(estoque, tamanhoEstoque);

    // Ordenar o estoque por inserção
    ordenarPorInsercao(estoque, tamanhoEstoque);

    printf("\nEstoque após a ordenação:\n");
    exibirEstoque(estoque, tamanhoEstoque);

    // Realizar busca binária otimizada no estoque ordenado
    int resultadoBusca = buscaBinariaOtimizada(estoque, tamanhoEstoque, produtoBuscado);

    if (resultadoBusca != -1) {
        printf("\nProduto encontrado. Identificador: %d\n", resultadoBusca);
    } else {
        printf("\nProduto não encontrado.\n");
    }

    return 0;
}
