#include<stdio.h>

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


int print_polinome(Polinome *root) {
	Polinome *pol_temp;
	Expression *expr_temp;

	while(temp_pol != NULL) {
		expr_temp = pol_temp->val;
		printf("%d^%d", expr_temp->base, expr_temp->exponent);
	}
	return 0;
}

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

Polinome *read_polinome() {
	FILE *file = fopen("polinom.txt", "r");

	Polinome *root = (Polinome *)malloc(sizeof(Polinome)); 
	root->val = NULL;
	root->next = NULL;

	int temp_base, temp_exp;
	Expression *expr_temp;
	Polinome *pol_temp = root;


	while(!feof(file)) {
		fscanf("%d %d", &temp_base, &temp_exp);
		expr_temp = create_expr(temp_base, temp_exp);
		pol_temp->next = create_polinome(expr_temp);
		pol_temp = pol_temp->next;
	}

	return root;
}


int main() {
	
	return 0;
}
