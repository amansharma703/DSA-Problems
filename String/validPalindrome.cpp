/*
	Problem : Valid Palindrome
	Check given string is Palindrome or not,
	by converting all uppercase letters into lowercase letters
	and removing all non-alphanumeric characters.
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

bool isPalindrome(string s) {
	string str = s;
	int left = 0;
	int right = str.size() - 1;
	while (left <= right) {
		swap(str[left], str[right]);
		left++;
		right--;
	}

	if (s == str) {
		return true;

	}
	else {

		return false;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	getline(cin, s);
	// convert string to lowercase
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string str = "";
	// copy s into str by skipping alphanumeric character
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			str += s[i];
		}
	}
	cout << isPalindrome(str) << endl;;
	return 0;
}