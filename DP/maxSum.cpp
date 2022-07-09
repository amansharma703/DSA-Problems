/*
	Given an array representing money, find max amount, that can
	be robbed wihtout choosing the adjacent houses
	eg :  [2,7,9,3,1]  max_amount = 2 + 9 + 1 = 12
*/

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

/*
	recursive count
	Time Complexity : O(2^N)
	Space Complexity : O(N)
*/
int maxAjRec(int n, int arr[]) {
	if (n == 0) return arr[n];
	if (n < 0) return 0;
	int pick = arr[n] + maxAjRec(n - 2, arr);
	int notPick = 0 + maxAjRec(n - 1, arr);
	return max(pick, notPick);
}


/*
	Using memoization dp
	Time Complexity : O(N)
	Space Complexity : O(N) for recursion stack + O(N) for array space ≡ O(N)
*/
int maxAjMemo(int n, int arr[], vector<int> &dp) {
	if (n == 0) return arr[n];
	if (n < 0) return  0;
	if (dp[n] != -1 )
		return dp[n];
	int pick = arr[n] + maxAjMemo(n - 2, arr, dp);
	int notPick = 0 + maxAjMemo(n - 1, arr, dp);
	return dp[n] = max(pick, notPick);
}

/*
	Using Tabulation dp
	Time Complexity : O(N)
	Space Complexity : O(N) only for array space
*/
int maxAjTab(int n, int arr[]) {
	vector<int> dp(n , 0);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		int pick = arr[i];
		if (i > 1) {
			pick += dp[i - 2];
		}
		int notPick = 0 + dp[i - 1];
		dp[i] = max(pick, notPick);
	}
	return dp[n - 1];
}


/* count using space Optimisation
	Time Complexity : O(N)
	Space Complexity : O(1)
*/
int maxAjSpace(int n, int arr[]) {
	int prev = arr[0];
	int prev2 = 0;
	int curri = 0;
	for (int i = 1; i < n; i++) {
		int pick = arr[i] ;
		if (i > 1) {
			pick +=  prev2;
		}
		int notPick = 0 + prev;
		curri = max(pick, notPick);
		prev2 = prev;
		prev = curri;
	}
	return prev;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {2, 5, 4, 6, 7, 1, 4, 9, 1, 3, 6};
	int n = sizeof(arr) / sizeof(int);
	cout << maxAjRec(n - 1, arr) << endl;
	vector<int> dp(n, -1);
	cout << maxAjMemo(n - 1, arr, dp) << endl;
	cout << maxAjTab(n, arr) << endl;
	cout << maxAjSpace(n, arr) << endl;
	return 0;
}