#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***********************************************************
 * Kao cvor stabla koristimo element koji nema value
 *
 * Kada listu prosljedujemo funkciji koja radi promjenu
 * nad listom onda saljemo head element.
 *
 * Kada listu prosljedujemo funkciji koja ne radi promjenu
 * nad listom onda prosljedujemo head->next tj prvi element
 * koji ima zapisanu vrijednost.
 *
 * Kao cvor stabla koristimo element koji nema value.
 **********************************************************/

typedef struct {
	char *first_name;
	char *last_name;
	int year_of_birth;
} Person;


typedef struct Node {
	Person *val;
	struct Node *next;

} Node;


void prepend(Node *root, char first_name[], char last_name[], int year_of_birth) {
	Node *new_node;
	Person *new_person;
	
	new_node = (Node *)malloc(sizeof(Node));
	new_person = (Person *)malloc(sizeof(Person));

	new_person->first_name = strdup(first_name);
	new_person->last_name = strdup(last_name);
	new_person->year_of_birth = year_of_birth;

	new_node->val = new_person;

	new_node->next = root->next;
    root->next = new_node;	
}


void append(Node *root, char first_name[], char last_name[], int year_of_birth) {
	Node *new_node;
	Person *new_person;
	Node *last_node;

	new_node = (Node *)malloc(sizeof(Node));
	new_person = (Person *)malloc(sizeof(Person));

	new_person->first_name = strdup(first_name);
	new_person->last_name = strdup(last_name);
	new_person->year_of_birth = year_of_birth;

	new_node->val = new_person;

	last_node = root;
	while(last_node->next != NULL) {
		last_node = last_node->next;	
	}

	last_node->next = new_node;
	new_node->next = NULL;
}


void print_list(Node *root) {
	Node *node_buffer = root;
	Person *node_val;
	while(node_buffer != NULL) {
		node_val = node_buffer->val;
		printf(
				"%s %s %d\n", 
				node_val->first_name, 
				node_val->last_name, 
				node_val->year_of_birth
		);
		node_buffer = node_buffer->next;
	}
}


int main() {

	Node *list_root;

	list_root = (Node *)malloc(sizeof(Node));

	prepend(list_root, "Mirko", "Mirkic", 2010);
	prepend(list_root, "Matko", "Matkic", 2010);
	append(list_root, "Stipe", "Stipic", 2010);
	print_list(list_root->next);
}
