/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

#include <stdio.h>

bool canConstruct(char* ransomNote, char* magazine) {
	int base[128] = {0};
	char *p = magazine;
	while (*p) {
		base[*p]++;
		p++;
	}
	p = ransomNote;
	while (*p) {
		if ((--base[*p] < 0) return 0;
		p++;
	}
	return 1;
}

int main()
{
	return 0;
}
