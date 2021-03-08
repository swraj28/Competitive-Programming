#include <bits/stdc++.h>
using namespace std;

//Iteration takes palce row wise
bool isSafe(int board[4][4], int row, int col, int n) {
	for (int i = 0; i < row; i++) { //checking in a particular column wheather a queen is present
		if (board[i][col]) {
			return false;
		}
	}

	int x = row;
	int y = col;

	while (x >= 0 and y < n) { //checking in the right diagonal wheather a queen is present
		if (board[x][y]) {
			return false;
		}
		x--;
		y++;
	}

	x = row;
	y = col;

	while (x >= 0 and y >= 0) { //checking in  the left diagonal wheather a queen is present
		if (board[x][y]) {
			return false;
		}
		x--;
		y--;
	}

	return true; //if none of the above cases satisfied it means we can palce a queen at that index
}

bool NQueens(int board[4][4], int row, int n) {
	//Base case
	if (row == n) {
		//you have successfully placed n queens in n rows numbered(0 to n-1).
		// print the board

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j]) {
					cout << "Q ";
				} else {
					cout << "_ ";
				}
			}
			cout << endl;
		}

		cout << "*****************" << endl;

		return true;
	}
	//Recursive case.
	// try to place the queen on the current row and call on the remaining row which will be solve by recursion.
	// isSafe() function determines whethear we can place a queen at any position (i,j)
	for (int col = 0; col < n; col++) {

		if (isSafe(board, row, col, n)) {
			//Place the queen-Assuming (i,j) is the right position
			board[row][col] = 1;

			bool rest_of_the_queens = NQueens(board, row + 1, n);

			if (rest_of_the_queens) {
				return true;
			}
			//it means (i,j) is not the right position-our assumption is wrong
			board[row][col] = 0; //Backtracking
		}

	}
	//you have tried for all position but couldn't palce the queen
	return false;
}

int countNQueens(int board[4][4], int row, int n) {

	if (row == n) { //base case.you have successfully placed n queens in n rows numbered (0 to n-1)
		return 1;
	}

	int count = 0;

	for (int col = 0; col < n; col++) {

		if (isSafe(board, row, col, n)) {

			board[row][col] = 1;

			count += countNQueens(board, row + 1, n);

			board[row][col] = 0;
		}

	}

	return count;
}

void printNQueens(int board[4][4], int row, int n) {

}

bool ratInAMaze(char maze[4][4], int sr, int sc, int er, int ec) {

	if (sr == er and sc == ec) {
		return true;
	}

	if (sr > er or sc > ec) {
		return false;
	}

	if (maze[sr][sc] == 'X') {
		return false;
	}

	bool horizontal = ratInAMaze(maze, sr, sc + 1, er, ec);
	bool vertical = ratInAMaze(maze, sr + 1, sc, er, ec);

	return horizontal or vertical;
}

void printRatInAMaze(char maze[4][4], int sol[4][4], int sr, int sc, int er, int ec) {
	if (sr == er and sc == ec) {
		// Print Path

		sol[er][ec] = 1;

		for (int i = 0; i <= er; i++) {
			for (int j = 0; j <= ec; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}

		cout << "******************" << endl;

		return;
	}
	//Rat should be present inside the maze
	if (sr > er or sc > ec) {
		return;
	}

	if (maze[sr][sc] == 'X') {
		return;
	}

	sol[sr][sc] = 1; //assume soln exist through the current cell

	printRatInAMaze(maze, sol, sr, sc + 1, er, ec);
	printRatInAMaze(maze, sol, sr + 1, sc, er, ec);

	//Backtracking
	sol[sr][sc] = 0;
}

bool isPossible(int mat[9][9], int row, int col, int n, int number) {

	for (int i = 0; i < n; i++) {
		if (mat[i][col] == number or mat[row][i] == number) {
			return false;
		}
	}

	int x_gridStarting = (row / 3) * 3;
	int y_gridStarting = (col / 3) * 3;

	for (int i = x_gridStarting; i < x_gridStarting + 3; i++) {
		for (int j = y_gridStarting; j < y_gridStarting + 3; j++) {

			if (mat[i][j] == number) {
				return false;
			}

		}
	}

	return true;
}

bool sudokuSolver(int mat[9][9], int row, int col, int n) {
	if (row == n) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return true;
	}

	if (col == n) {
		return sudokuSolver(mat, row + 1, 0, n);
	}

	if (mat[row][col] != 0) {
		return sudokuSolver(mat, row, col + 1, n);
	}

	for (int option = 1; option <= 9; option++) {

		if (isPossible(mat, row, col, n, option)) {

			mat[row][col] = option;

			bool baki_ka_sudoku = sudokuSolver(mat, row, col + 1, n);

			if (baki_ka_sudoku) {
				return true;
			}

			// Choice A
		}
		// Choice B
	}
	// Choice C
	mat[row][col] = 0;
	return false;
}

int main() {


	int board[4][4] = {0};
	int n = 4;

	// cout<<NQueens(board,0,n)<<endl;
	cout << countNQueens(board, 0, n) << endl;

	// char maze[][4] = {
	// 	{'0','0','0','0'},
	// 	{'0','0','0','X'},
	// 	{'0','0','0','0'},
	// 	{'0','X','0','0'},
	// };

	// int n=3;

	// int sol[4][4] = {0};

	// cout<<ratInAMaze(maze,0,0,n,n)<<endl;
	// printRatInAMaze(maze,sol,0,0,n,n);

	// int mat[9][9] = {
//            {5,3,0,0,7,0,0,0,0},
//            {6,0,0,1,9,5,0,0,0},
//            {0,9,8,0,0,0,0,6,0},
//            {8,0,0,0,6,0,0,0,3},
//            {4,0,0,8,0,3,0,0,1},
//            {7,0,0,0,2,0,0,0,6},
//            {0,6,0,0,0,0,2,8,0},
//            {0,0,0,4,1,9,0,0,5},
//            {0,0,0,0,8,0,0,7,9}
//    };

//    int n = 9;

//    cout<<sudokuSolver(mat,0,0,n)<<endl;

	return 0;
}