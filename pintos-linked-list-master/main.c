#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char *name;
	struct list_elem elem;
};

void insert(struct list *student_list) {

	char *student_name = (char*) malloc(50*sizeof(char));


	printf("Name: ");
	scanf("%s", student_name);
	struct student *new = (struct student *)malloc(sizeof(struct student));
	new->name = student_name;
	//printf("%s \n", (list_entry(&new->elem, struct student, elem))->name);
	list_push_back(student_list, &new->elem);
}

void delete(struct list *student_list) {
	
	printf("Name: ");
    char student_name[255];
    scanf("%s",student_name);
	struct list_elem *e;

	for(e = list_begin(student_list); e != list_end(student_list); e = list_next(e)) {
		struct student *current_student = list_entry (e, struct student, elem);
		if(strcmp((list_entry (e, struct student, elem))->name, student_name) == 0) {
			free(list_entry(e, struct student, elem)->name);
			free(list_entry(e, struct student, elem));
			list_remove(e);
			return;
		}
	} 
}

void list(struct list *student_list) {
	
	if(!list_empty(student_list)) {

		struct list_elem *e;
  	for(e = list_begin(student_list); e != list_end(student_list); e = list_next(e)) {
    	struct student *current_student = list_entry(e, struct student, elem);
		printf("%s ", current_student->name);
    	//printf("%s ", list_entry(e, struct student, elem)->name);

  	}
	}else{
		printf("The list is empty");
	}
	printf("\n");
}

void quit(struct list *student_list) {
	
	while (!list_empty(student_list)) {
		struct list_elem *e = list_pop_front(student_list);
		free(list_entry(e, struct student, elem));
		}

	exit(0);
}

int main() {
	struct list student_list;
	list_init (&student_list);
	int opt;

	do {
		printf("Menu:\n");
		printf("1 - Insert student\n");
		printf("2 - Delete student\n");
		printf("3 - List students\n");
		printf("4 - Exit\n");
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				{
					insert(&student_list);
					printf("Student added\n");
					break;
				}
			case 2:
				{
					delete(&student_list);
					break;
				}
			case 3:
				{
					list(&student_list);
					break;
				}

			case 4:
				{
					quit(&student_list);
					break;
				}
			default:
				{
					printf("Quit? (1/0):\n");
					scanf("%d", &opt);
					if (opt)
						quit(&student_list);
					break;
				}
		}
	} while(1);

	return 0;
}