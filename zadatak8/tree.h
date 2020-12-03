typedef struct _tree Tree;

char *str_duplicate(char *old);
Tree *create_leaf(char *name);
Tree *add_child(Tree *where, char *what);
Tree *add_sibling(Tree *where, char *what);
void print_children(Tree *head);
