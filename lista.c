#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

//estrututa para manipular a lista
struct lista{

    ponteiro elemento;
    struct lista *prox;
};
typedef struct lista lista;

//estrutura que contem um ponteiro pro fim e um ponteiro pro inicio da lista
struct controlador{

	lista *inicio;
	lista *fim;
};
typedef struct controlador controlador;

//funca para inicializar a lista
ponteiro create_lista(int tam){

    controlador *aux=(controlador *)malloc(sizeof(controlador));
	aux->inicio=NULL;
	aux->fim=NULL;

	return aux;
}

//funcao para inserir na lista, retorna um indicador para o elemento acrescentado
void insert_lista(ponteiro p, ponteiro conteudo){

    lista *nova=(lista *)malloc(sizeof(lista));
    controlador *aux=(controlador *)p;
	lista *aux2=aux->fim;

    nova->elemento=conteudo;
    nova->prox=NULL;
    if(aux->inicio==NULL){

        aux->inicio=nova;
		aux->fim=nova;
        //return (nova);
    }
    else{

        aux2->prox=nova;
        aux->fim=nova;
    }
    //return (nova);
}

//funcao para ver o tamanho da lista
int length(ponteiro p){

	controlador *aux2=(controlador *)p;
	lista *aux=(lista *)aux2->inicio;
    int i=0;

    while(aux!=NULL){

        aux=aux->prox;
        i++;
    }
    return i;
}

//funcao para remover um item da lista
void remove_lista(ponteiro p, ponteiro posic){

	controlador *aux3=(controlador *)p;
	lista *aux=(lista *)aux3->inicio;
	lista *aux2;

    if(aux3->inicio!=NULL){

        if(aux3->inicio==posic){

            aux3->inicio=aux->prox;
            free(aux);
            return;
        }

        while(aux!=posic){

            aux2=aux;
            aux=aux->prox;
        }
        aux2->prox=aux->prox;
		if(aux->prox==NULL)
			aux3->fim=aux2;
        free(aux);

        return;
    }
}

//funcao que retorna o endereço do campo "item" da lista
ponteiro get_lista(ponteiro p, ponteiro posic){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)aux->inicio;
	lista *aux3=(lista *)posic;

	if(aux2!=NULL)
		return(aux3->elemento);
    else
        return(NULL);
}

//insere antes do item indicado
ponteiro insert_before(ponteiro p, ponteiro posic, ponteiro conteudo){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)posic;
	lista *aux3=(lista *)aux->inicio;
	lista *aux4;
	lista *nova=(lista *)malloc(sizeof(lista));
	nova->elemento=conteudo;
	if(aux->inicio==aux2){

		nova->prox=aux2;
		aux->inicio=nova;
		return(nova);
	}
	while(aux3!=posic){

		aux4=aux3;
		aux3=aux3->prox;
	}
	aux4->prox=nova;
	nova->prox=aux3;
	return(nova);
}

//insere depois do item indicado
ponteiro insert_after(ponteiro p, ponteiro posic, ponteiro conteudo){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)posic;
	lista *nova=(lista *)malloc(sizeof(lista));

	nova->elemento=conteudo;
	nova->prox=aux2->prox;
	aux2->prox=nova;
	if(nova->prox==NULL)
		aux->fim=nova;
	return(nova);
}

//retorna o primeiro elemento da lista
ponteiro get_first(ponteiro p){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)aux->inicio;
	if(aux2==NULL)
		return NULL;
	return (aux2);
}

//retorna elemento seguinte a posic da lista
ponteiro get_next(ponteiro p, ponteiro posic){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)posic;

	if(aux->inicio!=NULL){

        if(aux2->prox==NULL)
            return(NULL);

        return(aux2->prox);
    }
    return NULL;
}

//retorna o ultimo elemento da lista
ponteiro get_last(ponteiro p){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)aux->fim;
	return(aux2);
}

//indica um elemento existente na lista
ponteiro get_previous(ponteiro p, ponteiro posic){

    controlador *aux=(controlador *)p;
	lista *aux2=(lista *)aux->inicio;
	lista *aux3;

	if(aux->inicio==posic)
		return NULL;
	while(aux2!=posic){

		aux3=aux2;
		aux2=aux2->prox;
	}
	return(aux3);
}
