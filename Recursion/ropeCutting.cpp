/*
Rope cutting problem
given n = length of rope

cut the rope in such a way that length of every piece (after cuts) should be in set {a,b,c}
0<a,b,c<=n

*/

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int ropeCut(int n, int a, int b, int c) {
	if (n == 0) return 0;
	if (n < 0) return -1;

	int res = max(ropeCut(n - a, a, b, c), max(ropeCut(n - b, a, b, c), ropeCut(n - c, a, b, c)));

	if (res == -1)
		return -1;
	return res + 1;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 25;
	int a = 5, b = 12, c = 13;
	cout << ropeCut(n, a, b, c);
	return 0;
}