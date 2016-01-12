/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL)return head2;
	if (head2 == NULL)return head1;
	node * temp2 = NULL;
	node * ans = NULL;
	node * k = NULL;
	bool compl = false;
	while (!compl){
		if (head1->num < head2->num){
			if (ans == NULL)
			{
				ans = (node *)malloc(sizeof(node));
				k = ans;
				ans->num = head1->num;
				ans->next = NULL;
				head1 = head1->next;
			}
			else{
				ans->next = head1;
				head1 = head1->next;
				ans = ans->next;
			}
		}
		else{
			if (ans == NULL)
			{
				ans = (node *)malloc(sizeof(node));
				k = ans;
				ans->num = head2->num;
				ans->next = NULL;
				head2 = head2->next;
			}
			else{
				ans->next = head2;
				head2 = head2->next;
				ans = ans->next;
			}
		}
		if (head1 == NULL){
			ans->next = head2;
			compl = true;
		}
		if (head2 == NULL){
			ans->next = head1;
			compl = true;
		}
	}
	return k;
}