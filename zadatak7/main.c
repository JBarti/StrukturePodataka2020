#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define foreach(p, q) for(p=q->next; p!=NULL; p=p->next)
#define MIN_RAND 10
#define MAX_RAND 100

typedef struct _node Node;

struct _node {
	char *val;
	Node *next;
};

Node *create_node(char *val) {
	Node *new_node = (Node *)malloc(sizeof(Node));

	if(new_node == NULL) {
		printf("Unable to allocate space");
		return NULL;
	}

	new_node->next = NULL;
	new_node->val = val;

	return new_node;
}


Node *push_to_stack(Node *head, char *val) {
	Node *new_node = create_node(val);
	
	new_node->next = head->next;
	head->next = new_node;

	return new_node;
}


Node *push_to_queue(Node *head, char *val) {
	return push_to_stack(head, val);	
}


Node *find_penultimate(Node *head) {
	Node *node_temp;
	Node *node_last = head;

	foreach(node_temp, head) {
		if(node_temp->next == NULL) {
			return node_last;
		} 
		node_last = node_temp;
	}

	return NULL;
}


Node *pop_from_stack(Node *head) {
	if(head->next == NULL) {
		printf("No elements to pop");
		return NULL;
	}

	Node *penultimate = find_penultimate(head);
	if(penultimate == NULL) return NULL;

	Node *node_temp = penultimate->next;
	penultimate->next = NULL;

	return node_temp;
}


Node *pop_from_queue(Node *head) {
	if(head->next == NULL) {
		printf("No elements to pop");
		return NULL;
	}

	Node *removed = head->next;
	head->next = removed->next;
	return removed;
}


int count_lines(char filename[]) {
	FILE *file = fopen(filename, "r");
	char char_temp;
	int counter = 0;

	while(!feof(file)) {
		char_temp = fgetc(file); 

		if(char_temp == '\n') {
			counter += 1;
		}
	}

	fclose(file);

	return counter;
}


Node *read_expression(char *filename, int lines) {
	FILE *file = fopen(filename, "r");
	Node *stack_head = create_node("");
	Node *node_temp = stack_head;

	for(int i=0; i<lines; i++) {
		char temp_str[10];
		fscanf(file, "%s", temp_str);
		node_temp->next = create_node(strdup(temp_str));
		node_temp = node_temp->next;
	}

	return stack_head;
}


int print_list(Node *head) {
	Node *node_temp;

	foreach(node_temp, head) {
		printf("%s\n", node_temp->val);
	}

	return 0;
}


int main() {
	int lines_count = count_lines("expression.txt");
	Node *expression = read_expression("expression.txt", lines_count);

	print_list(expression);

	pop_from_stack(expression);
	printf("\n");

	print_list(expression);


	return 0;
}
