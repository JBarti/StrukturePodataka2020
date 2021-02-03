typedef struct _student Student;
typedef struct _student_list StudentList;
typedef long unsigned int id;
#define foreach_st(head, temp) for(temp=head->next; temp!=NULL; temp=temp->next)

struct _student {
    char *first_name;
    char *last_name;
    id MB;
};


struct _student_list {
    Student *val;
    StudentList *next;
};


int student_cmp(Student *s1, Student *s2);

Student *create_student(char *first_name, char *last_name, id MB);

StudentList *create_student_node(Student *val);
StudentList *insert_after(StudentList *where, Student *val);
StudentList *insert_student(StudentList *root, Student *val);

void print_student_list(StudentList *root);
