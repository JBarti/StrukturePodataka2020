#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include"./hash_table.h"


int is_prime(int num) {
    int num_sqr = ceil(sqrt(num));
    for(int i=2; i<num_sqr; i++) {
        if(!(num % i)) { return 0; }
    }
    return 1;
}


int get_next_prime(int num) {
    while(!is_prime(num)) {
        num ++;
    }
    return num;
}


Node *create_nodes(int len) {
    Node *new = (Node *)malloc(sizeof(Node) * len);
    if(new == NULL) {
        printf("Could not allocate memory for Node\n");
        exit(1);
    }

    return new;
}


HashTable *create_table(int tsize) {
    HashTable *tbl = (HashTable *)malloc(sizeof(HashTable));
    if(tbl == NULL) {
        printf("Could not allocate memory for HashTable\n");
        exit(1);
    }
    
    tbl->tsize = tsize;
    tbl->node_list = create_nodes(tsize);

    return tbl;
}


HashTable *init_table(int tsize) {
    tsize = get_next_prime(tsize);

    HashTable *tbl  = create_table(tsize);

    return tbl;
}


int ASCI_sum(char *str) {
    int sum = 0;

    for(int i=0; i<strlen(str); i++) {
        sum += (int)str[i];
    }

    return sum;
}


int get_student_hash(Student *st, int seed) {
    int name_sum = ASCI_sum(st->first_name);
    int last_name_sum = ASCI_sum(st->last_name);

    return (name_sum + last_name_sum) % seed;
}


Student *add_student_to_table(HashTable *tbl, Student *st) {
    int hash = get_student_hash(st, tbl->tsize);
    Node *pos = &tbl->node_list[hash];

    if(pos->st_list == NULL) {
        pos->st_list = create_student_node(NULL);
    }

    return insert_student(pos->st_list, st)->val;
}


Student *prompt_student() {
    char first_name[100], last_name[100];
    id MB;

    printf("Inser student data: ");
    scanf("%s %s %li", first_name, last_name, &MB);

    return create_student(
            strdup(first_name),
            strdup(last_name),
            MB
    );
}


void print_table(HashTable *tbl) {
    for(int i=0; i<tbl->tsize; i++) {
        printf("Hash: %d\n", i);
        printf("Students: ");
        if(tbl->node_list[i].st_list == NULL) {
            printf("[]\n");
            continue;
        }
        print_student_list(tbl->node_list[i].st_list);
    }
}
