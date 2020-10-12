typedef struct {
	char *first_name;
	char *last_name;
	int year_of_birth;
} Person;

typedef struct Node {
	Person *val;
	struct Node *next;

} Node;


Node *create_node(Person *person);

Person *create_person(char first_name[], char last_name[], int year_of_birth);

void prepend(Node *root, Person *person);

void append(Node *root, Person *person);

void insert_before(Node *root, Person *person, Person *new_person);

void insert_after(Node *root, Person *person, Person *new_person);

void print_list(Node *root);

Node *find_node_by_person(Node *root, Person *person);

Person *find_by_last_name(Node *root, char last_name[]);

void delete_person(Node *root, Person *person_del);

