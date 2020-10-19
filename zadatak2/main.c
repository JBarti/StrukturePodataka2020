#include<stdio.h>
#include<stdlib.h>

#include "person_list.h"

/***********************************************************
 * Kao cvor stabla koristimo element koji nema value
 *
 * Kada listu prosljedujemo funkciji koja radi promjenu
 * nad listom onda saljemo head element.
 *
 * Kada listu prosljedujemo funkciji koja ne radi promjenu
 * nad listom onda prosljedujemo head->next tj prvi element
 * koji ima zapisanu vrijednost.
 *
 * Kao cvor stabla koristimo element koji nema value.
 **********************************************************/


int main() {
	Node *list_root;

	list_root = (Node *)malloc(sizeof(Node));

    Person *p1 = create_person("Ante", "Ante", 2010);
    Person *p2 = create_person("Bartul", "Bartul", 2010);
    Person *p3 = create_person("Josip", "Josip", 2010);
    Person *p4 = create_person("Matej", "Matej", 2010);
    Person *p5 = create_person("Stipe", "Stipe", 2010);

	append(list_root, p1);
	append(list_root, p2);
	append(list_root, p1);
	append(list_root, p3);
	append(list_root, p1);
	print_list(list_root->next);

    Person *person_searched = find_by_last_name(list_root->next, "Josip");
	if(person_searched != NULL) {
		printf(
				"\n%s %s %d\n", 
				person_searched->first_name, 
				person_searched->last_name, 
				person_searched->year_of_birth
		);
	}
    printf("\n");
    delete_person(list_root, person_searched);
    print_list(list_root->next);

    printf("\n");
    insert_after(list_root, p2, p4);
    print_list(list_root->next);

    printf("\n");
    insert_before(list_root, p2, p5);
    print_list(list_root->next);

	printf("\n");
    sort(list_root);
	print_list(list_root->next);
    
}
