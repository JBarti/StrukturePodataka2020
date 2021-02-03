#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./student_list.h"

Student *create_student(char *first_name, char *last_name, id MB) {
    Student *new = (Student *)malloc(sizeof(Student));
    if(new == NULL) {
        printf("Could not allocate memory for Student\n");
        exit(1);
    }

    new->first_name = first_name;
    new->last_name = last_name;
    new->MB = MB;

    return new;
}

StudentList *create_student_node(Student *val) {
    StudentList *new = (StudentList *)malloc(sizeof(StudentList));
    if(new == NULL) {
        printf("Could not allocate memory for StudentList\n");
        exit(1);
    }

    new->val = val;
    new->next = NULL;

    return new;
}


int student_cmp(Student *st1, Student *st2) {
    char st1_str[100] = "";
    strcat(st1_str, st1->first_name);
    strcat(st1_str, st1->last_name);

    char st2_str[100] = "";
    strcat(st2_str, st2->first_name);
    strcat(st2_str, st2->last_name);

    return strcmp(st1_str, st2_str);
}


StudentList *insert_after(StudentList *where, Student *val) {
    StudentList *new = create_student_node(val);
    
    new->next = where->next;
    where->next = new;

    return new;
}


StudentList *insert_student_util(StudentList *root, Student *val) {
    StudentList *curr = root;
    StudentList *st_new = NULL;

    if(student_cmp(val, curr->val) > 0) {
        if(curr->next == NULL || student_cmp(val, curr->next->val) < 0)
            st_new = insert_after(curr, val);
        else 
            insert_student_util(curr->next, val);
    }
    else if(student_cmp(val, curr->val) < 0) {
        if(curr->next == NULL || student_cmp(val, curr->next->val) > 0)
            st_new = insert_after(curr, val);
        else
            insert_student_util(curr->next, val);
    }
    else {
        st_new = insert_after(curr, val);
    }

    return st_new;
}


StudentList *insert_student(StudentList *root, Student *val) {
    if(root->next == NULL) { return insert_after(root, val); }
    return insert_student_util(root->next, val);
}



void print_student_list(StudentList *root) {
    StudentList *temp;
    Student *temp_val;

    foreach_st(root, temp) {
        temp_val = temp->val; 
        printf(
                "%s %s %li, ", 
                temp_val->first_name, 
                temp_val->last_name, 
                temp_val->MB
        );
    }

    printf("\n");
}
