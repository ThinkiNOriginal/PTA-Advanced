#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxsize = 100010;

int main() {
	string str;
	cin >> str;
	char sign = str[0];
	int len = str.size();
	string exp;
	string real;
	char expsign;
	for (int i = 1; i < len; i++) {
		if (str[i] == '.') {
			continue;
		}
		if (str[i] == 'E') {
			expsign = str[i + 1];
			exp = str.substr(i + 2);
			break;
		}
		real += str[i];
	}

	int rlen = real.size();
	int expn = stoi(exp);
	auto ori = expn;
	if (expsign == '+') {
		while (expn >= rlen) {
			real += '0';
			expn--;
		}
		if (ori < rlen - 1) {
			real.insert(ori + 1, 1, '.');
		}
	} else if (expsign == '-') {
		expn--;
		while (expn) {
			real = '0' + real;
			expn--;
		}
		real = "0." + real;
	}
	
	if (sign == '-') {
		real = '-' + real;
	}
	cout << real << endl;
	return 0;
}




			


