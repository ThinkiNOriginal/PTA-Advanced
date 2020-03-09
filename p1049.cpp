#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;


int main() {
	string str;
	cin >> str;
	int len = str.size();
	int res = 0;
	for (int i = 0; i < len; i++) {
		string lstr = str.substr(0, i);
		string rstr = str.substr(i + 1);
		int l = lstr.empty() ? 0 : stoi(lstr);
		int r = rstr.empty() ? 0 : stoi(rstr);
		auto x = str[i];
		if (x == '0') {
			res += l * pow(10, len - i - 1);
		} else if (x == '1') {
			res += l * pow(10, len - i - 1) + r + 1;
		} else {
			res += (l + 1) * pow(10, len - i - 1);
		}
	}
	printf("%d\n", res);
	return 0;
}
			

