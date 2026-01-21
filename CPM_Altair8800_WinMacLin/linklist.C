#include <stdio.h>
#include "LINKLIST.H"
#define NULL 0

struct node *mknode(n) int n; {
    struct node* x;
    x = alloc(4);
    x->num = n;
    x->next = NULL;
    return x;
}

int isempty(list) {
    if (list == NULL) {
        return 1;
    }
    return 0;
}

int lsize(l) struct node* l; {
    int count;
    struct node* current;
    
    count = 0;
    current = l;
    
    while (current != NULL) {
        count = count + 1;
        current = current->next;
    }
    
    return count;
}
