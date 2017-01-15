#include <stdio.h>



typedef int bool;

bool isPalindrome(int x) {
    	if (x < 0) return 0;
	int t, m, n;
	t = x;
	m = 10;
	n = 0;	
	while (t) {
		t /= m;
		m *= 10;
		n++;
	}
	
    	return 1;
}

int main(int argc, char *argv[])
{
	if (argc != 2) return -1;

	int x = atoi(argv[1]);
	if (isPalindrome(x))
		printf("[%d], it's a palindrome", x);
	else 
		printf("[%d], it's not a palindrome", x);

	if (isPalindrome(INT_MAX))
		printf("[%d], it's a palindrome", INT_MAX);
	else 
		printf("[%d], it's not a palindrome", INT_MAX);

	return 0;
}
