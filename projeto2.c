#include <stdio.h>
#include <string.h>

// Estrutura representando um time
typedef struct {
    char nome[50];
    int pontos;
} Time;

// Função para exibir a tabela de times
void exibirTabela(Time *times, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Time: %s; Pontos: %d\n", times[i].nome, times[i].pontos);
    }
}

// Função para exibir os cinco primeiros da tabela
void cincoPrimeiros(Time *times, int tamanho) {
    for (int i = 0; i < tamanho && i < 5; i++) {
        printf("Posição: %d; Time: %s; Pontos: %d\n", i + 1, times[i].nome, times[i].pontos);
    }
}

// Função para exibir os cinco últimos da tabela
void cincoUltimos(Time *times, int tamanho) {
    int indice = tamanho - 5;
    for (int i = indice; i < tamanho; i++) {
        printf("Posição: %d; Time: %s; Pontos: %d\n", i + 1, times[i].nome, times[i].pontos);
    }
}

// Função para calcular e exibir a diferença de pontos entre times
void diferencaPontos(Time *times, int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        for (int j = i + 1; j < fim; j++) {
            int diferenca = times[i].pontos - times[j].pontos;
            printf("%s x %s Diferença: %d\n", times[i].nome, times[j].nome, diferenca);
        }
    }
}

// Função para reordenar e reduzir o tamanho pela metade
void reordenarETamanhoMetade(Time *times, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (times[j].pontos < times[j + 1].pontos) {
                // Troca os times de posição se necessário
                Time temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }

    // Reduz o tamanho pela metade
    int newSize = tamanho / 2;
    for (int i = newSize; i < tamanho; i++) {
        memset(times[i].nome, 0, sizeof(times[i].nome));
        times[i].pontos = 0;
    }
}

int main() {
    Time tabela[10];

    // Inicialização dos times
    strcpy(tabela[0].nome, "Palmeiras");
    tabela[0].pontos = 63;
  
    strcpy(tabela[1].nome, "Flamengo");
    tabela[1].pontos = 63;

    strcpy(tabela[2].nome, "Botafogo");
    tabela[2].pontos = 62;

  strcpy(tabela[3].nome, "Atlético-MG");
  tabela[3].pontos = 60;

  strcpy(tabela[4].nome, "Gremio");
    tabela[4].pontos = 59;

  strcpy(tabela[5].nome, "Bragantino");
    tabela[5].pontos = 59;

  strcpy(tabela[6].nome, "Fluminense");
    tabela[6].pontos = 53;

  strcpy(tabela[7].nome, "Atlético-PR");
    tabela[7].pontos = 52;

  strcpy(tabela[8].nome, "Cuiabá");
    tabela[8].pontos = 63;

  
  // ... (repetir para os outros times)''

    // Exibe tabela com seus respectivos pontos
    exibirTabela(tabela, 10);
    printf('\n');
    // Exibe os cinco melhores da Tabela
    cincoPrimeiros(tabela, 10);

    // Exibe os cinco piores da Tabela
    cincoUltimos(tabela, 10);

    // Exibe a diferença dos cinco primeiros
    diferencaPontos(tabela, 0, 5);

    // Exibe a diferença dos cinco últimos
    diferencaPontos(tabela, 5, 10);

    printf("\nMetade dos Times com base na quantidade de pontos:\n");
    reordenarETamanhoMetade(tabela, 10);
    exibirTabela(tabela, 10);

    return 0;
}