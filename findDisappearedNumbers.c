/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
        int *r = calloc(numsSize, sizeof(int));
        int i; 
        for (i = 0; i < numsSize; ++i) {
                r[nums[i] - 1] = nums[i];
        }
        
        int j = 0;
        for (i = 0; i < numsSize; ++i)
                if (r[i] == 0) r[j++] = i + 1;
        *returnSize = j;
        return r;
}

int main()
{
	
}
