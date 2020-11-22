#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "person_list.h"


Node *create_node(Person *person) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = person;
    new_node->next = NULL;

    return new_node;
}


Person *create_person(char first_name[], char last_name[], unsigned int year_of_birth) {
    Person *new_person = (Person *)malloc(sizeof(Person));

    new_person->first_name = strdup(first_name);
    new_person->last_name = strdup(last_name);
    new_person->year_of_birth = year_of_birth;

    return new_person;
}


Node *prepend(Node *root, Person *person) {
    Node *new_node = create_node(person);

    new_node->next = root->next;
    root->next = new_node;

    return new_node;
}


Node *append(Node *root, Person *person) {
    Node *new_node = create_node(person);

    Node *last_node = root;
    while(last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;

    return new_node;
}


int print_list(Node *root) {
    Node *node_temp = root;
    Person *node_val;

    while(node_temp != NULL) {
        node_val = node_temp->val;
        printf(
                "%s %s %d\n", 
                node_val->first_name, 
                node_val->last_name, 
                node_val->year_of_birth
              );
        node_temp = node_temp->next;
    }

    return 0;
}


Person *find_by_last_name(Node *root, char last_name[]) {
    Node *node_temp = root;
    Person *node_val;

    while(node_temp != NULL) {
        node_val = node_temp->val;
        if(strcmp(node_val->last_name, last_name) == 0) {
            return node_val;
        }
        node_temp = node_temp->next;
    }

    return NULL;
}


int delete_person(Node *root, Person *person_del) {
    Node *node_temp = root;
    Node *last_node = NULL;

    while(node_temp != NULL) {
        if(node_temp->val == person_del) {
            last_node->next = node_temp->next;
            free(node_temp->val);
            free(node_temp);
            return 0;
        }
        last_node = node_temp;
        node_temp = node_temp->next;
    }
    return 1;
}


int insert_before(Node *root, Person *person, Person *new_person) {
    Node *node_temp = root;
    Node *last_node = NULL;
    Node *new_node = create_node(new_person); 

    while(node_temp != NULL) {
        if(last_node != NULL && node_temp->val == person) {
            last_node->next = new_node;
            new_node->next = node_temp;
            return 0;
        }
        last_node = node_temp;
        node_temp = node_temp->next;
    }

    return 1;
}


int insert_after(Node *root, Person *person, Person *new_person) {
    Node *node_temp = root;
    Node *last_node = NULL;
    Node *new_node = create_node(new_person);

    while(node_temp != NULL) {
        if(last_node != NULL && last_node->val == person) {
            last_node->next = new_node;
            new_node->next = node_temp;
            return 0;
        }
        last_node = node_temp;
        node_temp = node_temp->next;
    }

    return 1;
}

int sort(Node *root) {
    Node *node_temp, *node_next_temp;

    Person *val_temp, *val_next_temp;

    for(node_temp=root->next; node_temp!=NULL; node_temp=node_temp->next) {	
        for(node_next_temp=root->next; node_next_temp->next!=NULL; node_next_temp=node_next_temp->next) {

            val_temp = node_next_temp->val;
            val_next_temp = node_next_temp->next->val;

            if(strcmp(val_temp->last_name, val_next_temp->last_name) > 0) {
                node_next_temp->val = val_next_temp;
                node_next_temp->next->val = val_temp;
            }
        }
    }

    return 0;
}
