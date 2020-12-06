#include <stdio.h>
#include "TDLinkedList.h"

struct DlinkedList {   
    DLNode *begin;   
    DLNode *end;   
    int size; 
}; 

struct dlnode {    
    int data;    
    DLNode *next;    
    DLNode *prev;
}; 

//Exercício 1a
int list_erase_even(List* li) {
    if (li == NULL || li->size == 0)
        return -1;
    else {
        DLnode *no;
        no = li->begin;
        int i = 1;

        while (no != NULL && i < li->size) {
            if (no->data % 2 == 0) {
                list_erase(li, i); // não muda o ponteiro de nó!
            } else {
                no = no->next;
                i++;
            }
        }
    }
    return 0;
}

//Exercicio 1c
int list_splice(List *dest, List *source, int  pos) { 
    if (dest == NULL || source == NULL || pos > dest->size)
        return -1;
    else {
        DLnode *no = dest->end;
        for (int o = dest->size; o >= pos; o--)
            no = no->prev;
        
        int i = pos;
        DLnode aux = source->begin;
        while (li != NULL && i > source->size) {  // quem é li?
            li->next = aux;
            aux = aux->next;
        }
        for (int x = dest->size; x <= dest->size + source->size; x++) {
            if (no->next != NULL) {
                li->end->next = no->data;
                no = no->next;
            } else {
                return 0;
            }
        }
        return 0;
    }
}