
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arvoreB.h"
#include "arvoreRetangulo.h"
#include "hash_lista.h"


//Contador para armazenar a quantidade de nós da árvore
int cont = 0;
long int cont1=0;
long int Inseridos=0;
long int Removidos=0;


//Estrutura que contém os dados do retângulo
struct retang{
	int op;
	double x;
	double y;
	double larg;
	double alt;
	double area;
	char cor[20];
};
typedef struct retang retang;
 //Estrutura que contem os moradores
struct casa{
	char nome[150];
	char cep[10];
	char face[3];
	char fone[15];
	int n;
};
typedef struct casa casa;

//Estrutura que contem os Estabelecimentos comerciais
struct comercio{
	char nome[150];
	char cep[10];
	char face[3];
	char fone[15];
	char tp[50];
	int n;
};
typedef struct comercio comercio;

struct quadra{
	int op;
	double x;
	double y;
	double larg;
	double alt;
	double area;
	char cor[20];
	char cep[10];
	int pass;
};
typedef struct quadra quadra;

struct equipamento{
	int op;
	double x;
	double y;
	double alt;
	double larg;
	double area;
	char id[10];
	char cor[20];
	char cep[10];
};
typedef struct equipamento equipamento;

//Cria uma árvore vázia
void createArvore (retangulo *raiz){

	*raiz = emptyTree();
}

hash createHashL(){
	void* p = criaTabela_HL();
	return p;
}

hash createHashD(){
	void* d = criaTabela_HD();
	return d;
}

void insereEquipamento (double x, double y,char id[15],char cep[10], retangulo *raiz,int opcao){

	equipamento *novoEquipamento = (equipamento *)malloc(sizeof(equipamento));

	novoEquipamento->x = x;
	novoEquipamento->y = y;
	novoEquipamento->area = x;
	strcpy(novoEquipamento->id,id);
	strcpy(novoEquipamento->cep,cep);
	novoEquipamento->op = opcao;
	novoEquipamento->larg=0;
	novoEquipamento->alt=0;
	cont++;
	Inseridos++;
	
	
	apontNo no = makeTree(novoEquipamento);

	if (*raiz == NULL){

		*raiz = no;
		return;		
	}
	else{

		//ponteiro auxiliar que aponta para a raiz
		apontNo aux = *raiz;
		apontNo aux2;
		//ponteiro que recebe o conteudo de cada nó da árvore
		equipamento *auxEquipamento = (equipamento *) info (aux);
		//entra no while até encontrar a posição certa de inserir
		while(1){

			if(novoEquipamento->area > auxEquipamento->area){
		
				aux2 = right(aux);
				if(aux2 == NULL){

					setRight (aux, no);
					setFather (aux, no);
					return;
				}
				aux = right (aux);
			}
			else{

				aux2 = left(aux);
				if(aux2 == NULL){

					setLeft (aux, no);
					setFather (aux, no);
					return;
				}			
				aux = left (aux);
			}
			auxEquipamento = (equipamento *) info (aux);
		}
	}
}

void insereLoja (char nome[150],char cep[10],char face[3],char fone[15], int n, char tp[50], hash hashDL){
	//printf("TESTE = %s %s %s %s %d %s\n",nome,cep,face,fone,n,tp);
	
	comercio *novaLoja =(comercio *)malloc(sizeof(comercio));
	strcpy(novaLoja->nome,nome);
	strcpy(novaLoja->cep,cep);
	strcpy(novaLoja->face,face);
	strcpy(novaLoja->fone,fone);
	strcpy(novaLoja->tp,tp);
	novaLoja->n = n;
	int resp;
	
	//printf("Teste: %s %s\n",cep,fone);
	resp = put_HL(hashDL, cep, novaLoja, fone);
	//comercio *n2 = (comercio *) get_HD(hashDL, "SE1.1", "7392-5326");
	//printf("TEL: %s\n", n2->tp);
	//printf("TEL: %s\n", n2->nome);
}

void insereCasa (char nome[150],char cep[10],char face[3],char fone[15], int n, hash hashLC){
	//printf("TESTE = %s %s %s %s %d\n",nome,cep,face,fone,n);
	casa *novaCasa =(casa *)malloc(sizeof(casa)); 
	strcpy(novaCasa->nome,nome);
	strcpy(novaCasa->cep,cep);
	strcpy(novaCasa->face,face);
	strcpy(novaCasa->fone,fone);
	novaCasa->n = n;
	int resp;
	resp = put_HL(hashLC, cep, novaCasa, nome);
	//casa *n2 = (casa *) get_HL(hashLC, "SE1.1", "Henrique679918_da_Silva");
	//printf("TEL: %s\n", n2->nome);
	//printf("ok\n");
}

//Insere um retângulo na árvore
void insereRetang (double x, double y, double larg, double alt, char cor[20], retangulo *raiz){

	retang *novoRetangulo = (retang *)malloc(sizeof(retang));
	novoRetangulo->x = x;
	novoRetangulo->y = y;
	novoRetangulo->larg = larg;
	novoRetangulo->alt = alt;
	novoRetangulo->area = x;
	strcpy(novoRetangulo->cor,cor);
	novoRetangulo->op=0;
	
	cont++;
	Inseridos++;

	apontNo no = makeTree(novoRetangulo);

	if (*raiz == NULL){

		*raiz = no;
		return;		
	}
	else{

		//ponteiro auxiliar que aponta para a raiz
		apontNo aux = *raiz;
		apontNo aux2;
		//ponteiro que recebe o conteudo de cada mó da árvore
		retang *auxRetan = (retang *) info (aux);
		//entra no while até encontrar a posição certa de inserir
		while(1){

			if(novoRetangulo->area > auxRetan->area){
		
				aux2 = right(aux);
				if(aux2 == NULL){

					setRight (aux, no);
					setFather (aux, no);
					return;
				}
				aux = right (aux);
			}
			else{

				aux2 = left(aux);
				if(aux2 == NULL){

					setLeft (aux, no);
					setFather (aux, no);
					return;
				}			
				aux = left (aux);
			}
			auxRetan = (retang *) info (aux);
		}
	}
}

//insere quadras na arvore
void insereQuadra (double x, double y, double larg, double alt, char cor[20],char cep[10], retangulo *raiz){
           
 
	quadra *novoQuadra = (quadra *)malloc(sizeof(quadra));
	novoQuadra->x = x;
	novoQuadra->y = y;
	novoQuadra->larg = larg;
	novoQuadra->alt = alt;
	novoQuadra->area = x;
	strcpy(novoQuadra->cor,cor);
	strcpy(novoQuadra->cep,cep);
	novoQuadra->op=1;
	novoQuadra->pass=0;
	apontNo no = makeTree(novoQuadra);
	
	cont++;
	Inseridos++;

	if (*raiz == NULL){

		*raiz = no;
		return;		
	}
	else{

		//ponteiro auxiliar que aponta para a raiz
		apontNo aux = *raiz;
		apontNo aux2;
		//ponteiro que recebe o conteudo de cada nó da árvore
		quadra *auxQuadra = (quadra *) info (aux);
		//entra no while até encontrar a posição certa de inserir
		while(1){

			if(novoQuadra->area > auxQuadra->area){
		
				aux2 = right(aux);
				if(aux2 == NULL){

					setRight (aux, no);
					setFather (aux, no);
					return;
				}
				aux = right (aux);
			}
			else{

				aux2 = left(aux);
				if(aux2 == NULL){

					setLeft (aux, no);
					setFather (aux, no);
					return;
				}			
				aux = left (aux);
			}
			auxQuadra = (quadra *) info (aux);
		}
	}
}



//imprime o campo "área" de todos os nós da árvore
void imprimeDados (retangulo raiz){

	if (raiz == NULL)
		return;
	retang *aux = (retang *) info (raiz);
	printf ("ALTURA: %lf\n", aux->alt);
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeDados (esq);
	imprimeDados(dir);
}



//Remove o(s) nó(s) que esteja dentro ou seja igual do triângulo indicado
void removeRetangulo (double x, double y, double larg, double alt, retangulo *raiz){
	if (*raiz == NULL)
		return;
	retangulo aux = *raiz;
	retang *conteudo = info (aux);
	retangulo pai = father (aux);
	retangulo verifica = left (pai);
	int help = 0;  //Variável que ajuda a verifica qual filho vou remover (direito ou esquerdo)
	retangulo set = aux;
	int v;
	
	if( (conteudo->x >= x) && ((conteudo->x + conteudo->larg) <= (x + larg)) && (conteudo->y >= y) && ((conteudo->y + conteudo->alt) <= (y + alt)) ){
	
		if (verifica == aux)
			help = 1;
		set = Remove (aux);	
		if (help == 1)
			setLeft (pai, set);
		else
			setRight (pai, set);
		if (pai == NULL)
			*raiz = set;
		cont--;
		Removidos++;
		
	}

	if (set == NULL || *raiz == NULL)
		return;

	retangulo esq, dir;	
	esq = left (set); 
	dir = right (set);
	retang *conteudoDIR = (retang *) info(dir);	

	removeRetangulo (x, y, larg, alt, &esq);
	if (dir != NULL)
		if (conteudoDIR->area <= (alt * larg))
			removeRetangulo (x, y, larg, alt, &dir);
}

//Função que retorna  quantidade de nós da árvore
int quantidadeNos (){

	return cont;
}

void imprimeSVG (retangulo raiz,double x,double y,char nomeSVG[100]){
	FILE *arq;

	strcat(nomeSVG,".svg");
	
	arq=fopen(nomeSVG,"w");

    fprintf(arq,"<svg height=\"%lf\" width=\"%lf\">\n",y,x);
	
	fclose(arq);
	
	imprimeRetan(raiz,nomeSVG);
	
	arq=fopen(nomeSVG,"a");
	fprintf(arq,"</svg>");
	fclose(arq);
}

void imprimeRetan (retangulo raiz,char nomeSVG[100]){
	FILE *arq;
	arq=fopen(nomeSVG,"a");
	if (raiz == NULL){
		
		return;}
	retang *aux =  info (raiz);
	quadra *aux1 = info (raiz);
	
	if(aux->op==0){
		fprintf (arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"fill:%s;stroke:black;stroke-width:0.5;\"/>\n", aux->x,aux->y,aux->larg,aux->alt,aux->cor);
	}
	if(aux1->op==1){
		fprintf (arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" style=\"fill:%s;fill-opacity:0.5;\"/>\n", aux1->x,aux1->y,aux1->larg,aux1->alt,aux1->cor);
		fprintf (arq,"<text x=\"%lf\" y=\"%lf\" style=\"fill:black;\">%s</text>\n", aux1->x+((aux1->larg/2)-15),aux1->y+10,aux1->cep);
	}
	if(aux1->op==2){
		fprintf (arq,"<text x=\"%lf\" y=\"%lf\" style=\"fill:yellow;font-size:8px;\">H</text>\n", aux1->x,aux1->y);
	}
	if(aux1->op==3){
		fprintf (arq,"<text x=\"%lf\" y=\"%lf\" style=\"fill:red;font-size:8px;\">S</text>\n", aux1->x,aux1->y);
	}
	if(aux1->op==4){
		fprintf (arq,"<text x=\"%lf\" y=\"%lf\" style=\"fill:white;font-size:15px;\">((C))</text>\n", aux1->x,aux1->y);
	}
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeRetan(esq,nomeSVG);
	imprimeRetan(dir,nomeSVG);
	fclose(arq);
}

void trocaCor (retangulo raiz,char cor1[20], char cor2[20]){

	if (raiz == NULL)
		return;
	retang *aux = (retang *) info (raiz);
	if (strcmp(cor1,aux->cor)==0){
		strcpy(aux->cor,cor2);
		cont1++;
	}
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	trocaCor (esq,cor1,cor2);
	trocaCor (dir,cor1,cor2);

}

void trocaRetan(retangulo *raiz,char cor1[20], char cor2[20], double x, double y, double larg, double alt){
	if (*raiz == NULL)
		return;
	retangulo aux = *raiz;
	retang *conteudo = (retang *) info (aux);
	retangulo pai = father (aux);
	retangulo verifica = left (pai);
	int help = 0;  
	
	if( (conteudo->x >= x) && ((conteudo->x + conteudo->larg) <= (x + larg)) && (conteudo->y >= y) && ((conteudo->y + conteudo->alt) <= (y + alt)) ){
		strcpy(conteudo->cor,cor2);
		cont1++;
	}

	retangulo esq, dir;	
	esq = left (aux); 
	dir = right (aux);
	retang *conteudoDIR = (retang *) info(dir);	

	trocaRetan (&esq,cor1,cor2, x, y, larg, alt);
	if (dir != NULL)
		if (conteudoDIR->area <= (alt * larg))
			trocaRetan (&dir, cor1, cor2, x, y, larg, alt);
	
}

void Resumo(char diretorio[100],char nomeArq[100],long int prof){
	
	FILE *arq;
	strcat(diretorio,"/resumo.txt");
	
	arq=fopen(diretorio,"a");
	
	fprintf(arq,"%s %li %d %li %li %li\n",nomeArq,cont,prof,Inseridos,Removidos,cont1);
	
	fclose(arq);
}


int height(retangulo raiz) {

    int u, v;
    if (raiz == NULL)
		return -1;
	retang *aux = (retang *) info (raiz);
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	u=height (esq);
	v=height(dir);
    if (u > v) return u+1;
    else return v+1;
}



void imprimeEquipamento (retangulo *raiz,char nomeArq[100], double x, double y, double larg, double alt,int opcao){
	
	if (*raiz == NULL)
		return;
	
	FILE *arq;
	arq=fopen(nomeArq,"a");
	
	retangulo aux = *raiz;
	equipamento *conteudo = info (aux);
	retangulo pai = father (aux);
	retangulo verifica = left (pai);
	int help = 0;  
	
	if( (conteudo->x >= x) && ((conteudo->x + conteudo->larg) <= (x + larg)) && (conteudo->y >= y) && ((conteudo->y + conteudo->alt) <= (y + alt))  ){
		if(opcao==2){
			if(conteudo->op==2){
				fprintf (arq,"%s %lf %lf \n",conteudo->id,conteudo->x,conteudo->y);
			}
		}
		if(opcao==3){
			if(conteudo->op==3){
				fprintf (arq,"%s %lf %lf \n",conteudo->id,conteudo->x,conteudo->y);
			}
		}
	}

	retangulo esq, dir;	
	esq = left (aux); 
	dir = right (aux);
	equipamento *conteudoDIR = info(dir);	

	imprimeEquipamento (&esq,nomeArq, x, y, larg, alt,opcao);
	if (dir != NULL)
		if (conteudoDIR->area <= (alt * larg))
			imprimeEquipamento (&dir,nomeArq, x, y, larg, alt,opcao);
	fclose(arq);
}

void imprimeTorre (retangulo *raiz,char nomeArq[100]){
	
	FILE *arq;
	arq=fopen(nomeArq,"a");
	if (raiz == NULL)
		return;
	
	equipamento *aux = info (raiz);
	if(aux->op==4){
		fprintf (arq,"%s\n",aux->cep);
	}
	
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeTorre (esq,nomeArq);
	imprimeTorre(dir,nomeArq);
	fclose(arq);
}

void moradoresRetan (retangulo *raiz,char nomeArq[100], double x, double y, double larg, double alt,hash hash_LC){
	
	if (*raiz == NULL)
		return;
	
	FILE *arq;
	arq=fopen(nomeArq,"a");
	
	retangulo aux = *raiz;
	quadra *conteudo = info (aux);
	retangulo pai = father (aux);
	retangulo verifica = left (pai);
	int help = 0;  
	
	if (conteudo->op==1){
		if( (conteudo->x >= x) && ((conteudo->x + conteudo->larg) <= (x + larg)) && (conteudo->y >= y) && ((conteudo->y + conteudo->alt) <= (y + alt))  ){
			imprimeMoradores(hash_LC,conteudo->cep,nomeArq);
		}
	}
	retangulo esq, dir;	
	esq = left (aux); 
	dir = right (aux);
	equipamento *conteudoDIR = info(dir);	

	moradoresRetan (&esq,nomeArq, x, y, larg, alt,hash_LC);
	if (dir != NULL)
		if (conteudoDIR->area <= (alt * larg))
			moradoresRetan (&dir,nomeArq, x, y, larg, alt,hash_LC);
	fclose(arq);
}

void imprimeMoradores(hash hashLC,char cep[10],char nomeArq[100]){
	FILE *arq;
	arq=fopen(nomeArq,"a");
	casa *aux = (casa *)get_first_HL(hashLC,cep);
	casa *aux1;
	while(aux!=NULL){
		aux1 = get_HL(aux);
		fprintf(arq,"%s %s %s %d %s\n",aux1->nome, aux1->fone, aux1->face, aux1->n, aux1->cep);
		aux = get_next_HL(cep,aux);
	}
	fclose(arq);
}

void imprimeLoja(hash hashDL,char cep[10]){
	comercio *aux = (comercio *)get_first_HL(hashDL,cep);
	comercio *aux1;
	while(aux!=NULL){
		aux1=(comercio *)get_HL(aux);
		printf("%s\n",aux1->tp);
		aux = get_next_HL(cep,aux);
	}
}

void imprimeFace(retangulo *raiz,char nomeArq[100],char face[3], double larg){
	FILE *arq;
	arq=fopen(nomeArq,"a");
	char aux1[10];
	if (raiz == NULL)
		return;
	equipamento *aux = info (raiz);
	if(aux->op==2){
		if (aux->x <= larg){
			strcpy(aux1,aux->id);
			if(aux1[1]==face[0]){
				fprintf (arq,"%s %lf %lf \n",aux->id,aux->x,aux->y);
			}
		}
	}
	
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeFace(esq,nomeArq,face,larg);
	imprimeFace(dir,nomeArq,face,larg);
	fclose(arq);
}


void imprimeComercioQuadra(retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100]){

	char cep[10];
	char cepaux[10];
	if (raiz == NULL)
		return;
	quadra *aux = info (raiz);
	strcpy(cep,aux->cep);
	if(aux->op==1){
			verificaLoja(hashDL,cep,tp,nomeArq);
	}
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeComercioQuadra(esq,hashDL,tp,nomeArq);
	imprimeComercioQuadra(dir,hashDL,tp,nomeArq);
}

void imprimeComercioRetan(retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100], double x, double y, double larg, double alt){

	char cep[10];
	char cepaux[10];
	char pai[10];
	if (raiz == NULL)
		return;
	quadra *aux = info (raiz);
	strcpy(cep,aux->cep);
	
	if(aux->op==1){
		if( (aux->x >= x) && ((aux->x + aux->larg) <= (x + larg)) && (aux->y >= y) && ((aux->y + aux->alt) <= (y + alt))  ){
			verificaLoja(hashDL,cep,tp,nomeArq);
		}
	}
	
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeComercioRetan(esq,hashDL,tp,nomeArq,x,y,larg,alt);
	imprimeComercioRetan(dir,hashDL,tp,nomeArq,x,y,larg,alt);
}

void verificaLoja(hash hashDL,char cep[10],char tp[50],char nomeArq[100]){
	
	FILE *arq;
	arq=fopen(nomeArq,"a");
	comercio *aux = (comercio *)get_first_HL(hashDL,cep);
	comercio *aux1;
	while(aux!=NULL){
		aux1=(comercio *)get_HL(aux);
		if (strcmp(aux1->tp,tp)==0){
			fprintf (arq,"%s %s %s %d \n",aux1->tp,aux1->cep,aux1->face,aux1->n);
		}
		aux = get_next_HL(cep,aux);
	}
	fclose(arq);	
}

void imprimeLojas (retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100]){
	
	char cep[10];
	char cepaux[10];
	if (raiz == NULL)
		return;
	quadra *aux = info (raiz);
	strcpy(cep,aux->cep);
	if(aux->op==1){
		if(tp[0]=='*'){
			escreveTodos(hashDL,cep,tp,nomeArq);
		}
		else{
			escreveTP(hashDL,cep,tp,nomeArq);
		}
	}
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeLojas(esq,hashDL,tp,nomeArq);
	imprimeLojas(dir,hashDL,tp,nomeArq);
}

void imprimeLojasRetan (retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100], double x, double y, double larg, double alt){
	char cep[10];
	char cepaux[10];
	if (raiz == NULL)
		return;
	quadra *aux = info (raiz);
	strcpy(cep,aux->cep);		
	if(aux->op==1){
		if( (aux->x >= x) && ((aux->x + aux->larg) <= (x + larg)) && (aux->y >= y) && ((aux->y + aux->alt) <= (y + alt))  ){
			if(tp[0]=='*' || tp[1]=='*'){
				escreveTodos(hashDL,cep,tp,nomeArq);
			}
			else{
				escreveTP(hashDL,cep,tp,nomeArq);
			}
		}
	}
	retangulo esq, dir;
	esq = left (raiz);
	dir =  right (raiz);
	imprimeLojasRetan(esq,hashDL,tp,nomeArq,x,y,larg,alt);
	imprimeLojasRetan(dir,hashDL,tp,nomeArq,x,y,larg,alt);
}

void escreveTP(hash hashDL,char cep[10],char tp[50],char nomeArq[100]){
	
	FILE *arq;
	arq=fopen(nomeArq,"a");
	comercio *aux = (comercio *)get_first_HL(hashDL,cep);
	comercio *aux1;
	while(aux!=NULL){		
		aux1=(comercio *)get_HL(aux);
		if (strcmp(aux1->tp,tp)==0){
			fprintf (arq,"%s %s %s %d \n",aux1->tp,aux1->cep,aux1->face,aux1->n);
		}
		aux = get_next_HL(cep,aux);
	}
	fclose(arq);	
}

void escreveTodos(hash hashDL,char cep[10],char tp[50],char nomeArq[100]){
	
	FILE *arq;
	arq=fopen(nomeArq,"a");
	comercio *aux = (comercio *)get_first_HL(hashDL,cep);
	comercio *aux1;
	while(aux!=NULL){
		aux1=(comercio *)get_HL(aux);
		fprintf (arq,"%s %s %s %s %s %d \n",aux1->tp,aux1->nome,aux1->fone,aux1->cep,aux1->face,aux1->n);
		aux = get_next_HL(cep,aux);
	}
	fclose(arq);	
}
