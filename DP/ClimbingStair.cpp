/*  You are climbing a staircase. It takes n steps to reach the top.
	Each time you can either climb 1 or 2 steps.
	then count number of ways to reach N and return it ;
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;


/* recursive count
	Time Complexity : O(2^N)
	Space Complexity : O(N)
*/
int csRec(int n) {
	if (n <= 1)
		return 1;
	return csRec(n - 1) + csRec(n - 2);
}


/* count using memoization dp
	Time Complexity : O(N)
	Space Complexity : O(N) for recusrion stack + O(N) for array space ≡ O(N)
*/
int csMemo(int n , vector<int> &dp) {
	if ( n <= 1)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = csMemo(n - 1, dp) + csMemo(n - 2, dp);
}



/* count using memoization dp
	Time Complexity : O(N)
	Siace Complexity : O(N) only for array space
*/
int csTab(int n , vector<int> &dp) {
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}


/* count using space Optimisation
	Time Complexity : O(N)
	Siace Complexity : O(1)
*/
int csSpace(int n) {
	int prev = 1;
	int prev2 = 1;
	int curr = 0;
	for (int i = 2; i <= n; i++)
	{
		curr = prev + prev2;
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
	cout << csRec(n) << endl;
	vector<int> dp(n + 1, -1);
	cout << csMemo(n, dp) << endl;
	cout << csTab(n, dp) << endl;
	cout << csSpace(n);
	return 0;
}