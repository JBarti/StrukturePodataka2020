#include<stdio.h>
#include"./hash_table.h"

#define NUM_STUDENTS 2
#define TBL_SIZE 11

int main() {
    HashTable *htb = create_table(TBL_SIZE);

    printf("Unesite %d studenata: \n", NUM_STUDENTS);
    for(int i=0; i<NUM_STUDENTS; i++) {
        Student *s = prompt_student();
        add_student_to_table(htb, s);
    }
    print_table(htb);
    return 0;
}
