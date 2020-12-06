struct aluno {
  int matricula;
  char nome[50];
  float n1,n2,n3;
};

typedef struct lista Lista;
typedef struct aluno Aluno;
Lista *criar_lista(int size); 
void libera_lista(Lista *lst); 
int consulta_lista_pos(Lista *lst, int pos, struct aluno *alu);
int consulta_lista_mat(Lista *lst, int mat, struct aluno *alu);
int insere_lista_final(Lista *lst, struct aluno alu); 
int insere_lista_inicio(Lista *lst, struct aluno alu); 
int insere_lista_ordenada(Lista *lst, struct aluno alu); 
int remove_lista_mat(Lista *lst, int mat); 
int remove_lista_inicio(Lista *lst); 
int remove_lista_final(Lista *lst); 
int remove_lista_otimizado(Lista *lst, int mat); 
int tamanho_lista(Lista *lst); 
int lista_cheia(Lista *lst, int size); 
int lista_vazia(Lista *lst); 
void preenche_lista(struct aluno *alu); 
void imprime_lista(Lista *lst); 
int compactar_lista(Lista *lst); 