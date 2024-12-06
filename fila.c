#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct No {
    int idade;
    no* prox;
    no* ant;
};

Fila* fila_criar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

void fila_liberar(Fila* f) {
    no* atual = f->prim;
    while (atual != NULL) {
        no* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(f);
}

void fila_inserir(Fila* f, int idade) {
    no* novo = (no*)malloc(sizeof(no));
    novo->idade = idade;
    novo->prox = NULL;
    novo->ant = f->ult;
    if (f->ult != NULL) {
        f->ult->prox = novo;
    } else {
        f->prim = novo;
    }
    f->ult = novo;
}

int fila_remover(Fila* f) {
    if (f->prim == NULL) {
        return -1;
    }
    no* removido = f->prim;
    int idade = removido->idade;
    f->prim = removido->prox;
    if (f->prim != NULL) {
        f->prim->ant = NULL;
    } else {
        f->ult = NULL;
    }
    free(removido);
    return idade;
}

void atendendo_cliente(Fila* f, const char* nome_do_arquivo) {
    FILE* arquivo = fopen(nome_do_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_do_arquivo);
        exit(1);
    }

    int idade;
    while (fscanf(arquivo, "%d", &idade) == 1) {
        fila_inserir(f, idade);
    }

    fclose(arquivo);
}

void bubble_sort(Fila* f) {
    if (f->prim == NULL || f->prim->prox == NULL) {
        return;
    }

    int inverter = 1;
    while (inverter) {
        inverter = 0;
        no* atual = f->prim;

        while (atual->prox != NULL) {
            if (atual->idade < atual->prox->idade) {
                int temp = atual->idade;
                atual->idade = atual->prox->idade;
                atual->prox->idade = temp;
                inverter = 1;
            }
            atual = atual->prox;
        }
    }
}

void atende_pacientes(Fila* f) {
    printf("Atendendo os pacientes:\n");
    while (f->prim != NULL) {
        int idade = fila_remover(f);
        printf("Paciente de %d anos atendido.\n", idade);
    }
}

void fila_imprimir(Fila* f) {
    no* atual = f->prim;
    while (atual != NULL) {
        printf("%d ", atual->idade);
        atual = atual->prox;
    }
    printf("\n");
}