#include<bits/stdc++.h>
using namespace std;

int n = 5, m = 4;//n-no of edges and m-no of vertices
int adj[6][6];
int arr[4][2]; //It stores the conection betwwen the vertices

void create_adj_matrix() {

	//initialize all the elements of adj list to zero
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			adj[i][j] = 0;
		}
	}
	//traverse through the edge array
	for (int i = 0; i < m; i++) {
		int x = arr[i][0];
		int y = arr[i][1];

		adj[x][y] = 1;
		adj[y][x] = 1; //bidierctional edges
	}
	//print the adj matrix
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	create_adj_matrix();
}


