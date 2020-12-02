struct aluno{
  int mat;
  char nome[50];
  float n1,n2,n3;
};

typedef struct aluno Aluno;
typedef struct list List;
List *list_create();
void list_free(List *lst);
int list_push_front(List *lst, struct aluno alu);
int list_push_back(List *lst, struct aluno alu);
int list_pop_front(List *lst);
int list_pop_back(List *lst);
int list_find_mat(List *lst, int nmat, struct aluno *alu);
int list_find_pos(List *lst, int pos, struct aluno *alu);
int list_size(List *lst);
int lista_cheia(List *lst);
int lista_vazia(List* lst);
void list_print(List *lst);
void preenche_lista(struct aluno *alu);
int list_insert(List *lst, int pos, struct aluno alu);
int list_insert_sorted(List *lst, struct aluno alu);
int list_erase(List *lst, int pos);