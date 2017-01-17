/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

int findWord(char **board, int boardRowSize, int boardColSize, char* word, int i, int j) {
	
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	int i, j;

    for (i = 0; i < boardRowSize; ++i) {
    	for (j = 0; j < boardRowSize; ++j) {
			if (board[i][j] == word[0])
				findWord(** board, int boardRowSize, int boardColSize, char* word, i, j);
		}
	}
}

int main()
{

}
