#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
char pilha[N];
int t;

void criapilha (void) {
   t = 0;
}

void empilha (char y) {
   pilha[t++] = y;
}

char desempilha (void) {
   return pilha[--t];
} 

int pilhavazia (void) {
   return t <= 0;
}

char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf; 
   posf = malloc ((n+1) * sizeof (char));
   criapilha ();
   empilha (inf[0]);       // empilha '('

   int j = 0;
   for (int i = 1; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char x;
         case '(': empilha (inf[i]);
                   break;
         case ')': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   break;
         case '+': 
         case '-': x = desempilha ();
                   while (x != '(') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i]);
                   break;
         case '*':
         case '/': x = desempilha ();
                   while (x != '(' && x != '+' && x != '-') {
                      posf[j++] = x;
                      x = desempilha ();
                   }
                   empilha (x);
                   empilha (inf[i]);
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';      
   return posf;
}

int main(){
  char inf[30];
  char *posf;
  scanf("%s", inf);
  posf = infixaParaPosfixa(inf);
  printf("Formula posfixa: %s", posf);
  return 0;
}