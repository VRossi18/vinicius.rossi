#include <stdio.h>
#include "pilha.h"

void fill_stack (struct Aluno *alu) {  
    printf("Matricula: ");
    scanf("%d", &alu->matricula);

    setbuf(stdin, NULL);
    printf("Nome: ");
    scanf("%[^\n]%*c", alu->nome);
    setbuf(stdin, NULL);

    printf("Digite as 3 notas: ");
    scanf("%f %f %f", &alu->n1, &alu->n2, &alu->n3);
    setbuf(stdin, NULL);
  }

int main(void) {
    Stack *stack;
    Aluno alu;
    stack = stack_create();
    if (stack == NULL)
      printf("Erro ao criar pilha.\n");
      
    fill_stack(&alu);
    stack_push(stack, alu);

    fill_stack(&alu);
    stack_push(stack, alu);

    fill_stack(&alu);
    stack_push(stack, alu);
    
    stack_print(stack);
    printf("\n\nRemovendo um elemento.\n\n");

    stack_pop(stack);
    stack_print(stack);
    stack_free(stack);
    return 0;
  }