/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:
*/

#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int count = 0;	    
	int i;
	int max = 0;
	for (i = 0; i < numsSize; ++i) {
		if (nums[i] == 1) count++;
		else {
			if (count > max)  max = count;
			count = 0;
		}
	}
	return max;
}

int main()
{

}
