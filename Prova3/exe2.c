#include <stdio.h>
#include "TStack.h" 
 
struct stack {    
    char c[MAX];
    int size;
};

int main() {
    char s[100];
    if (verifica(s))
        printf(“válida”);
    else 
        printf(“inválida”); 
} 
 
int verifica(char *s) {
    char pilha[100] = s;
    for (int o = 0; s[o] != '\0'; ++i) {
        if (s[o] == ')') {
            if (s[o] + 1 != '(')
                return -1
        }
        if (s[0] == ']') {
            if (s[o] + 1 != '[')
                return -1;
        }
    }
    return 0;
}


// não usou a pilha que foi pedido no exercício