#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman(int num)
{
	int tmp;
	char *ret = calloc(64, sizeof(char));
	char *p = ret;

	int divisor = 1000; 
	while (divisor) {
		tmp = num / divisor;
		if (tmp) {
			switch (divisor) {
			case 1000: {
				switch (tmp) {
					case 1: *p++ = 'M'; break;
					case 2: *p++ = 'M'; *p++ = 'M'; break;
					case 3: *p++ = 'M'; *p++ = 'M'; *p++ = 'M'; break;
				}
				break;
			}
			case 100: {
				switch (tmp) {
					case 1: *p++ = 'C'; break;
					case 2: *p++ = 'C'; *p++ = 'C'; break;
					case 3: *p++ = 'C'; *p++ = 'C'; *p++ = 'C'; break;
					case 4: *p++ = 'C'; *p++ = 'D'; break;
					case 5: *p++ = 'D'; break;
					case 6: *p++ = 'D'; *p++ = 'C'; break;
					case 7: *p++ = 'D'; *p++ = 'C'; *p++ = 'C'; break;
					case 8: *p++ = 'D'; *p++ = 'C'; *p++ = 'C'; *p++ = 'C'; break;
					case 9: *p++ = 'C'; *p++ = 'M'; break;
				}
				break;
			}
			case 10: {
				switch (tmp) {
					case 1: *p++ = 'X'; break;
					case 2: *p++ = 'X'; *p++ = 'X'; break;
					case 3: *p++ = 'X'; *p++ = 'X'; *p++ = 'X'; break;
					case 4: *p++ = 'X'; *p++ = 'L'; break;
					case 5: *p++ = 'L'; break;
					case 6: *p++ = 'L'; *p++ = 'X'; break;
					case 7: *p++ = 'L'; *p++ = 'X'; *p++ = 'X'; break;
					case 8: *p++ = 'L'; *p++ = 'X'; *p++ = 'X'; *p++ = 'X'; break;
					case 9: *p++ = 'X'; *p++ = 'C'; break;
				}
				break;
			}
			case 1: {
				switch (tmp) {
					case 1: *p++ = 'I'; break;
					case 2: *p++ = 'I'; *p++ = 'I'; break;
					case 3: *p++ = 'I'; *p++ = 'I'; *p++ = 'I'; break;
					case 4: *p++ = 'I'; *p++ = 'V'; break;
					case 5: *p++ = 'V'; break;
					case 6: *p++ = 'V'; *p++ = 'I'; break;
					case 7: *p++ = 'V'; *p++ = 'I'; *p++ = 'I'; break;
					case 8: *p++ = 'V'; *p++ = 'I'; *p++ = 'I'; *p++ = 'I'; break;
					case 9: *p++ = 'I'; *p++ = 'X'; break;
				}
				break;
			}
			}
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
