#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

// Examcentre class

template <typename T = int>

class Examcentre {
public:
	T data;
	Examcentre<T> *left;
	Examcentre<T> *right;

	Examcentre(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
}

int examInstructor(Examcentre<int> *root) {


}
