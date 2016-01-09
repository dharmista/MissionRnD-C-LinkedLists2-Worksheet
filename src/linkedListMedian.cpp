/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	node * ptr1 = head, *ptr2 = head;
	while (ptr2->next != NULL){								//For odd numbered Linked-List
		if (ptr2->next->next == NULL)						//For even numbered Linekd-List
			return ((ptr1->num + ptr1->next->num) / 2);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
	}
	return ptr1->num;
}
