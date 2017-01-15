#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows)
{
	const int n = strlen(s);
	char *as = calloc(numRows * n, sizeof(char));

	int r, c;
	char *ret = calloc(n + 1, sizeof(char));
	if (numRows == 1) {
		memcpy(ret, s, n);
		return ret;
	}
	
	for (c = 0; c < n; ++c) {
		if (*s) {
			int t = c % (numRows - 1);
			if (t == 0) {
				for (r = 0; r < numRows && *s; ++r) {
					*(as + r * n + c) = *s++;
				}
			} else {
				*(as + (numRows - t - 1) * n + c) = *s++;
			}
		} else {
			break;
		}
	}


	int i = 0;
	for (r = 0; r < numRows; ++r) {
		for (c = 0; c < n; ++c) {
			if (*(as + r * n + c))
				ret[i++] = *(as + r * n + c);
		}
	}

	return ret;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "number of args error\n");
		return -1;
	}

	printf("[%s]\n", argv[1]);
	printf("[%s]\n", convert(argv[1], atoi(argv[2])));
	return 0;
}
