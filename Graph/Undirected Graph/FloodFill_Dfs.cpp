#include<bits/stdc++.h>
using namespace std;
#define ll long long
int R;
int C;

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void print_mat(char mat[][50]) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void Flood_fill(char mat[][50], int i, int j, char ch, char color) {
	// BAse Case-MAtrix Boundary Condition
	if (i<0 or j<0 or i >= R or j >= C) {
		return;
	}
	//Figure Boundary Condition
	if (mat[i][j] != ch) {
		return;
	}

	//Recursive Call
	mat[i][j] = color;

	for (int k = 0; k < 4; k++) {
		Flood_fill(mat, i + dx[k], j + dy[k], ch, color);
	}

	return;
}

int main() {

	cin >> R >> C;

	char mat[15][50];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mat[i][j];
		}
	}

	print_mat(mat);
	Flood_fill(mat, 10, 14, '.', 'r');
	print_mat(mat);

	return 0;
}