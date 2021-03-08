#include <bits/stdc++.h>

using namespace std;

string replacePi(string str) {
	if (str.length() == 0) {
		return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = replacePi(ros);

	if (ch == 'p' and recursionResult[0] == 'i') {
		return "3.14" + recursionResult.substr(1);

	} else {
		return ch + recursionResult;
	}
}

void printSubsequence(string str, string ans) { //string ans is an empty string.
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros, ans);
	printSubsequence(ros, ans + ch);
}

void printPermuatations(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	for (int i = 0; i < str.length(); i++) {

		char ch = str[i];

		string ros = str.substr(0, i) + str.substr(i + 1);

		printPermuatations(ros, ans + ch);

	}
}

bool can_swap(char arr[], int si, int curr) //take the example "abb" to understad the can_swap() function
{
	for (int i = si; i < curr; i++)
	{
		if (arr[i] == arr[curr])
		{
			return false;
		}
	}

	return true;
}

void permute(char arr[], int si) //print all the distinct permutations recursively
{
	if (si == strlen(arr) - 1)
	{
		cout << arr << endl;
		return;
	}

	for (int i = si; i < strlen(arr); i++)
	{
		if (can_swap(arr, si, i))
		{
			swap(arr[si], arr[i]);

			permute(arr, si + 1);

			swap(arr[si], arr[i]); //backtracking
		}
	}
}
//subsets ans subsequences are same
void sub_set(int arr[], int n, int si, vector<int> &v) { //to generate all the power set of a set recursively

	if (si == n) {

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	v.push_back(arr[si]);

	sub_set(arr, n, si + 1, v);

	v.pop_back();  //backtracking

	sub_set(arr, n, si + 1, v);
}

bool subset_target(int arr[], int n, int si, int target) {
	if (target == 0) {
		return true;
	}

	if (si >= n and target != 0) {
		return false;
	}
	if (target >= arr[si]) {  //check if target can be obtained by any one of the following;1.including si.2.excluding si.
		return subset_target(arr, n, si + 1 , target) or subset_target(arr, n, si + 1 , target - arr[si]);
	} else {
		return subset_target(arr, n, si + 1, target);
	}
}

//we can print substrings by using this as well.(as subarary and substrings are same (n*(n+1)/2) in no)
void print_subarray(int arr[], int n, int start, int end) {

	if (end == n ) { //stop if we reach at the end of the array
		return;
	}

	if (start > end) { //increment the end point and start from 0
		print_subarray(arr, n, 0, end + 1);
	}
	else
	{
		for (int i = start; i < end; i++) {
			cout << arr[i] << " ";
		}
		cout << arr[end] << endl;

		print_subarray(arr, n, start + 1, end);
	}
}

void mappedString(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch1 = str[0];
	string ros1 = str.substr(1);

	int ch1_int = ch1 - '0';

	ch1 = ch1 - '0' + 'A' - 1;

	mappedString(ros1, ans + ch1);

	if (str.length() > 1) {

		char ch2 = str[1];

		int ch2_int = ch2 - '0';

		int second_number = ch1_int * 10 + ch2_int;

		if (second_number <= 26) {

			ch2 = second_number + 'A' - 1;

			string ros2 = str.substr(2);

			mappedString(ros2, ans + ch2);
		}
	}

}

string code[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeyPad(string str, string ans) {
	if (str.length() == 0) {
		cout << ans << endl;
		return;
	}

	char ch = str[0];
	int idx = ch - '0';

	string key = code[idx];

	string ros = str.substr(1);

	for (int i = 0; i < key.length(); i++) {
		char keyChar = key[i];
		printKeyPad(ros, ans + keyChar);
	}
}

void printBoardPath(int start, int end, string ans) {
	if (start == end) {
		cout << ans << endl;
		return;
	}

	if (start > end) {
		return;
	}


	for (int dice = 1; dice <= 6; dice++) {
		char ch = dice + '0';
		printBoardPath(start + dice, end, ans + ch);
	}
	// return;
}

void printMazePath(int sr, int sc, int er, int ec, string ans) {

	if (sr == er and ec == sc) {
		cout << ans << endl;
		return;
	}

	if (sr > er or sc > ec) {
		return;
	}

	printMazePath(sr + 1, sc, er, ec, ans + "V");
	printMazePath(sr, sc + 1, er, ec, ans + "H");

	// return;
}

int reduceToOne(int n) {
	if (n == 1) {
		return 0;
	}

	int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

	if (n % 2 == 0) {
		count2 = reduceToOne(n / 2) + 1;
	}

	if (n % 3 == 0) {
		count3 = reduceToOne(n / 3) + 1;
	}

	count1 = reduceToOne(n - 1) + 1;

	return min(count1, min(count2, count3));

}

// Perfect Squares

int numSquares(int n) {
	if (n == 0) {
		return 0;
	}

	int minValue = INT_MAX;

	for (int i = 1; i * i <= n; i++) {

		int abhiTakKaAnswer = numSquares(n - i * i) + 1;

		minValue = min(minValue, abhiTakKaAnswer);
	}

	return minValue;
}

// Partition Equal Subset Sum

bool isPossible(int nums[], int si, int sum, int total, int n) {

	if (2 * sum == total) {
		return true;
	}

	if (si == n or 2 * sum > total) {
		return false;
	}

	//Recursive Case

	bool exclude = isPossible(nums, si + 1, sum, total, n);
	bool include = isPossible(nums, si + 1, sum + nums[si], total, n);

	return exclude || include;
}

bool canPartition(int nums[], int n) { //leetcode

	int total = 0;

	for (int i = 0; i < n; i++) {
		total += nums[i];
	}

	if (total & 1) { //if total is odd
		return false;
	}

	return isPossible(nums, 0, 0, total, n);
}

// Palindrome Partitioning 2(leetcode)

bool isPalindrome(string str, int left, int right) {
	while (left <= right) {
		if (str[left] != str[right]) {
			return false;
		}
		left++;
		right--;
	}

	return true;
}

int minimumNumberOfCuts(string str, int start, int end) {
	if (start > end) {
		return 0;
	}

	if (start == end) {
		return 0;
	}

	if (end - start == 1) {
		return str[start] != str[end];
		// return 0;
	}

	if (isPalindrome(str, start, end)) {
		return 0;
	}

	int minValue = INT_MAX;

	for (int i = start; i < end; i++) {

		int leftCuts = minimumNumberOfCuts(str, start, i);
		int rightCuts = minimumNumberOfCuts(str, i + 1, end);

		int abhiTakKaAnswer = leftCuts + 1 + rightCuts;

		minValue = min(minValue, abhiTakKaAnswer);
	}

	return minValue;

}

int main() {

	cout << replacePi("xxpiipxxipi") << endl;
	cout << replacePi("pixxippixx") << endl;

	printSubsequence("aaa", "");

	printPermuatations("abc", "");

	char arr[1000];

	cin >> arr;

	permute(arr, 0);

	mappedString("1234", "");

	char ch = '7';

	printKeyPad("234", "");

	printPermuatations("abc", "");

	printBoardPath(0, 10, "");

	printMazePath(0, 0, 2, 2, "");

	cout << reduceToOne(21) << endl;

	cout << numSquares(13) << endl;

	int nums[] = {1, 11, 5, 5};
	int n = 4;

	cout << canPartition(nums, n) << endl;

	int ch_int = ch - '0';
	cout << ch_int << endl;

	char assignedAlphabet = ch - '0' + 'A' - 1;

	cout << assignedAlphabet << endl;

	string str;
	cin >> str;

	cout << minimumNumberOfCuts(str, 0, str.length() - 1) << endl;

	return 0;
}

// // Using Swap
// void Permuatations(string str,string ans){
// 	if(str.length()==0){
// 		cout<<ans<<endl;
// 		return;
// 	}

// 	for(int i=0;i<str.length();i++){

// 		swap(str[0],str[i]);

// 		char ch = str[0];

// 		string ros = str.substr(1);
// 		Permuatations(ros,ans+ch);
// 		swap(str[0],str[i]);
// 	}
// }