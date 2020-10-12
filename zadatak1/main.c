#include<stdio.h>
#include<stdlib.h>
#define UKUPNO_BODOVA 200

typedef struct Student {
    char first_name[50];
    char last_name[50];
    int score; 
} Student; 


int get_lines_count(FILE *file) {
    char char_buffer;
    int line_counter = 0;
    while(!feof(file)) {
        char_buffer = fgetc(file);
        if(char_buffer == '\n') {
            line_counter += 1;
        }
    }

    rewind(file);
    return line_counter;
}


void read_students(FILE *file, int size, Student *students) {
    int i;

    for(i=0; i<size; i++) {
        fscanf(
                file, 
                "%s %s %d", 
                students[i].first_name, 
                students[i].last_name, 
                &students[i].score
        );
    }
}


int main() {
    FILE *students_file;
    Student *students;
    int line_number;
    int i;

    students_file = fopen("studenti.txt", "r");

    if(students_file == NULL) {
        printf("Could not open file !");
        return 0;
    }

    line_number = get_lines_count(students_file);
    students = (Student *)malloc(sizeof(Student) * line_number);
    read_students(students_file, line_number, students);


    float relative_score;

    printf("Ime\tPrezime\tPostotak\tBodovi\n");
    for(i=0; i<line_number; i++) {
        relative_score = (float)students[i].score / (float)UKUPNO_BODOVA;
        printf(
                "%s\t%s\t%.2f\t%d\n", 
                students[i].first_name, 
                students[i].last_name, 
                relative_score*100, 
                students[i].score
        );
    }

    fclose(students_file);

    return 0;
}
