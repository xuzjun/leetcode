/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

#include <stdio.h>

int findComplement(int num) {
	unsigned int t = num;
	int count = 0;
	int i;
	for (i = 1; i < 32; ++i) {
		if ((t & 1) == 1) count = i;
		t = t >> 1;
	}
	t = 1;
	printf("%d\n", count);
	while (count--) t = t << 1;
	
	return t - 1 - num;
}

int main()
{
	int i = 1;
	i = i << 30;
	printf("%d\n", findComplement(i));
	return 0;
}
