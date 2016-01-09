/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void reverse(node *temp, node *prev, node **head)
{
	if (!temp->next)
	{
		*head = temp;
		temp->next = prev;
		return;
	}
	node *next = temp->next;
	temp->next = prev;
	reverse(next, temp, head);					/*Linking back to front*/
}

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else
		reverse(head, NULL, &head);
	return head;
}
