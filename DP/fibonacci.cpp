//  Calculate Fibonacci number i.e  0, 1, 1, 2, 3, 5, 8 ...
#include<bits/stdc++.h>
#include<string.h>
using namespace std;


// fibonacci number using recursion
int fibRec(int n) {
	if (n <= 1)
		return n;
	return fibRec(n - 1) + fibRec(n - 2);
}


// fibonacci number using memoization
int fibMemo(int n , vector<int> &dp) {
	if ( n <= 1)
		return n;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}


// fibonacci number using Tabulation
int fibTab(int n , vector<int> &dp) {
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

// fibonacci number using space Optimisation
int fibSpc(int n) {
	int prev = 1;
	int prev2 = 0;
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
	cout << fibRec(n) << endl;
	vector<int> dp(n + 1, -1);
	cout << fibMemo(n, dp) << endl;
	cout << fibTab(n, dp) << endl;
	cout << fibSpc(n);
	return 0;
}