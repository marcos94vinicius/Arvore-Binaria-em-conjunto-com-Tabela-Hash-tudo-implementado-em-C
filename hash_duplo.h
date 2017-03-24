#ifndef HASH_DUPLO_H_INCLUDED
#define HASH_DUPLO_H_INCLUDED

typedef long int b;

//ponteiro para void pointer
typedef void* tabelaD;

//ponteiro para void pointer
typedef void* Item;

//retorna uma tabela de espalhamento vazia
tabelaD criaTabela_HD();

//função que calcula a posição do dado a ser inserido
b calcula_HD (char ch[10]);

//função que recalcula a posição do dado a ser inserido
b calcula2_HD (char ch[10]);

//adiciona a tupla <ch,v> à vetor. Retorna 1, se a tupla foi efetivamente adicionada; 0, caso contrário.
b put_HD (tabelaD vetor, char ch[10], Item v, char id[10]);

//retorna verdadeiro se H contém uma tupla t tal que #1(t)=ch.
b exists_HD (tabelaD vetor, char ch[10], char id[10]);

//GET (h, ch). Seja a tupla <ch, v> contida em h retorna v.
Item get_HD (long int posic, tabelaD h);

//Remove um elemento da tabela
void remove_HD (tabelaD h, char ch[10], char id[10]);

//Retorna o primeiro elemento da lista da chave ch
long int get_first_HD(tabelaD h, char ch[10]);

//Retorna o elemento seguinte a p
long int get_next_HD(tabelaD h, long int posic);

#endif // HASH_DUPLO_H_INCLUDED
