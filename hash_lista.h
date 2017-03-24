#ifndef HASH_LISTA_H_INCLUDED
#define HASH_LISTA_H_INCLUDED

//ponteiro para void pointer
typedef void* tabelaL;

//ponteiro para void pointer
typedef void* Item;

//função que calcula a posição do dado a ser inserido
int calcula_HL (char ch[10]);

//retorna uma tabela de espalhamento vazia
tabelaL criaTabela_HL();

//adiciona a tupla <ch,v> à vetor. Retorna 1, se a tupla foi efetivamente adicionada; 0, caso contrário.
int put_HL (tabelaL vetor, char ch[10], Item v, char id[100]);

//retorna verdadeiro se H contém uma tupla t tal que #1(t)=ch.
int exists_HL (tabelaL vetor, char ch[10], char id[100]);

//Retorna o conteudo apontado por h.
Item get_HL (tabelaL h/*, char ch[10], char id[100]*/);

//Remove um elemento da tabela
void remove_HL (tabelaL h, char ch[10], char id[10]);

//Retorna o primeiro elemento da lista da chave ch
Item get_first_HL(tabelaL h, char ch[10]);

//Retorna o elemento seguinte a p
Item get_next_HL(char ch[10], tabelaL p);

#endif // HASH_LISTA_H_INCLUDED
