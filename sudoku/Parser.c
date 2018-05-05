#include "Parser.h"

int init() {
	int numOfFixed;
	int check;
	printf("Please enter the number of cells to fill [0-80]:\n");
	check = scanf("%d", &numOfFixed);
	while (numOfFixed < 0 || numOfFixed > 80) {
		if (check != 1) {
			exit(0);
		}
		printf("Error: Invalid number of cells "
				"to fill (should be between 0 and 80)\n");
		check = scanf("%d", &numOfFixed);
	}
	return numOfFixed;
}