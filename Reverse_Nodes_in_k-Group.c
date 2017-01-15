/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
        struct ListNode *h = NULL, *p, *p1, *p2 = NULL, *p3 = NULL, *f = NULL, *f1 = NULL;
        p = p1 = head;
        int i;
        while (1) { 
                for (i = 0; i < k; ++i)
                        if (p) p = p->next;
                        else break;
                if (i < k) break;
                
                if (p1) p2 = p1->next;
                else break;
                
                if (p2 != p) p3 = p2->next;
                else p3 = p2;
                
                p1->next = p;
                f1 = p1;
		if (f == NULL) f = p1;
                for (i = 1; i < k; ++i) {
                        if (p2 != p) p2->next = p1;
                        else break;
                        p1 = p2;
                        p2 = p3;
                        if (p3 != p) p3 = p3->next;
                        else break;
                }
                if (h == NULL) {h = p1;}
                else {f->next = p1; f = f1;}
                p1 = p;
        }               
        if (h == NULL) h = head;
        return h;
}

struct ListNode *makeList(int size)
{
	struct ListNode *h = NULL, *p = NULL;
	int i;

	for (i = 0; i < size; ++i) {
		if (h == NULL) {
			h = calloc(1, sizeof(struct ListNode));
			h->val = i + 1;
			p = h;
		} else {
			struct ListNode *new = calloc(1, sizeof(struct ListNode));
			new->val = i + 1;
			p->next = new;
			p = new;
		}
	}
	return h;
}

void print(struct ListNode *h)
{
	while (h) {
		printf("%d ", h->val);
		h = h->next;
	}
	printf("\n");
}

int main()
{
	struct ListNode *head = makeList(6);

	struct ListNode *r = reverseKGroup(head, 2);

	print(r);
	return 0;
}
