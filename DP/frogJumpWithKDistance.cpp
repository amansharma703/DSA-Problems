/*
	There are N stones, numbered 1,2,…,N. For each i (1≤i≤N)

	There is a frog who is initially on Stone 1.
	He will repeat the following action some number of times to reach Stone N:

	If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K.
	Here, a cost of ∣hi-hj| is incurred, where j is the stone to land on.
	Find the minimum possible total cost incurred before the frog reaches Stone N.
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;


/* recursive count
	Time Complexity : O(2^N * K)
	Space Complexity : O(N)
*/
int frogJumpKRec(int n, int k, vector<int> &height) {
	if (n == 0)
		return 0;
	int minJump = INT_MAX;
	for (int i = 1; i <= k; i++) {
		if (n - i >= 0) {
			int jump = frogJumpKRec(n - i, k, height) + abs(height[n] - height[n - i]);
			minJump = min(minJump, jump);
		}
	}
	return minJump;
}


/* count using memoization dp
	Time Complexity : O(N * K)
	Space Complexity : O(N) for recusrion stack + O(N) for array space ≡ O(N)
*/
int frogJumpKMemoDp(int n, int k , vector<int> &height , vector<int> &dp) {
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	int minJump = INT_MAX;

	for (int i = 1; i <= k; i++) {
		if (n - i >= 0) {
			int jump = frogJumpKRec(n - i, k, height) + abs(height[n] - height[n - i]);
			minJump = min(minJump, jump);
		}
	}

	return dp[n] = minJump;;
}



/* count using Tabulation dp
	Time Complexity : O(N * K)
	Space Complexity : O(N) only for array space
*/
int frogJumpKTab(int n , int k ,  vector<int> &height) {
	vector<int> dp(n, 0);
	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		int minJump = INT_MAX;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				int jump = dp[i - j] + abs(height[i] - height[i - j]);
				minJump = min(minJump, jump);
			}
		}

		dp[i] = minJump;
	}

	return dp[n - 1];
}


/* count using space Optimisation
	Time Complexity : O(N)
	Space Complexity : O(K) no need of space optimsation bcz if k==n then is TC : O(N)
*/



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> height ;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		height.push_back(x);
	}
	cout << frogJumpKRec(n - 1, k, height) << endl;
	vector<int> dp(n + 1, -1);
	cout << frogJumpKMemoDp(n - 1, k, height , dp) << endl;
	cout << frogJumpKTab(n, k, height) << endl;

	return 0;
}