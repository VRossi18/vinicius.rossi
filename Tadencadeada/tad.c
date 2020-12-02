#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "tad.h"

#define SUCCESS 0
#define OUT_OF_MEMORY -1

typedef struct list_node list_node;
struct list{
 list_node *head;
};
struct list_node{
 struct aluno data;
 list_node *next;
};

List *list_create(){
  List *lst;
  lst = malloc(sizeof(List));
  if(lst == NULL)
    return NULL;
  lst->head = NULL;
  return lst;
}

void list_free(List *lst){
  if(lst == NULL)
    return;
  list_node *node;
  while(lst->head != NULL){
    node = lst->head;
    lst->head = lst->head->next;
    free(node);
  }
  free(lst);
}

int list_push_front(List *lst, struct aluno al){
  if(lst == NULL)
    return OUT_OF_MEMORY;
  list_node *node;
  node = (list_node *)malloc(sizeof(list_node));
  if(node == NULL)
    return OUT_OF_MEMORY;
  node->data = al;
  node->next = lst->head;
  lst->head = node;
  return SUCCESS;
}

int list_push_back(List *lst, struct aluno alu){
  if(lst == NULL)
    return OUT_OF_MEMORY;
  list_node *node, *teste;
  node = (list_node *)malloc(sizeof(list_node));
  if(node == NULL)
    return OUT_OF_MEMORY;
  node->data = alu;
  if(lst->head == NULL){
    node->next = NULL;
    lst->head = node;
    return SUCCESS;
  }
  teste = lst->head;
  while(teste->next != NULL){
    teste = teste->next;
  }
  if(teste->next == NULL){
    node->next = teste->next;
    teste->next = node;
    return SUCCESS;
  }
  return SUCCESS;
}

int list_pop_front(List *lst){
  if(lst == NULL)
    return OUT_OF_MEMORY;
    
  if(lst->head == NULL)
    return OUT_OF_MEMORY;
    
  list_node *node;
  node = lst->head;
  lst->head = node->next;
  free(node);
  return SUCCESS;
}

int list_pop_back(List *lst){
  if(lst == NULL)
    return OUT_OF_MEMORY;

  if(lst->head == NULL)
    return OUT_OF_MEMORY;

  list_node *prev, *node;
  node = lst->head;
  while(node->next != NULL) {
    prev = node;
    node = node->next;
  }
  if(node == lst->head) {
    lst->head = NULL;
  }
  else {
    prev->next = node->next;
  }
  free(node);
  return SUCCESS;
}

int list_find_mat(List *lst, int nmat, struct aluno *alu){
  if(lst == NULL || lst->head == NULL)
    return SUCCESS;
  list_node *node;
  node = lst->head;
  while(node != NULL && node->data.mat != nmat)
    node = node->next;

  if(node->data.mat != nmat)
    return OUT_OF_MEMORY;

  else {
    *alu = node->data;
    return SUCCESS;
  }
}

int list_find_pos(List *lst, int pos, struct aluno *alu){
  if(lst == NULL || lst->head == NULL || pos <= 0)
    return OUT_OF_MEMORY;
  list_node *node;
  node = lst->head;
  int i = 1;
  while(node != NULL && i < pos){
    node = node->next;
    i++;
  }
  if(node == NULL)
    return OUT_OF_MEMORY;

  else {
    *alu = node->data;
    return SUCCESS;
  }
}

int list_size(List *lst){
  if(lst == NULL)
    return OUT_OF_MEMORY;

  if(lst->head == NULL)
    return SUCCESS;

  list_node *node;
  node = lst->head;
  int i = 0;
  while(node != NULL){
    node = node->next;
    i++;
  }
  return i;
}

int lista_cheia(List *lst){
  return OUT_OF_MEMORY;
}

int lista_vazia(List* lst){
  if(lst == NULL)
    return OUT_OF_MEMORY;

  if(lst->head == NULL)
    return SUCCESS;

  return SUCCESS;
}

void list_print(List *lst){
  if(lst == NULL || lst->head == NULL)
    return;

  list_node* node = lst->head;
  while(node != NULL) {
    printf("Matricula: %d\n",node->data.mat);
    printf("Nome: %s\n",node->data.nome);
    printf("Notas: %.1f %.1f %.1f\n",node->data.n1,
                                     node->data.n2,
                                     node->data.n3);
    printf("-------------------------------\n");
    node = node->next;
    }
}

void preenche_lista(struct aluno *alu){
  printf("Matricula: ");
  scanf("%d", &alu->mat);
  setbuf(stdin, NULL);
  printf("Nome: ");
  gets(alu->nome);
  setbuf(stdin, NULL);
  printf("Digite as 3 notas: ");
  scanf("%f %f %f", &alu->n1, &alu->n2, &alu->n3);
  setbuf(stdin, NULL);
}

int list_insert(List *lst, int pos, struct aluno alu){
  if(lst == NULL)
    return OUT_OF_MEMORY;
  list_node *node, *teste, *prev;

  int i = 1;
  node = malloc(sizeof(list_node));
  if(node == NULL)
    return OUT_OF_MEMORY;

  node->data = alu;

  if(lst->head == NULL) {
    node->next = NULL;
    lst->head = node;
    return SUCCESS;
  }
  teste = lst->head;
  while(teste != NULL && i < pos){
    prev = teste;
    teste = teste->next;
    i++;
  }
  if(teste == NULL){
    node->next = teste;
    prev->next = node;
    return SUCCESS;
  }
  if(lst->head == teste){
    node->next = lst->head;
    lst->head = node;
    return SUCCESS;
  }
  return SUCCESS;
}

int list_insert_sorted(List *lst, struct aluno alu){
  if(lst == NULL)
    return OUT_OF_MEMORY;

  list_node *node, *teste, *prev;
  node = malloc(sizeof(list_node));
  if(node == NULL)
    return OUT_OF_MEMORY;
  node->data = alu;
  if(lst->head == NULL){
    node->next = NULL;
    lst->head = node;
    return SUCCESS;
  }
  teste = lst->head;
  while(teste != NULL && teste->data.mat < alu.mat) {
    prev = teste;
    teste = teste->next;
  }
  if(lst->head == teste) {
    node->next = lst->head;
    lst->head = node;
    return SUCCESS;
  }
  if(teste == NULL) {
    prev->next = node;
    node = NULL;
    return SUCCESS;
  }
  else {
    node->next = teste;
    prev->next = node;
    return SUCCESS;
  }
}

int list_erase(List *lst, int pos){
  if(lst == NULL)
    return OUT_OF_MEMORY;
  if(lst->head == NULL)
    return OUT_OF_MEMORY;
    
  list_node *node, *prev;
  node = lst->head;

  while(node != NULL && node->data.mat != pos){
    prev = node;
    node = node->next;
  }

  if(node == NULL)
    return OUT_OF_MEMORY;

  if(node == lst->head) {
    lst->head = node->next;
    free(node);
    return SUCCESS;
  }
  else {
    prev->next = node->next;
    free(node);
    return SUCCESS;
  }
}