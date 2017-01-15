#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define POINT_TAB_SIZE 26

typedef struct trie_node {
	int is_a_word;
	int frequence;
	void *ptr;
	struct trie_node *nodes[POINT_TAB_SIZE];
} Node;

Node *malloc_node()
{
	Node *n = calloc(1, sizeof(Node));
	return n;
}

void insert_word(Node *root, const char *word)
{
	int len = strlen(word);
	int pos;
	Node *p = root;

	int i;
	for (i = 0; i < len; ++i) {
		if (!isalpha(word[i]))
			continue;
		pos = tolower(word[i]) - 'a';
		if (p->nodes[pos] == NULL) {
			Node *n = malloc_node();
			p->nodes[pos] = n;
		}
		p = p->nodes[pos];
	}
	if (p != root) p->is_a_word = 1;
}

int find(Node *root, const char *word)
{
	int len = strlen(word);
	int pos;
	Node *p = root;

	int i;
	for (i = 0; i < len; ++i) {
		if (!isalpha(word[i])) continue;
		pos = tolower(word[i]) - 'a';
		if (p->nodes[pos] == NULL) return 0;
		p = p->nodes[pos];
	}
	if (p->is_a_word == 1)
		return 1;

	return 0;
}

Node *read_file(const char *filename)
{
	char *s[11] = {
		"add", "addition", "good", "go",
		"goose", "thank", "in", "inn",
		"an", "ant", "Hello"
	};
	Node *root = malloc_node();
	int i;
	for (i = 0; i < 11; i++)
		insert_word(root, s[i]);
	return root;
}


int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <filename> <word>\n", argv[0]);
		return -1;
	}

	Node *root = read_file(argv[1]);

	if (find(root, argv[2])) printf(">>>>find it[%s]\n", argv[2]);
	else printf(">>>>did not find it[%s]\n", argv[2]);

	return 0;
}
