/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/
#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
	int num = numsSize;
	int i, j = 0;
	for (i = 1; i < numsSize; ++i) {
		if (nums[j] == nums[i]) {num--; continue;}
		nums[++j] = nums[i];
	}

	return num;
}

int main()
{
	int nums[12] = {1, 1, 2, 2, 3, 4, 5, 6, 9, 10, 11, 11};

	int ret = removeDuplicates(nums, 12);
	printf("%d\n-----\n", ret);

	int i;
	for (i = 0; i < ret; ++i)
		printf("%d\n", nums[i]);

	return 0;
}
