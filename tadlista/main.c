#include <stdio.h>
#include "tadLista.h"

int main(void) {
  Lista *lst;
  Aluno alu;
  lst = criar_lista(100);
  preenche_lista(&alu);
  insere_lista_inicio(lst, alu);
  preenche_lista(&alu);
  insere_lista_final(lst, alu);
  preenche_lista(&alu);  
  insere_lista_ordenada(lst, alu);
  preenche_lista(&alu);  
  insere_lista_ordenada(lst, alu);
  consulta_lista_pos(lst, 1, &alu);
  consulta_lista_mat(lst, 11821213, &alu);
  remove_lista_mat(lst, 11821213);
  tamanho_lista(lst);
  remove_lista_inicio(lst);
  remove_lista_final(lst);
  remove_lista_otimizado(lst, 11821213);
  lista_cheia(lst, 100);
  lista_vazia(lst);
  compactar_lista(lst);
  imprime_lista(lst);
  libera_lista(lst);
  return 0;
}