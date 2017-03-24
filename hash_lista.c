#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash_lista.h"

//Estrutura que contem as informações para isenrir na hash e um ponteiro lista
struct info{

	char chave[100];
	Item conteudo;
	struct info *prox;
};
typedef struct info info;

//Estrutura que contém apenas um void pointer para criar a tabela
struct tab {

    void* conteudo;
};
typedef struct tab tab;

//função que calcula a posição do dado a ser inserido
int calcula_HL (char ch[10]){

	int i = 1, j = 0;
    int posic = 0;

    while (ch[j] != '\0'){

        posic += ch[j]*i;
        i++;
        j++;
    }
    while(posic >= 2000){

        if (posic % 2000 >= 1)
            posic -= 1001;
    }

    return posic;
}

//retorna uma tabela de espalhamento vazia
tabelaL criaTabela_HL(){

	tab *vet = (tab*) malloc (2000 * sizeof (tab));
	int i;

	for(i = 0; i < 2000; i++){

		vet[i].conteudo = NULL;
	}

	return (vet);
}

//adiciona a tupla <ch,v> à vetor. Retorna 1, se a tupla foi efetivamente adicionada; 0, caso contrário.
int put_HL (tabelaL vetor, char ch[10], Item v, char id[100]){

    tab *vet = (tab *)vetor;
    int posic = calcula_HL(ch);

    info *nova = (info *) malloc(sizeof(info));
    nova->conteudo = v;
    strcpy(nova->chave, id);
    nova->prox = NULL;

    int r = 0;

    if (vet[posic].conteudo ==  NULL){

        vet[posic].conteudo = nova;
        r = 1;
    }
    else{

        info *aux = (info *) vet[posic].conteudo;
        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = nova;
        r = 1;
    }

    return r;
}

//Retorna o conteudo apontado por h.
Item get_HL (tabelaL h/*, char ch[10], char id[100]*/){

    //tab *vet = (tab *)h;
    //int posic = calcula_HL(ch);

    //if (vet[posic].conteudo == NULL)
       // return NULL;

    //else{

        info *aux = (info *)h;

        //while(strcmp(aux->chave, id) != 0){

            //aux = aux->prox;
            //if(aux == NULL)
              //  return NULL;
        //}
        return aux->conteudo;
    //}
}

//Remove um elemento da tabela
void remove_HL (tabelaL h, char ch[10], char id[100]){

	int posic = calcula_HL(ch);
	tab *vet = (tab *)h;
	
	if (vet[posic].conteudo == NULL)
		return;
	
	else{

		info *aux = (info *)vet[posic].conteudo;
		info *aux2 = (info *)vet[posic].conteudo;
		while(strcmp(aux->chave, id) != 0){

			aux2 = aux;				
			aux = aux->prox;
			if(aux == NULL)
				return;
		}			
		if(aux == vet[posic].conteudo){

			vet[posic].conteudo = aux->prox;
			free(aux);
			return;			
		}
		else
			aux2->prox = aux->prox;
	}
}

//Retorna o primeiro elemento da lista da chave ch
Item get_first_HL(tabelaL h, char ch[10]){

	int posic = calcula_HL(ch);
	tab *vet = (tab *)h;

	if (vet[posic].conteudo == NULL)
		return NULL;
	
	else
		return (vet[posic].conteudo);
}

//Retorna o elemento seguinte a p
Item get_next_HL(char ch[10], tabelaL p){
	
	if (p == NULL)
		return NULL;
	else{

		info *aux = (info *)p;
		return (aux->prox);
	}
}
