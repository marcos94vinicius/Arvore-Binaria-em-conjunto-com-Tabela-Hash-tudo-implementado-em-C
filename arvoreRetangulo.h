#ifndef arvoreRetangulo_INCLUDED
#define arvoreRetangulo_INCLUDED

//indica um nó da arvore
typedef void* retangulo;
typedef void* hash;

//Cria uma árvore vázia
void createArvore (retangulo *raiz);

//Insere um retângulo na árvore
void insereRetang (double x, double y, double larg, double alt, char cor[20], retangulo *raiz);


//Troca a cor dos retângulos de cor1 para cor2
void trocaCor (retangulo raiz,char cor1[20], char cor2[20]);

//Imprime os dados da árvore.
void imprimeDados (retangulo raiz);

//Remove o(s) nó(s) que esteja dentro ou seja igual do triângulo indicado
void removeRetangulo (double x, double y, double larg, double alt, retangulo *raiz); 

//Função que retorna  quantidade de nós da árvore
int quantidadeNos ();

// Gera o arquivo svg
void imprimeSVG (retangulo raiz,double x,double y,char sufixo[100]);

//funçao do imprime svg
void imprimeRetan (retangulo raiz,char nomeSVG[100]);

//verifica se um retangulo esta contido em outro
int VerRetan(double x, double y, double larg, double alt,double x1, double y1, double larg1, double alt1);

//troca a cor dos retangulos contidos no retangulo passado por parametro
void trocaRetan(retangulo *raiz,char cor1[20], char cor2[20], double x, double y, double larg, double alt);

// gera o resumo do teste
void Resumo(char diretorio[100],char nomeArq[100],long int prof);

//profundidade da arvore
int height(retangulo raiz);

//insere uma casa na hash
void insereCasa (char nome[150],char cep[10],char face[3],char fone[15],int n, hash hashL);

//insere Loja
void insereLoja (char nome[150],char cep[10],char face[3],char fone[15], int n, char tp[50], hash hashDL);

//cria hash lista
hash createHashL();

//cria hash dupla
hash createHashD();

//insere uma quadra na arvore
void insereQuadra (double x, double y, double larg, double alt, char cor[20],char cep[10], retangulo *raiz);

//insere um equipamento na arvore
void insereEquipamento(double x, double y,char id[15],char cep[10],retangulo *raiz,int opcao);


//imprime os equipamentos dentro de uma area passada por parametro
void imprimeEquipamento(retangulo *raiz,char nomeArq[100], double x, double y, double larg, double alt,int opcao);

//imprime as quadras com torre de celular
void imprimeTorre (retangulo *raiz,char nomeArq[100]);

//imprime os moradores em relaçao ao cep
void imprimeMoradores(hash hashLC,char cep[10],char nomeArq[100]);

void imprimeLoja(hash hashDL,char cep[10]);

//imprime todos os moradores dentro das quadra contidas no retangulo passado por parametro
void moradoresRetan (retangulo *raiz,char nomeArq[100], double x, double y, double larg, double alt,hash hash_LC);

//imprime face
void imprimeFace(retangulo *raiz,char nomeArq[100],char face[3], double larg);

//imprime quadras com estabelecimentos do tipo tp 
void imprimeComercioQuadra(retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100]);

//printa lojas 
void verificaLoja(hash hashDL,char cep[10],char tp[50],char nomeArq[100]);

void imprimeComercioRetan(retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100], double x, double y, double larg, double alt);

//escreve comparando tps
void ecreveTP(hash hashDL,char cep[10],char tp[50],char nomeArq[100]);

//escreve td da lista
void escreveTodos(hash hashDL,char cep[10],char tp[50],char nomeArq[100]);

//escreve detalhe s da loja
void imprimeLojas (retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100]);

//escreve detalhes das lojas contidas dentro do retangulo passado por parametro
void imprimeLojasRetan (retangulo *raiz,hash hashDL,char tp[50],char nomeArq[100], double x, double y, double larg, double alt);

#endif // arvoreRetangulo_INCLUDED
