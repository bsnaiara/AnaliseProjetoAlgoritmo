#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define TAM_SALT 16
#define ITERACOES 10000
#define TAM_CHAVE 32

void gerarSalt(unsigned char *salt) {
    if (RAND_bytes(salt, TAM_SALT) != 1) {
        fprintf(stderr, "Erro ao gerar salt aleatório\n");
        exit(EXIT_FAILURE);
    }
}

void criptografarSenha(const char *senha, const unsigned char *salt, unsigned char *senhaCriptografada) {
    if (PKCS5_PBKDF2_HMAC(senha, strlen(senha), salt, TAM_SALT, ITERACOES, EVP_sha256(), TAM_CHAVE, senhaCriptografada) != 1) {
        fprintf(stderr, "Erro ao realizar PBKDF2\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char senha[50];
    unsigned char salt[TAM_SALT];
    unsigned char senhaCriptografada[TAM_CHAVE];

    printf("Digite a senha a ser criptografada: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';  // Remover a quebra de linha inserida pelo fgets

    gerarSalt(salt);
    criptografarSenha(senha, salt, senhaCriptografada);

    printf("Senha criptografada (PBKDF2-SHA-256): ");
    for (int i = 0; i < TAM_CHAVE; i++) {
        printf("%02x", senhaCriptografada[i]);
    }
    printf("\n");

    return 0;
}
