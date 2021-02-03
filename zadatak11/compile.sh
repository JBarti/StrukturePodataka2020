gcc -Wall -g -c hash_table.c
gcc -Wall -g -c student_list.c
gcc -g main.c hash_table.o student_list.o -lm 
