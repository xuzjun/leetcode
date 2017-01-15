#include <stdio.h>
#include <stdlib.h>

#define TRUE   1
#define FALSE  0
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef int bool;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int depth(struct TreeNode *root)
{
	if (root == NULL) return 0;
	return MAX(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(struct TreeNode* root)
{
	if (root == NULL) return TRUE;
	int left = depth(root->left);
	int right = depth(root->right);
	return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

struct TreeNode *init_tree()
{
	return NULL;
}

void print_tree(struct TreeNode *root)
{

}

int main()
{
	struct TreeNode *root = init_tree();

	print_tree(root);

	int ret = isBalanced(root);

	if (ret)
		printf("It's a balance tree.\n");
	else
		printf("It's not a balance tree.\n");

	return 0;
}
