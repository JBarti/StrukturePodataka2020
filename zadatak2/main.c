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

    Person *p1 = create_person("Mirko", "Mirkic", 2010);
    Person *p2 = create_person("Matko", "Matkic", 2010);
    Person *p3 = create_person("Stipko", "Stipkic", 2010);
    Person *p4 = create_person("Jozo", "Jozic", 2010);
    Person *p5 = create_person("Jozo", "Jozic", 2010);

	prepend(list_root, p1);
	prepend(list_root, p2);
	append(list_root, p3);
	print_list(list_root->next);

    Person *person_searched = find_by_last_name(list_root->next, "Mirkic");
    printf(
            "\n%s %s %d\n", 
            person_searched->first_name, 
            person_searched->last_name, 
            person_searched->year_of_birth
    );
    printf("\n");
    delete_person(list_root, person_searched);
    print_list(list_root->next);

    printf("\n");
    insert_after(list_root, p2, p4);
    print_list(list_root->next);

    printf("\n");
    insert_before(list_root, p2, p5);
    print_list(list_root->next);
    
}
