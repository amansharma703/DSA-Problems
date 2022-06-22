// Print count of Subsequences whose sum is k
#include<bits/stdc++.h>
using namespace std;

int printSubsequence (int index, vector<int> &v, int k , int sum, int arr[], int n) {
	if (index == n)
	{
		// codition satisfied
		if (sum == k) {
			return 1;
		}
		// not satisfy
		return 0;
	}
	// Take or pick particular index element into the subsequence
	v.push_back(arr[index]);
	sum += arr[index];
	int l  = printSubsequence(index + 1, v, k, sum, arr, n);

	// Not Take or don't pick particular index element into the subsequence
	v.pop_back();
	sum -= arr[index];
	int r  = printSubsequence(index + 1, v, k, sum, arr, n);
	return l + r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {3, 1, 2, 5, 4};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v;
	int k = 5;
	int sum = 0;
	cout << printSubsequence(0, v, k, sum, arr, n);
	return 0;
}

