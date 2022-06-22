// Print any one Subsequence whose sum is k
#include<bits/stdc++.h>
using namespace std;

bool printSubsequence (int index, vector<int> &v, int k , int sum, int arr[], int n) {
	if (index == n)
	{
		// codition satisfied
		if (sum == k) {
			for (auto it : v)
				cout << it << " ";
			cout << endl;
			return true;
		}
		// not satisfy
		return false;
	}
	// Take or pick particular index element into the subsequence
	v.push_back(arr[index]);
	sum += arr[index];
	if (printSubsequence(index + 1, v, k, sum, arr, n) == true) {
		return true;
	}
	// Not Take or don't pick particular index element into the subsequence
	v.pop_back();
	sum -= arr[index];
	if (printSubsequence(index + 1, v, k, sum, arr, n) == true) {
		return true;
	}
	return false;
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
	printSubsequence(0, v, k, sum, arr, n);
	return 0;
}

