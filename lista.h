#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//simplipificacao para void pointer
typedef void* ponteiro;
//typedef void* P1;

//funcao que inicializa a lista(faz com que ela fique vazia)
ponteiro create_lista(int tam);

//funcao para inserir dados na lista
void insert_lista(ponteiro p, ponteiro conteudo);

//funcao que da a quantidade de dados da lista
int length(ponteiro p);

//funcao para remover um item da lista
void remove_lista(ponteiro p, ponteiro posic);

//funcao que retorna o endereço do campo "item" da lista
ponteiro get_lista(ponteiro p, ponteiro posic);

//insere antes do item indicado
ponteiro insert_before(ponteiro p, ponteiro posic, ponteiro conteudo);

//insere depois do item indicado
ponteiro insert_after(ponteiro p, ponteiro posic, ponteiro conteudo);

//retorna o primeiro elemento da lista
ponteiro get_first(ponteiro p);

//retorna elemento seguinte a posic da lista
ponteiro get_next(ponteiro p, ponteiro posic);

//retorna o ultimo elemento da lista
ponteiro get_last(ponteiro p);

//indica um elemento existente na lista
ponteiro get_previous(ponteiro p, ponteiro posic);

#endif // LISTA_H_INCLUDED*/
