#include "Location2D.h"
#include <stdio.h>

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1,', '1', '1', '1'},
	{'e', '0', '1,', '0', '0', '1'},
	{'1', '0', '0,', '0', '1', '1'},
	{'1', '0', '1,', '0', '1', '1'},
	{'1', '0', '1,', '0', '0', 'x'},
	{'1', '1', '1,', '1', '1', '1'},
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

Location2D pcEntry, locExit;

static bool done = false;

void searchRecur(Location2D pt) {
	printf("%d,%d", pt.row, pt.col);
	if (done) return;
	if (pt == locExit) {
		done = true;
		return;
	}

	int r = pt.row;
	int c = pt.col;
	map[r][c] = '5';

	if (isValidLoc(r - 1, c)) searchRecur(Location2D(r - 1, c));
	if (isValidLoc(r + 1, c)) searchRecur(Location2D(r + 1, c));
	if (isValidLoc(r, c - 1)) searchRecur(Location2D(r , c - 1));
	if (isValidLoc(r, c + 1)) searchRecur(Location2D(r , c + 1));
}

void main()
{
	pcEntry.set(1, 0);
	locExit.set(4, 5);

	searchRecur(pcEntry);
	if (done)
		printf("\n ==> 출구가 탐지되었습니다.\n");
	else
		printf("\n ==> 출구를 찾지 못했습니다.\n");
}