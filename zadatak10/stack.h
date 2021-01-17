typedef struct _tree Tree;

struct _tree {
    char *val;
    Tree *ptr_left;
    Tree *ptr_right;
};

Tree *create_leaf(char *name);
Tree *add_leaf_at(Tree *head, char *val, int pos_flag);
Tree *add_leaf(Tree *head, char *val);


typedef struct _stack Node;

struct _stack {
    char *val;
    Node *next;
};

Node *create_node(char *val);
Node *pop_from_stack(Node *head);
Node *push_to_stack(Node *head, char *val);
char *pop_val_from_stack(Node *head);
void print_stack(Node *head);
