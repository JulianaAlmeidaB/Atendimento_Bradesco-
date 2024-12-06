// Importacao das bibliotecas utilizadas no codigo;
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
//Funcao que atende os clientes,referente as suas idades;
void atendendo_clientes(Fila* f,const char* nome_do_arquivo); 

//Funcao que ordena as filas utilizando o algoritmo de bubble sort;
void bubble_sort(Fila *f);

//Funcao que atende cliente e os remove da fila;
void atende_pacientes(Fila *f);

int main(void) {
    //Funcoes utilizadas na main;
    Fila* fila = fila_criar();
    char* nome_do_arquivo = "clientes.txt";
    atendendo_cliente(fila, nome_do_arquivo);
    bubble_sort(fila);
    atende_pacientes(fila);
    fila_liberar(fila);
    return 0;
}