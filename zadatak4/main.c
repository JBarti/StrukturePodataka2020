#include<stdio.h>
#include<stdlib.h>

struct Expression {
	int base;
	int exponent;
};

typedef struct Expression Expression;

struct Polinome {
	Expression *val;
	struct Polinome *next;
};

typedef struct Polinome Polinome;


Expression *create_expr(int base, int exponent) {
	Expression *expr = (Expression *)malloc(sizeof(Expression));

	expr->base = base;
	expr->exponent = exponent;

	return expr;
}


Polinome *create_polinome(Expression *expr) {
	Polinome *pol = (Polinome *)malloc(sizeof(Expression));

	pol->val = expr;
	pol->next = NULL;
}


Polinome *copy_polinome(Polinome *root) {
    Polinome *root_new = (Polinome *)malloc(sizeof(Polinome));
    Polinome *pol_new_temp = root_new;
    Polinome *pol_temp = root->next;

    while(pol_temp!=NULL) {
        Expression *expr_temp = pol_temp->val;
        Expression *expr_copy = create_expr(expr_temp->base, expr_temp->exponent);
        Polinome *pol_copy = create_polinome(expr_copy);

        pol_new_temp->next = pol_copy;
        pol_temp = pol_temp->next;
        pol_new_temp = pol_new_temp->next;
    }

    return root_new;
}


int print_polinome(Polinome *root) {
	Polinome *pol_temp = root;
	Expression *expr_temp;

	while(pol_temp != NULL) {
		expr_temp = pol_temp->val;
		printf("%dx^%d\n", expr_temp->base, expr_temp->exponent);
        pol_temp = pol_temp->next;
	}
	return 0;
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


Polinome *read_polinome(int lines_count, char filename[]) {
	FILE *file = fopen(filename, "r");

	Polinome *root = (Polinome *)malloc(sizeof(Polinome)); 
	root->val = NULL;
	root->next = NULL;

	int temp_base, temp_exp, i;
	Expression *expr_temp;
	Polinome *pol_temp = root;


	for(i=0; i<lines_count; i++) {
		fscanf(file, "%d %d", &temp_base, &temp_exp);
		expr_temp = create_expr(temp_base, temp_exp);
		pol_temp->next = create_polinome(expr_temp);
		pol_temp = pol_temp->next;
	}

    fclose(file);

	return root;
}


Polinome *sort_polinome(Polinome *root) {
    Polinome *node, *temp;

    for(node=root->next; node!=NULL; node=node->next)
    for(temp=root->next; temp->next!=NULL; temp=temp->next) {
        if(temp->val->exponent > temp->next->val->exponent) {
            Expression *temp_expr = temp->val;
            temp->val = temp->next->val;
            temp->next->val = temp_expr;
        }
    }
    
    
    return root;
}


Expression *find_same_power(Polinome *root, Expression *expr) {
    Polinome *pol_temp = root->next;
    
    while(pol_temp!=NULL) {
        if(pol_temp->val->exponent == expr->exponent)
            return pol_temp->val;
        pol_temp = pol_temp->next;
    }

    return NULL;
}

Polinome *add_polinomes(Polinome *root1, Polinome *root2) {
    Polinome *pol_sum = copy_polinome(root1);
    Polinome *pol2_temp = root2->next;
    
    while(pol2_temp!=NULL) {
        Expression *same_power = find_same_power(pol_sum, pol2_temp->val);

        if(same_power!=NULL) {
            same_power->base += pol2_temp->val->base;
            continue;
        }

        Expression *expr_new = create_expr(
                pol2_temp->val->base,
                pol2_temp->val->exponent
        );
        Polinome *pol_new = create_polinome(expr_new);
        Polinome *pol_swap = pol_sum->next;
        pol_sum->next = pol_new;
        pol_new->next = pol_swap;

        pol2_temp = pol2_temp->next;
    }

    return sort_polinome(pol_sum);
}


Polinome *multiply_polinomes(Polinome *root1, Polinome *root2) {
    Polinome *pol_sum = copy_polinome(root1);    
    Polinome *sum_temp = pol_sum->next;
    Polinome *pol2_temp;

    for(pol2_temp=root2->next; pol2_temp!=NULL; pol2_temp=pol2_temp->next)
    for(sum_temp=pol_sum->next; sum_temp!=NULL; sum_temp=sum_temp->next) {
        Expression *new_expr = create_expr(
                pol2_temp->val->base * sum_temp->val->base,
                pol2_temp->val->exponent + sum_temp->val->exponent
        );

        Expression *same_pow = find_same_power(pol_sum, new_expr);
        if(same_pow!=NULL) {
            same_pow->base += new_expr->base;
            continue;
        }

        Polinome *new_pol = create_polinome(new_expr);
        Polinome *pol_swap = pol_sum->next;
        pol_sum->next = new_pol;
        new_pol->next = pol_swap;
    }

    return sort_polinome(pol_sum);
}


int main() {
    int lines_count1 = count_lines("polinom1.txt");
    Polinome *root1 = read_polinome(lines_count1, "polinom1.txt");

    int lines_count2 = count_lines("polinom2.txt");
    Polinome *root2 = read_polinome(lines_count2, "polinom2.txt");

    sort_polinome(root1);
    sort_polinome(root2);

    printf("First polinome: \n");
    print_polinome(root1->next);
    printf("\n");
    printf("Second polinome: \n");
    print_polinome(root2->next);
    printf("\n");

    Polinome *pol_sum = add_polinomes(root1, root2);
    printf("Polinome sum: \n");
    print_polinome(pol_sum->next);


    Polinome *pol_mult = multiply_polinomes(root1, root2);
    printf("Polinome mult: \n");
    print_polinome(pol_mult->next);

	return 0;
}
