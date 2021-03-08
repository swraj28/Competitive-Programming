#include <iostream>

using namespace std;

void printIncreasing(int n) {
	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	printIncreasing(n - 1);

	cout << n << endl;
}

int sumTillN(int n) {
	if (n == 0) {
		return 0;
	}

	int sumn1 = sumTillN(n - 1);
	int sumn = sumn1 + n;
	return sumn;
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}

	int factn1 = factorial(n - 1);
	int factn = n * factn1;
	return factn;
}

void printDecreasing(int n) {
	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	cout << n << endl;

	printDecreasing(n - 1);
}

int power(int n, int p) {
	if (p == 0) {
		return 1;
	}

	// if(p==1){
	// 	return n;
	// }

	int powern1 = power(n, p - 1);
	int powern = powern1 * n;
	return powern;
}

int powerBetter(int n, int p) { //t.c-o(logn) and s.c-o(logn)
	if (p == 0) {
		return 1;
	}

	int small_answer = powerBetter(n, p / 2);
	small_answer *= small_answer;

	if (p & 1) {
		return small_answer * n;
	}

	return small_answer;
}

// In this approach the whole is being passed at every call stack
// This is memory wise inefficient
bool is_sorted(int arr[], int si, int n) {
	if (si >= n - 1) {
		return true;
	}

	if (arr[si] <= arr[si + 1]) {
		return is_sorted(arr, si + 1, n);
	}
	return false;
}
// In this approach the pointer to the array is passed in
// every call stack not the whole array.
bool is_Sorted(int*arr, int n) {
	if (n == 1) {
		return true;
	}
	if (arr[0] <= arr[1]) {
		return is_Sorted(arr + 1, n - 1);
	}

	return false;
}
// Here the whole array is passed in every recursion call
// We can pass a pointer to the array in this aaproach also
//It is more efficiect(Conveting a for loop into recursion)
int linearSearch(int arr[], int si, int n, int data) {
	if (si == n) {
		return -1;
	}

	if (arr[si] == data) {
		return si;
	}

	return linearSearch(arr, si + 1, n, data); //directly returning the value of si
}

// Here a pointer to the array passes in the every recursion call
// Different approach
int Linear_search(int *arr, int n, int key) {
	if (n == 0) {
		return -1;
	}

	if (arr[0] == key) {
		return 0;
	}

	int idx = Linear_search(arr + 1, n - 1, key);
	if (idx == -1) {
		return -1;
	}

	return i + 1;
}

int main() {

	printIncreasing(5);

	cout << sumTillN(5) << endl;
	cout << factorial(5) << endl;

	cout << power(2, 5) << endl;

	int arr[] = {2, 3, 6, 6, 1, 2, 3, 4};
	int n = 8;
	int data = 6;

	cout << linearSearch(arr, 0, n, data) << endl;

	return 0;
}