#include"./student_list.h"

typedef struct _table_node Node;
typedef struct _hash_table HashTable;


struct _table_node {
    StudentList *st_list; 
};

struct _hash_table {
    int tsize;
    Node *node_list;
};


int is_prime(int num);
int get_next_prime(int num);
int get_student_hash(Student *st, int seed);

Node *create_nodes(int len);

HashTable *create_table(int tsize);
HashTable *init_table(int tsize);

Student *add_student_to_table(HashTable *tbl, Student *st);
Student *prompt_student();

void print_table(HashTable *tbl);
