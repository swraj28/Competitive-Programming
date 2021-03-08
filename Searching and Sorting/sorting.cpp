//various sorting algorithms(iterative as well as recursive)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//in every move ,place the largest element at the last.
void bubble_sort_itr(int arr[], int n) {

	int j = n - 1;
	while (j >= 1) {
		int no_of_swaps = 0; // Optimaization
		for (int i = 0; i < j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				no_of_swaps++;
			}
		}
		// If after any move no of swaps is zero then the array is sorted
		if (no_of_swaps == 0) {
			break;
		}
		j--;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubble_sort_rec(int arr[], int n) {
	if (n == 1) {
		return;
	}
	int no_of_swaps = 0;
	for (int i = 0; i < n - 1; i++) {//do the work for 1 element (Inner loop)
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			no_of_swaps++;
		}
	}

	if (no_of_swaps) {
		bubble_sort_rec(arr, n - 1);//ask recursion to do for (n-1)elements. (outer loop)
	}
}

void bubble_sort_complete_rec(int arr[], int j, int n) {
	if (n == 1) {
		return;
	}

	if (j == (n - 1)) {
		// Single Pass Of the Array Is Done
		bubble_sort_complete_rec(arr, 0, n - 1); // Recursive Call for outer loop
	}

	// Rec call for inner loop

	if (arr[j] > arr[j + 1]) {
		swap(arr[j], arr[j + 1]);
	}
	bubble_sort_complete_rec(arr, j + 1, n);
}

//in every move place the smallest element at the first
void selection_sort_itr(int arr[], int n) {

	int i = 0; //first_position
	while (i < n - 1) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
		i++;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void selection_sort_rec(int arr[], int n) {
	if (n == 0) {
		return;
	}
	for (int i = n - 1; i > 0; i--) {//do the work for 1 element
		if (arr[i] < arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
		}
	}
	selection_sort_rec(arr, n - 1);//ask recursion to do the smae for n-1
}

// Insertion sort works similar to the way you sort playing cards in your hands.
//the left hand will contain the sorted cards while the right hand will contain unsorted part.

// Best Case and Worst Case Analysis:-

void insertion_sort_itr(int arr[], int n) {

	int fp = 1;
	while (fp < n) {
		for (int i = fp - 1; i >= 0; i--) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			} else {
				break;
			}
		}
		fp++;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertion_sort_rec(int arr[], int n) {
	if (n == 0) {
		return;
	}

	insertion_sort_rec(arr, n - 1); //ask rec to sort the (n-1)elements.

	for (int i = n - 1; i > 0; i--) {//do the work for 1 element.
		if (arr[i] < arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
		} else {
			break;
		}
	}
}

void merge(int arr[], int n, int start, int end) {
	vector<int> v;
	int mid = start + (end - start) / 2;
	int i = 0, j = mid + 1;
	while (i <= mid and j <= end) {
		if (arr[i] <= arr[j]) {
			v.push_back(arr[i]);
			i++;
		} else {
			v.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		v.push_back(arr[i]);
		i++;
	}
	while (j <= end) {
		v.push_back(arr[j]);
		j++;
	}
	for (int i = 0; i < v.size(); i++) {
		arr[i] = v[i];
	}
}
//merge sort-(recursive)
void merge_sort(int arr[], int n, int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = start + (end - start) / 2;
	merge_sort(arr, n, start, mid);
	merge_sort(arr, n, mid + 1, end);

	merge(arr, n, start, end);
}

//merge sort-(iterative)i.e.two way merging
void merge_sort_itr(int arr[], int n) {

	for (int i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			merge(arr, n, i, i + 1);
		} else {
			merge(arr, n, i, i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

// Merge K sorted Array


//quick sort

//Randomization
void shuffle(int*a, int s, int e) {

	srand(time(NULL));

	int i, j;
	for (i = e; i > 0; i--) {
		//Create one random index outof (i+1) element
		j = rand() % (i + 1);
		swap(a[i], a[j]);
	}
}

int partition(int *a, int s, int e) {

	int pivot = a[e];
	int i = s - 1;
	int j = s;
	for (; j < e; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[e]);

	return i + 1;
}

void quick_sort(int*a, int s, int e) {
	if (s >= e) {
		return;
	}

	int p = partition(a, s, e);

	quick_sort(a, s, p - 1);
	quick_sort(a, p + 1, e);
}
//counting sort
//heap sort
//radix sort
//bucket sort
//dnf sort


int main() {

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubble_sort_itr(arr, n);
	bubble_sort_rec(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// selection_sort_itr(arr, n);
	// selection_sort_rec(arr, n);
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	// insertion_sort_itr(arr, n);
	// insertion_sort_rec(arr, n);
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	// merge_sort(arr, n, 0, n - 1);
	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// merge_sort_itr(arr, n);
	// cout<<endl;

	// shuffle(arr, 0, n - 1);
	// quick_sort(arr, 0, n - 1);

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	return 0;
}