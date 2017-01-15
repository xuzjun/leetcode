/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
	int count;
	int num;
	struct node *next;
} Node;

int longestConsecutive(int* nums, int numsSize) {
	Node *head = NULL;
	Node *p = NULL;

	int i;
	int l, r;
	for (i = 0; i < numsSize; ++i) {
		Node *new = calloc(1, sizeof(Node));
		new->num = nums[i]
		new->count = 1;
		if (head == NULL) head = new;
		p = head;
		l = r = 0;
		while (p) {
			if (p->num == nums[i] - 1) l = p->count;
			else if (p->num == nums[i] + 1) r = p->count;
			p = p->next;
		}
		len = l + r + 1;
	}

	int max = 0;
	Node *p = head;
	while (p) {
		if (p->count > max) max = p->count;
		p = p->next;
	}
	
	return max;
}

int main()
{
	int nums[11] = {100,7,200,1,9,3, -1, 0, 1, -2, 2};
	printf("%d\n", longestConsecutive(nums, 11));
	return 0;
}
