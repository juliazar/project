#include <stdio.h>
#include "Parser.h"
#include "Game.h"
#define N  9


int main() {
	int numOfFixed;
	int **board;
	int i;
	board = calloc(N, sizeof(int *));
	for (i = 0; i < N; i++) {
		board[i] = calloc(N, sizeof(int));	}
	//numOfFixed = init();
	solve(board, N);
	printBoard(board, N);
	return 0;
}