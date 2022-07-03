/*
	Password Validator
	You are given a string, you need to tell password is valid or not
	password is valid if :
							It contain atleast Upper Case Character
							It contain atleast Lower Case Character
							It contain atleast one Integal Value
*/
#include <iostream>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int cntLower = 0, cntUpper = 0, cntInteger = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= 97 && str[i] <= 122) {
				cntLower += 1;
			}
			if (str[i] >= 65 && str[i] <= 90) {
				cntUpper += 1;
			}
			if (str[i] >= 48 && str[i] <= 57) {
				cntInteger += 1;
			}
		}
		if (cntLower >= 1 && cntUpper >= 1 && cntInteger >= 1) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}