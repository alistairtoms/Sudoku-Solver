#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

/* function prototypes */
void build_grid(int G[][SIZE]);
void print_grid(int G[][SIZE], int solnum);
int solve(int G[][SIZE], int solnum);
int valid(int G[][SIZE], int value, int row, int col);
void build_grid2(int G[][SIZE]);


int
main(int argc, char* argv[]) {

	int G[SIZE][SIZE], solnum=1;

	build_grid(G);

	solve(G, solnum);

	return 0;
}


/* function that builds the grid based on user input */
void
build_grid(int G[][SIZE]) {

	printf("Enter in the intial sudoku board: ");

	int col, row, digit;
	for (row=0; row<SIZE; row++) {
		for (col=0; col<SIZE; col++) {
			scanf("%d", &digit);
			G[row][col] = digit;
		}
	}

	return;
}


/* function that prints out a grid */
void
print_grid(int G[][SIZE], int solnum) {

	printf("\n");
	printf("Solution number %d is:\n", solnum);
	printf("\n");

	int col, row;
	for (row=0; row<SIZE; row++) {
		for (col=0; col<SIZE; col++) {
			printf("%5d", G[row][col]);
		}
		printf("\n");
		printf("\n");
	}
	return;
}


/* recursive function that solves the sudoku */
int
solve(int G[][SIZE], int solnum) {

	int row, col, num;

	for (row=0; row<SIZE; row++) {
		for (col=0; col<SIZE; col++) {
			if (G[row][col] == 0) {
				for (num=1; num<=SIZE; num++) {
					if (valid(G, num, row, col)) {
						G[row][col] = num;
						solnum = solve(G, solnum);
						G[row][col] = 0;
					}
				}
				return solnum;
			}
		}
	}
	print_grid(G, solnum);
	solnum++;
	return solnum;
}


/* function that tests if a value can go at a given location */
int
valid(int G[][SIZE], int value, int row, int col) {

	int i, j;
	int x, y;

	/* check the row */
	for (i=0; i<SIZE; i++) {
		if (G[row][i] == value) {
			return 0;
		}
	}
	/* check the column */
	for (j=0; j<SIZE; j++) {
		if (G[j][col] == value) {
			return 0;
		}
	}
	/* check the square */
	x = (col/3)*3;
	y = (row/3)*3;

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			if (G[y+j][x+i] == value) {
				return 0;
			}
		}
	}
	/* otherwise return a 1 */
	return 1;
}