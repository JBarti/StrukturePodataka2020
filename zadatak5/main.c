#include<stdio.h>
#include<stdlib.h>
#define foreach(p, q) for(p=q->next; p!=NULL; p=p->next)

struct _node;
typedef struct _node* Position;
typedef struct _node Node;

struct _node {
	int val;
	Position next;
};


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


Node *create_node(int val) {
	Node *node = (Node *)malloc(sizeof(Node));

	if(node == NULL) {
		printf("Memory allocation failed");
		return NULL;
	}

	node->val = val;
	node->next = NULL;
	
	return node;
}


Node *read_nums(char filename[], int lines) {
	FILE *file = fopen(filename, "r");

	if(file == NULL) {
		printf("Unable to open file");
		return NULL;
	}

	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;

	if(head == NULL) {
		printf("Memory allocation failed");
		return NULL;
	}

	Node *node_temp = head;

	for(int i=0; i<lines; i++) {
		int temp;
		fscanf(file, "%d",  &temp);
		node_temp->next = create_node(temp);
		node_temp = node_temp->next;
	}

	return head;
}


int print_list(Node *head) {
	Node *node_temp;

	foreach(node_temp, head) {
		printf("%d\n", node_temp->val);
	}
}


int main() {
	int lines1 = count_lines("brojevi1.txt");
	int lines2 = count_lines("brojevi2.txt");

	Node *list1 = read_nums("brojevi1.txt", lines1);
	Node *list2 = read_nums("brojevi2.txt", lines2);

	print_list(list1);
	printf("\n");
	print_list(list2);


	return EXIT_SUCCESS;
}

