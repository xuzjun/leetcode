#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman(int num)
{
	char *ret = calloc(64, sizeof(char));
	char *p = ret;

	int tmp, divisor = 1000; 
	char BASE, MID, TOP;
	while (divisor) {
		switch (divisor) {
		case 1000: BASE = 'M'; break;
		case 100: BASE = 'C'; MID = 'D'; TOP = 'M'; break;
		case 10: BASE = 'X'; MID = 'L'; TOP = 'C'; break;
		case 1: BASE = 'I'; MID = 'V'; TOP = 'X'; break;
		}
		tmp = num / divisor;
		switch (tmp) {
		case 1:
		case 2:
		case 3: {
			while (tmp--) *p++ = BASE;
			break;
		}
		case 4: *p++ = BASE; *p++ = MID; break;
		case 5: *p++ = MID; break;
		case 6:
		case 7:
		case 8: {
			*p++ = MID;
			tmp -= 5;
			while (tmp--) *p++ = BASE;
			break;
		}
		case 9: *p++ = BASE; *p++ = TOP; break;
		}

		num %= divisor;
		divisor /= 10;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "argc error\n");
		return -1;
	}
	
	printf("[%s]\n", intToRoman(atoi(argv[1])));
	return 0;
}
