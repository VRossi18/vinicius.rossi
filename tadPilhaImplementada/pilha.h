#ifndef pilha
#define pilha


#include "aluno.h"

typedef struct Stack Stack;
Stack *stack_create();
int stack_free(Stack *stack);
int stack_pop(Stack *stack);
int stack_push(Stack *stack, struct Aluno alu);
void stack_print(Stack *stack);
int stack_top(Stack *stack, struct Aluno *alu);
int stack_empty(Stack *stack);
int stack_size(Stack *stack);
int stack_full(Stack *stack);

#endif