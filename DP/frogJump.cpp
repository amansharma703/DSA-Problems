/*  There is a frog on the 1st step of an N stairs long staircase.
	The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.
	If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
	In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair.
	Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;


/* recursive count
	Time Complexity : O(2^N)
	Space Complexity : O(N)
*/
int frogJumpRec(int n, vector<int> &height) {
	if (n == 0)
		return 0;
	int left = frogJumpRec(n - 1, height) + abs(height[n] - height[n - 1]);
	int right = INT_MAX;
	if (n > 1)
		right = frogJumpRec(n - 2, height) + abs(height[n] - height[n - 2] );
	return min(left, right);
}


/* count using memoization dp
	Time Complexity : O(N)
	Space Complexity : O(N) for recusrion stack + O(N) for array space ≡ O(N)
*/
int frogMemoDp(int n, vector<int> &height , vector<int> &dp) {
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	int left = frogMemoDp(n - 1, height, dp) + abs(height[n] - height[n - 1]);
	int right = INT_MAX;
	if (n > 1)
		right = frogMemoDp(n - 2, height, dp) + abs(height[n] - height[n - 2] );


	return dp[n] = min(left, right);;
}



/* count using Tabulation dp
	Time Complexity : O(N)
	Siace Complexity : O(N) only for array space
*/
int frogJumpTab(int n , vector<int> &height) {
	vector<int> dp(n, 0);
	dp[0] = 0;


	for (int i = 1; i < n; i++) {
		int l = dp[i - 1] + abs(height[i] - height[i - 1]);
		int r = INT_MAX;
		if (i > 1) {
			r = dp[i - 2] + abs(height[i] - height[i - 2]);
		}
		dp[i] = min(l, r);
	}

	return dp[n - 1];
}


/* count using space Optimisation
	Time Complexity : O(N)
	Siace Complexity : O(1)
*/
int frogJumpSpace(int n, vector<int> &height) {
	int prev = 0;
	int prev2 = 0;
	int curr = 0;
	for (int i = 1; i < n; i++) {
		int l = prev + abs(height[i] - height[i - 1]);
		int r = INT_MAX;
		if (i > 1) {
			r = prev2 + abs(height[i] - height[i - 2]);
		}
		curr  = min(l, r);
		prev2 = prev;
		prev = curr;
	}
	return prev;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> height ;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		height.push_back(x);
	}
	cout << frogJumpRec(n - 1, height) << endl;
	vector<int> dp(n + 1, -1);
	cout << frogMemoDp(n - 1, height , dp) << endl;
	cout << frogJumpTab(n, height) << endl;
	cout << frogJumpSpace(n, height);
	return 0;
}