/*
	Problem : House Robber 2
	Problem is similar to House RObber 1 but only difference is that
	Houses are in circular Arrangement, which means -
	1. If we start from 1st house, we can't rob last house
	2. If we start from 2nd house, we can rob last house
	3. Let start with both separately and return max of both
	4. if only 1 house present, directly rob it

*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

/*
	recursive count
	Time Complexity : O(2^N)
	Space Complexity : O(N)
*/
int maxAjRec(int n, vector<int> &arr) {
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
int maxAjMemo(int n, vector<int> &arr, vector<int> &dp) {
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
int maxAjTab(int n, vector<int> arr) {
	vector<int> dp(n , 0);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		int pick = arr[i];
		if (i > 1) {
			pick +=  dp[i - 2];
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
int maxAjSpace(int n, vector<int> &arr) {
	int prev = arr[0];
	int prev2 = 0;
	int curri = 0;
	for (int i = 1; i < n; i++) {
		int pick = arr[i];
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

	int arr[] = {1, 2, 3, 3, 12, 54, 76, 57, 12, 34};
	int n = sizeof(arr) / sizeof(int);
	vector<int> temp1, temp2;
	// due to circular nature , 1st and last can not include in the answer thats why
	//need to call the function by taking 1st element and not taking last element and vice versa
	for (int i = 0; i < n; i++) {
		if (i != 0) temp1.push_back(arr[i]);
		if (i != n - 1) temp2.push_back(arr[i]);
	}
	// if only one house is present directly rob it
	if (n == 1) {
		cout << arr[0] << endl;
	} else {
		cout << max(maxAjRec(temp1.size() - 1, temp1), maxAjRec(temp2.size() - 1, temp2)) << endl;
		vector<int> dp1(temp1.size(), -1);
		vector<int> dp2(temp2.size(), -1);
		cout << max(maxAjMemo(temp1.size() - 1, temp1, dp1), maxAjMemo(temp2.size() - 1, temp2, dp2)) << endl;
		cout << max(maxAjTab(temp1.size(), temp1), maxAjTab(temp2.size(), temp2)) << endl;
		cout << max(maxAjSpace(temp1.size(), temp1), maxAjSpace(temp2.size(), temp2)) << endl;
	}

	return 0;
}