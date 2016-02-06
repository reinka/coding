/*
 ============================================================================
 Name        : linked_list.c
 Author      : Andrei Poehlmann
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node_t, *nodeptr_t;

nodeptr_t head = NULL;

void insert_node(nodeptr_t new){
	if(head == NULL){
		head = new;
		new -> next = NULL;
	}else{
		nodeptr_t help = head;
		while(help->next != NULL){
			help = help->next;
		}
		help->next = new;
		new->next = NULL;
	}
}

void print_node(nodeptr_t head){
	nodeptr_t help = head;
	while(help != NULL){
		printf("%d ",help->value);
		help = help->next;
	}
	puts("");
}

int main(void) {

	node_t test1 = { 4, NULL}, new = {5, NULL};
	nodeptr_t p = &test1, q = &new;

	insert_node(q);
	print_node(head);
	insert_node(p);
	print_node(head);

	return EXIT_SUCCESS;
}
