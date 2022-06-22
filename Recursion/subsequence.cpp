#include<bits/stdc++.h>
using namespace std;

void printSubsequence (int index, vector<int> &v, int arr[], int n) {
	if (index == n)
	{
		for (auto it : v) {
			cout << it << " ";
		}
		if (v.size() == 0) {
			cout << "{}";
		}
		cout << endl;
		return;
	}
	// Take or pick particular index element into the subsequence
	v.push_back(arr[index]);
	printSubsequence(index + 1, v, arr, n);
	// Not Take or don't pick particular index element into the subsequence
	v.pop_back();
	printSubsequence(index + 1, v, arr, n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {3, 1, 2};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v;
	printSubsequence(0, v, arr, n);
	return 0;
}