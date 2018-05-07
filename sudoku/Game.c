

int solve(int **board,int n) {
	int row, col;
	int i;
	if (findEmpty(board, &row, &col, n) == 1) {
		return 1;
	}
	for (i = 1; i <= n; i++) {
		if (isValid(board, row, col, n, i) == 0) {
			continue;
		}
		board[row][col] = i;
		if (solve(board, n) == 1) {
			return 1;
		}
	}
	board[row][col] = 0;
	return 0;
}

/* returns 0 if there is an empty sell and sets (row, col) to be the coordinates
	of the next empty sell, returns 1 if the board if full */
int findEmpty(int **board, int *row, int *col, int n) {
	int i,j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				*row = i;
				*col = j;
				return 0;
			}
		}
	}
	return 1;
}

/* returns 1 if it is valid to put num in sell (row, col), otherwise
	return 0 */
/*change the hard-coded 3*/
int isValid(int **board, int row, int col, int n, int num) {
	int i;
	int j;
	int blockRow;
	int blockCol;

	for (i = 0; i < n; i++) {
		if (board[row][i] == num) {
			return 0;
		}
	}
	for (i = 0; i < n; i++) {
		if (board[i][col] == num) {
			return 0;
		}
	}
	/* add box checking */
	blockRow = row / 3;
	blockCol = col / 3;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[3 * blockRow + i][3 * blockCol + j] == num) {
				return 0;
			}
		}
	}

}

void printBoard(int **board, int n) {
	int i;
	int j;

	for (i = 0; i < n; i++) {
		if (i % 3 == 0) {
			printf("----------------------------------\n");
		}
		for (j = 0; j < n; j++) {
			if (j % 3 == 0) {
				printf("| ");
			}
			printf(" %d ", board[i][j]);
		}
		printf("%|\n");
	}
	printf("----------------------------------\n");
}