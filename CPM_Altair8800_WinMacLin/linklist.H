struct node {
    int num;
    struct node* next;
};

struct node* mknode(n);
int lsize(struct node* list);
int isempty(struct node* list);
