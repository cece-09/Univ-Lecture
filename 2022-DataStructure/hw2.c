#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 15

typedef struct node_ {
	int data;
	struct node_* prev;
	struct node_* next;
}node;
typedef node* listpointer;

listpointer node_insert(listpointer, int); // insert a node
listpointer node_delete(listpointer, int); // delete a node
void print_forward(listpointer); // ascending order
void print_reverse(listpointer); // desending order

int main(int argc, char *argv[]) {
	// the number of command-line argument must be 1
	if (argc != 2) {
		printf("usage: ./hw2 input_filename\n");
		exit(-1);
	}
	const char* filename = argv[1]; // the first elem
	
	// read from file
	FILE* infile = fopen(filename, "r");
	if (infile == NULL) {
		printf("The input file does not exist.\n");
		exit(-1);
	}
	char command[MAX_CHAR] = { 0 };
	int num;

	listpointer list = NULL; // head of the list

	while (!feof(infile)) {
		fscanf(infile, "%s %d", command, &num);

		if (strcmp(command, "INSERT") == 0) {
			list = node_insert(list, num);
		}
		else if(strcmp(command, "DELETE") == 0) {
			list = node_delete(list, num);
		}
		else if (strcmp(command, "ASCEND") == 0) {
			print_forward(list);
		}
		else if (strcmp(command, "DESCEND") == 0) {
			print_reverse(list);
		}
		else {
			break;
		}
	}
	
	// free all nodes
	if (list != NULL) {
		
		listpointer curr = list;
		listpointer freeNode;
		while (curr->next != list) {
			freeNode = curr;
			curr = curr->next;
			free(freeNode);
		}
		free(curr);
	}
	
	fclose(infile);
	return 0;
}

listpointer node_insert(listpointer list, int num) {
	// create new node
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) exit(-1);
	newNode->data = num;

	// if empty list
	if (list == NULL) {
		list = newNode;
		list->prev = list;
		list->next = list;
		return list;
	}
	
	listpointer curr = list;
	listpointer before = NULL;
	int tmp = 0;

	// if curr > newNode, terminate loop
	while (1) {
		if (curr->data  <  newNode->data) {
			before = curr;
			curr = curr->next;
			if (curr == list) {
				// curr is the last
				tmp = -1;
				break;
			}
		}
		else {
			if (curr->prev->next == list) {
				// curr is the first
				tmp = 1;
				break;
			}
			// curr is in the middle
			break;
		}
	}
	if (tmp == -1) { // append
		curr = before;
		newNode->prev = curr;
		newNode->next = list;
		curr->next  = newNode;
		list->prev = newNode;
	}
	else if (tmp == 1) { // shift
		newNode->prev = curr->prev;
		newNode->next = curr;		
		newNode->prev->next = newNode;
		curr->prev = newNode;
		list = newNode;
	}
	else { // insert in the middle
		before = curr->prev;
		newNode->prev = before;
		newNode->next = curr;

		before->next = newNode;
		curr->prev = newNode;
	}
	return list;
}

listpointer node_delete(listpointer list, int num) {
	// if empty list
	if (list == NULL) {
		return list;
	}

	// search the node .data == num
	listpointer curr = list;
	listpointer delNode = NULL;
	while (1) {
		if (curr->data == num) {
			delNode = curr;
			break;
		}
		curr = curr->next;
		if (curr == list) break;
	}
	if (delNode == NULL) {
		// there is no node to delete
		return list;
	}

	if (delNode->next == list) {
		// delNode is the last
		delNode->next->prev = delNode->prev;
		delNode->prev->next = list;
		delNode->next = NULL;
		delNode->prev = NULL;
	}
	else if (delNode->prev->next == list) {
		// delNode is the first
		list = delNode->next;
		delNode->next->prev = delNode->prev;
		delNode->prev->next = list;
		
		delNode->next = NULL;
		delNode->prev = NULL;
	}
	else {
		// delNode is in the middle
		delNode->next->prev = delNode->prev;
		delNode->prev->next = delNode->next;
		delNode->next = NULL;
		delNode->prev = NULL;
	}
	free(delNode);
	return list;
}

void print_forward(listpointer list) {
	listpointer curr;
	FILE* outfile;

	outfile = fopen("hw2_result.txt", "a");
	if (list) {
		curr = list;
		while (1) {
			fprintf(outfile, "%d ", curr->data);
			printf("%d ", curr->data);
			curr = curr->next;
			if (curr == list) break;
		}
	}
	fprintf(outfile, "\n");
	printf("\n");
	fclose(outfile);
}

void print_reverse(listpointer list) {

	listpointer curr;
	FILE* outfile;

	outfile = fopen("hw2_result.txt", "a");
	if (list) {
		curr = list->prev;

		while (curr != list) {
			fprintf(outfile, "%d ", curr->data);
			printf("%d ", curr->data);
			curr = curr->prev;
		}
		fprintf(outfile, "%d ", curr->data);
		printf("%d ", curr->data);
	}
	fprintf(outfile, "\n");
	printf("\n");
	fclose(outfile);
}