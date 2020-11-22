#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define foreach(p, q) for(p=q->next; p!=NULL; p=p->next)
#define MIN_RAND 10
#define MAX_RAND 100

typedef struct _node_double Node;

struct _node_double {
    double val;
    Node *next;
};



Node *create_node(double val) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Unable to allocate space");
        return NULL;
    }

    new_node->next = NULL;
    new_node->val = val;

    return new_node;
}


Node *push_to_stack(Node *head, double val) {
    Node *new_node = create_node(val);

    new_node->next = head->next;
    head->next = new_node;

    return new_node;
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


double apply_operator(Node *calc_stack, char operator) {
    Node *node1 = pop_from_stack(calc_stack);
    Node *node2 = pop_from_stack(calc_stack);

    if(node1 == NULL || node2 == NULL) {
        printf("Not enough data to finish operatin");
        return 1;
    }

    double num1 = node1->val;
    double num2 = node2->val;
    double rez;

    switch(operator) {
        case '+':
            rez = num1 + num2;
            break;
        case '-':
            rez = num1 - num2;
            break;
        case '*':
            rez = num1 * num2;
            break;
        case '/':
            rez = num1 / num2;
            break;
    }

    return rez;
}


Node *on_expr_read(Node *calc_stack, char *val) {
    if(isalnum(val)) {
        double num;
        sscanf(val, "%lf", &num);
        printf("\n %lf", num);
    }
    else {
        double num = apply_operator(calc_stack, val[0]);
        push_to_stack(calc_stack, num);
    }

    return calc_stack;
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


double calculate_expression(char *filename, int lines, Node* (* on_read)(Node *calc_stack, char *val)) {
    FILE *expr_file = fopen(filename, "r");
    char val[20];
    Node *calc_stack = create_node(0);
    int i;

    for(i=0; i<lines; i++) {
        fscanf(expr_file, "%s", val);
        printf("%s\n", val);
        char *value = strdup(val);
        on_expr_read(calc_stack, value);
    }

    fclose(expr_file);

    return 123;
}


int print_list(Node *head) {
    Node *node_temp;

    foreach(node_temp, head) {
        printf("%fl\n", node_temp->val);
    }

    return 0;
}


int main() {
    int lines_count = count_lines("expression.txt");
    calculate_expression("expression.txt", lines_count, on_expr_read);
    return 0;
}
