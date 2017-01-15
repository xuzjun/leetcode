#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman(int num)
{
	char *ret = calloc(64, sizeof(char));
	char *p = ret;

	int tmp, divisor = 1000; 
	char tab[4][3] = {
		{'I', 'V', 'X'},
		{'X', 'L', 'C'},
		{'C', 'D', 'M'},
		{'M', '-', '-'}
	}; 
	int t;
	while (divisor) {
		t = divisor == 1000 ? 3 : (divisor == 100 ? 2 : (divisor == 10 ? 1 : 0));
		tmp = num / divisor;
		switch (tmp) {
		case 1:
		case 2:
		case 3: {
			while (tmp--) *p++ = tab[t][0];
			break;
		}
		case 4: *p++ = tab[t][0]; *p++ = tab[t][1]; break;
		case 5: *p++ = tab[t][1]; break;
		case 6:
		case 7:
		case 8: {
			*p++ = tab[t][1];
			tmp -= 5;
			while (tmp--) *p++ = tab[t][0];
			break;
		}
		case 9: *p++ = tab[t][0]; *p++ = tab[t][2]; break;
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
