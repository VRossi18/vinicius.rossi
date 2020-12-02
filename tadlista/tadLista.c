#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "tadLista.h"

struct lista {
  int qtd;
  int tamanho_inicial;
  int tamanho_atual;
  struct aluno*dados;
};

Lista *criar_lista(int size) {
  Lista *li;
  li = (Lista *)malloc(sizeof(struct lista));
  if(li!=NULL){
    li->qtd=0;
    li->dados = malloc(size*sizeof(struct aluno));
    if(li->dados != NULL){
      li->tamanho_inicial = size;
      li->tamanho_atual = size;
      return li;
    }
  }
  return NULL;
}

void libera_lista(Lista *lst) {
  free(lst->dados);
  free(lst);
}

int consulta_lista_pos(Lista *lst, int posicao, struct aluno *alu) {
  if(lst == NULL || posicao <= 0 || posicao > lst->qtd)
    return -1;

  else 
    *alu=lst->dados[posicao -1];
  
  return 1;
}

int consulta_lista_mat(Lista *lst, int mat, struct aluno *alu) {
  if(lst == NULL)
    return 0;
  int i = 0;
  while(i < lst->qtd && lst->dados[i].matricula != mat)
    i++;
  if(i == lst->qtd)
    return 0;
  *alu = lst->dados[i];
  return 1;
}

int insere_lista_final(Lista *lst, struct aluno alu) {
  if(lst==NULL)
    return -1;
  
  if(lst->qtd == lst->tamanho_atual)
    lst->dados = realloc(lst->dados, (lst->tamanho_atual + lst->tamanho_inicial)*sizeof(struct aluno));
    if(lst->dados == NULL)
      return -1;
    lst->tamanho_atual += lst->tamanho_inicial;
  lst->dados[lst->qtd]=alu;
  lst->qtd++;
  return 0;
}

int insere_lista_inicio(Lista *lst, struct aluno alu) {
  if(lst == NULL)
    return -1;
  
  if(lst->qtd == lst->tamanho_atual)
    lst->dados = realloc(lst->dados, (lst->tamanho_atual + lst->tamanho_inicial)*sizeof(struct aluno));

    if(lst->dados == NULL)
      return -1;

  lst->tamanho_atual += lst->tamanho_inicial;

  for(int i=lst->qtd-1; i >= 0; i--) 
    lst->dados[i+1] = lst->dados[i];
  
  lst->dados[0]=alu;
  lst->qtd++;
  return 0;
}

int insere_lista_ordenada(Lista *lst, struct aluno alu) {
  if(lst == NULL)
    return 0;

  if(lst->qtd == lst->tamanho_atual)
    lst->dados = realloc(lst->dados, (lst->tamanho_atual + lst->tamanho_inicial)*sizeof(struct lista));
    if (lst->dados == NULL)
      return 0;
  lst->tamanho_atual += lst->tamanho_inicial;
  int i = 0, k = 0;
  while(i < lst->qtd && lst->dados[i].matricula < alu.matricula)
    i++;
  for(k = lst->qtd-1; k >= i; k--)
    lst->dados[k+1] = lst->dados[k];
  lst->dados[i] = alu;
  lst->qtd++;

  return 1;
}

int remove_lista_mat(Lista *lst, int mat) {
  if(lst == NULL)
    return 0;
  if(lst->qtd == 0)
    return 0;
  
  int i = 0, k = 0;
  while(i < lst->qtd && lst->dados[i].matricula != mat)
    i++;

  if(i == lst->qtd)
    return 0;

  for(int k = i; k < lst->qtd-1; k++)
    lst->dados[k] = lst->dados[k+1];

  lst->qtd--;

  return 1;
}

int remove_lista_otimizado(Lista *lst, int mat) {
  if(lst == NULL)
    return 0;

  if(lst->qtd == 0)
    return 0;

  int i = 0;
  while(i < lst->qtd && lst->dados[i].matricula != mat)
    i++;

  if(i == lst->qtd)
    return 0;
  lst->dados[i] = lst->dados[lst->qtd-1];
  lst->qtd--;

  return 1;
}

int remove_lista_inicio(Lista *lst) {
  if(lst==NULL || lst->qtd==0)
    return -1;
  int i=0;
  for(int i = 0;i < lst->qtd-1;i++)
    lst->dados[i]=lst->dados[i+1];
  
  lst->qtd--;
  return 0;
}

int remove_lista_final(Lista *lst){
  if(lst==NULL || lst->qtd==0)
    return -1;

  lst->qtd--;
  return 0;
}

int tamanho_lista(Lista *lst){
  if(lst==NULL)
    return -1;

  return lst->qtd;
}

int lista_cheia(Lista *lst, int tam){
  if(lst == NULL)
    return 0;
  return (lst->qtd == tam);
}

int lista_vazia(Lista *lst){
  if(lst == NULL)
    return 0;
  return (lst->qtd == 0);
}

void preenche_lista(struct aluno *alu) {
  printf("Matricula: ");
  scanf("%d", &alu->matricula);
  setbuf(stdin, NULL);
  printf("Nome: ");
  gets(alu->nome);
  setbuf(stdin, NULL);
  printf("Digite as 3 notas: ");
  scanf("%f %f %f", &alu->n1, &alu->n2, &alu->n3);
  setbuf(stdin, NULL);
}

void imprime_lista(Lista *lst){
  if(lst == NULL)
    return;
    
  for(int i = 0; i < lst->qtd; i++){
    printf("Matricula: %d\n", lst->dados[i].matricula);
    printf("Nome: %s\n", lst->dados[i].nome);
    printf("Notas: %.1f %.1f %.1f\n\n", lst->dados[i].n1, lst->dados[i].n2, lst->dados[i].n3);
  }
}

int compactar_lista(Lista *lst){
  if(lst == NULL)
    return 0;

  lst->dados = realloc(lst->dados, ceil(lst->qtd/lst->tamanho_inicial)*lst->tamanho_inicial*sizeof(struct aluno));
  return 1;
}