#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash_duplo.h"

//estrutura para auxiliar na busca dos dados
struct dados{

    void *ponteiro;
    char chave[10];
	long int prox;
};
typedef struct dados dados;

//retorna uma tabela de espalhamento vazia
tabelaD criaTabela_HD(){

     dados *Hash = (dados *)malloc(500000 * sizeof(dados));

    long int i = 0;
    while (i < 500000){

        Hash[i].ponteiro = NULL;
        strcpy(Hash[i].chave, "vazio");
		Hash[i].prox = -1;
		i++;
    }

    return Hash;
}

//função que calcula a posição do dado a ser inserido
long int calcula_HD (char ch[10]){

    long int i = 1, j = 0;
    long int posic = 0;

    while (ch[j] != '\0'){

        if (ch[j] != '-'){

            posic += ch[j]*i;
            i++;
        }
        j++;
    }
    while(posic >= 500000){

        if (posic % 500000 >= 1)
            posic -= 500000;
    }

    return posic;
}

//função que recalcula a posição do dado a ser inserido
long int calcula2_HD (char ch[10]){

    long int posic = calcula_HD(ch);
    long int posic2 = posic % 500000;

    return posic2;
}

//adiciona a tupla <ch,v> à vetor. Retorna 1, se a tupla foi efetivamente adicionada; 0, caso contrário.
long int put_HD (tabelaD vetor, char ch[10], Item v, char id[10]){

   	long int posic = calcula_HD(ch);
    long int posic2 = calcula2_HD(ch);
    long int aux;
    dados *vet = (dados *)vetor;
    long int r =0, i = 0;
printf("posic: %li\n", posic);
    if (vet[posic].ponteiro == NULL){

        strcpy(vet[posic].chave, id);
        vet[posic].ponteiro = v;
		aux = posic + 1*(posic2);
		aux = aux % 500000;
		vet[posic].prox = aux;
        r = 1;
    }
    else{

        while(1){

            aux = posic + i*(posic2);
            while (aux >= 500000)
                aux -= 500000;
            if (vet[aux].ponteiro == NULL){

                strcpy(vet[aux].chave, id);
                vet[aux].ponteiro = v;
				long int aux2 = posic + (i + 1)*posic2;
				aux2 = aux2 % 500000;
				vet[aux].prox = aux2;
                r = 1;
                break;
            }
            i++;
        }
    }
    return r;
}

//retorna verdadeiro se H contém uma tupla t tal que #1(t)=ch.
long int exists_HD (tabelaD vetor, char ch[10], char id[10]){

    long int posic = calcula_HD(ch);
    long int posic2 = calcula2_HD(ch);
    long int aux;
    dados *vet = (dados *)vetor;
    long int r =0, i;

    if (strcmp(vet[posic].chave, id) == 0 && vet[posic].ponteiro != NULL)
        r = 1;
    else{

        i = 0;
        while(1){

            aux = posic + i*(posic2);
            while (aux >= 500000)
                aux -= 500000;
            if (strcmp(vet[aux].chave, id) == 0 && vet[aux].ponteiro != NULL){

                r = 1;
                break;
            }
            i++;
        }
    }
    return r;
}

//GET (h, ch). Seja a tupla <ch, v> contida em h retorna v.
Item get_HD (long int posic, tabelaD h){

	
    dados *aux = (dados *)h;
	
	return (aux[posic].ponteiro); 
}

//Remove um elemento da tabela
void remove_HD (tabelaD h, char ch[10], char id[10]){

    long int r = exists_HD(h, ch, id);
    if (r == 0)
        return;
    else{

        long int posic = calcula_HD(ch);
        long int posic2 = calcula2_HD(ch);
        long int aux;
        dados *vet = (dados *)h;
        long int i;

        if (strcmp(vet[posic].chave, id) == 0){

            vet[posic].ponteiro = NULL;
            strcpy(vet[posic].chave, "vazio");
            return;
        }

        else{

            i = 0;
            while(1){

                aux = posic + i*(posic2);
                while (aux >= 500000)
                    aux -= 500000;
                if (strcmp(vet[aux].chave, id) == 0){

                    vet[aux].ponteiro = NULL;
                    strcpy(vet[aux].chave, "vazio");
                    return;
                }
                i++;
            }
        }
    }
}

//Retorna o primeiro elemento da lista da chave ch
long int get_first_HD(tabelaD h, char ch[10]){

	dados *vet = (dados *)h;
	long int posic = calcula_HD(ch);

	if (vet[posic].ponteiro == NULL)
		return -1;
	else
		return posic;
}

//Retorna o elemento seguinte a p
long int get_next_HD(tabelaD h, long int posic){

	dados *vet = (dados *)h;
	
	return (vet[posic].prox);
}
