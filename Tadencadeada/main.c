#include <stdio.h>
#include<stdlib.h>
#include "tad.h"


int main(void) {
  List* lst;
  lst = list_create();
  Aluno alu1, alu2;

  for(int i = 0; i <2;i++) {
    preenche_lista(&alu1);
    list_push_front(lst, alu1);
  }

  list_pop_back(lst);
  list_print(lst);

  return 0;
}