#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  struct nodeStack *begin;
  int size;
};

struct nodeStack {
  struct nodeStack *next;
  struct Aluno data;
};

typedef struct nodeStack nodeStack;

Stack *stack_create() {
  Stack *stack;
  stack = malloc(sizeof(Stack));
  if(stack != NULL) {
      stack->size = 0;
      stack->begin = NULL;
      return stack;
  }
  return NULL;
}

int stack_free(Stack *stack){
  if(stack == NULL)
    return -1;
  
  else {
    nodeStack *perc;
    perc = stack->begin;
    while(stack->begin != NULL){
      stack->begin = stack->begin->next;
      free(perc);
      perc = stack->begin;
    }
  }
  free(stack);
  return 0;
}

int stack_pop(Stack *stack){
  if(stack == NULL || stack->size == 0)
    return -1;
  
  else{
    nodeStack *p;
    p = stack->begin;
    stack->begin = stack->begin->next;
    free(p);
    stack->size--;
    return 0;
  }
}

int stack_push(Stack *stack, struct Aluno alu){
  if(stack == NULL)
    return -1;

  else {
    nodeStack *ns;
    ns = malloc(sizeof(nodeStack));
    if(ns != NULL){
      ns->data = alu;
      ns->next = stack->begin;
      stack->begin = ns;
      stack->size++;
    }    
    return 0;
  }
}

void stack_print(Stack *stack){
  if(stack == NULL || stack->size == 0)
    return;
  
  else {
    nodeStack *ns;
    ns = stack->begin;
    while(ns != NULL){
      printf("\nMatricula: %d\n",ns->data.matricula);
      printf("Nome: %s\n",ns->data.nome);
      printf("Notas: %.1f %.1f %.1f\n",ns->data.n1,
                                      ns->data.n2,
                                      ns->data.n3);
      printf("-------------------------------\n");
      ns = ns->next;
    }
  }
}

int stack_top(Stack *stack, struct Aluno *alu){
  if(stack == NULL || stack->size == 0)
    return -1;

  else{
    *alu = stack->begin->data;
    return 0;
  }
}

int stack_empty(Stack *stack) {
  if(stack == NULL)
    return -1;
  
  else 
    return (stack->size == 0);
  
}

int stack_size(Stack *stack){
  if(stack == NULL)
    return -1;
  else
    return stack->size;
}

int stack_full(Stack *sstack) {
  return -1;
}