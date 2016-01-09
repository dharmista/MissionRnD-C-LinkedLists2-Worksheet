/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int pos = 0;
	node * ans = head;
	if (head == NULL)
		return NULL;
	while (head != NULL){
		if ((pos + 1) % K == 0){
			node * temp = (node *)malloc(sizeof(node));
			temp->num = K;
			temp->next = head->next;
			head->next = temp;
			head = head->next;
		}
		head = head->next;
		pos++;
	}
	return ans;
}
