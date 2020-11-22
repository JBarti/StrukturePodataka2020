typedef struct {
    char *first_name;
    char *last_name;
    unsigned int year_of_birth;
} Person;

typedef struct Node {
    Person *val;
    struct Node *next;

} Node;


Node *create_node(Person *person);

Person *create_person(char first_name[], char last_name[], unsigned int year_of_birth);

Node *prepend(Node *element, Person *person);

Node *append(Node *element, Person *person);

int insert_before(Node *root, Person *person, Person *new_person);

int insert_after(Node *root, Person *person, Person *new_person);

int print_list(Node *root);

Node *find_node_by_person(Node *root, Person *person);

Person *find_by_last_name(Node *root, char last_name[]);

int delete_person(Node *root, Person *person_del);

int sort(Node *root);

