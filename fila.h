#ifndef FILA_H
#define FILA_H

typedef struct No no;

typedef struct Fila {
    no* prim;
    no* ult;
} Fila;

/*Declaracao da struct No que determina o no utilizado na fila e a declaracao da struct que representa a estrutura da fila;
*/

Fila* fila_criar();
/*Cria uma fila que aloca e inicializa os primeiros e o ultimo ponteiro utilizado durante os elementos provenientes do arquivo,inicializa
como NULL para indicar que a fila ta vazia;
*/
void fila_liberar(Fila* f);
/*Declaracao da funcao que libera a memoria alocada de cada no utilizado,apos cada no ser liberado,tambem eh liberado a fila para evitar 
problemas na memoria,recebe como parametro o ponteiro f;
*/
void fila_inserir(Fila* f, int idade);
/*Funcao utilizada para inserir elementos e "passa" a idadde como argumento;
Caso o ponteiro seja NULL nao haverá conexao do novo no com o ultimo da fila;
Atualiza a cada entrada o ponteiro ult para apontar para o novo no;
Recebe como parametro ponteiro referente a fila e o inteiro de idade;
*/
int fila_remover(Fila* f);
/*Funcao especifica para remover o elemento prim;
Atualiza para seguir para o proximo elemento e remover o anterior;
Retorna a idade do cliente que foi removido;
*/
void atendendo_cliente(Fila* f, const char* nome_do_arquivo);
/*Funcao  que carrega a idadde do cliente;
Abre o arquivo fornecido(nome_do_arquivo) e carrega as idades fornecidas;
Para cada cliente,chama a funcao para inserir;
Utiliza a const char para o valor nao ser alterado depois da primeira atribuicao;
*/
void bubble_sort(Fila* f);
/*A principal funcao pois ordena a fila utilizando o algoritmo de bubble sort;
Percorre a lista e compara elementos com a utilizao do laco de repeticao while;
Verifica se um elemento eh menor que o outro,para troca-lo;
*/
void atende_pacientes(Fila* f);
/*Funcao que remove o cliente ou paciente prim;
Funcao repetida ate a fila terminar com todos os clientes ;
*/
void fila_imprimir(Fila* f);
/*Essa funcao percorre as filas fornecidas do no prim e do no ult;
Verifica o estado da fila para imprimir para a depuracao do codigo;
*/

#endif