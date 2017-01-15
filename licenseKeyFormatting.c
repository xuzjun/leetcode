/*
Now you are given a string S, which represents a software license key which we would like to format. The string S is composed of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.

We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters in the string must be converted to upper case.

So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license key formatted according to the description above.

Example 1:
Input: S = "2-4A0r7-4k", K = 4

Output: "24A0-R74K"

Explanation: The string S has been split into two parts, each part has 4 characters.
Example 2:
Input: S = "2-4A0r7-4k", K = 3

Output: "24-A0R-74K"

Explanation: The string S has been split into three parts, each part has 3 characters except the first part as it could be shorter as said above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* S, int K)
{

#define UPPER(a)  ('a' <= (a) && (a) <= 'z') ? ((a) + 'A' - 'a') : (a)    
    
    int len = strlen(S);
    char *r = calloc(strlen(S) * 2, sizeof(char));
    
    int j = len - 1;
    int i = len * 2 - 1;
    
    while (j >= 0) {
        int k = K;
        while (k--) {
            while (S[j] == '-' && j >= 0) j--;
            if (j >= 0) {
                r[i--] = UPPER(S[j]);
                j--;
            } else {
                break;
            }
        }
        if (j >= 0) r[i--] = '-';
        else if (r[i + 1] == '-') i++;
    }
    memmove(r, r + i + 1, len * 2 - 1 - i);
    r[len * 2 - 1 - i] = 0;
    return r;
}

int main()
{
	char *s = "--a-a-a-a--";
	printf("%s\n", licenseKeyFormatting(s, 2));
	return 0;
}
