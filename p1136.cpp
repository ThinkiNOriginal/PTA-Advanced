#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isP(string str) {
	int len = str.size();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1])
			return false;
	}
	return true;
}

string delayed(string str, string rstr) {
	int len = str.size();
	int c = 0;
	for (int i = len - 1; i >= 0; i--) {
		auto cur = str[i] - '0' + rstr[i] - '0' + c;
		str[i] = cur % 10 + '0';
		c = cur / 10;
	}
	if (c) {
		str = '1' + str;
	}
	return str;
}


int main() {
	string str;
	cin >> str;
	bool find = false;
	int cnt = 0;
	while (cnt < 10) {
		if (isP(str)) {
			find = true;
			break;
		}
		string rstr = str;
		reverse(rstr.begin(), rstr.end());
		auto ans = delayed(str, rstr);
		cout << str << " + " << rstr<<" = " << ans << endl;
		str = ans;
		cnt++;
	}
	if (find)
		cout << str <<" is a palindromic number."<<endl;
	else 
		cout << "Not found in 10 iterations." << endl;
	return 0;
}


