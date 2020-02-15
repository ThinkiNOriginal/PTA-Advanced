#include <string>
#include <algorithm>
#include <vector>
#include <iostream>


int main() {
	std::string s;
	std::cin >> s;
	int len = s.size();
	while (4 - len) {
		len++;
		s = '0' + s;
	}
	std::string big = s;
	std::string lit = s;
	std::sort(big.begin(), big.end(), std::greater<char>());
	std::sort(lit.begin(), lit.end(), std::less<char>());
	bool suc = false;
	while (big != lit) {
		auto x = stoi(big) - stoi(lit);
		s = std::to_string(x);
		printf("%s - %s = %04d\n", big.c_str(), lit.c_str(), x);
		if (x == 6174) {
			suc = true;
			break;
		}
		int len = s.size();
		while (4 - len) {
			s = '0' + s;
			len++;
		}
		big = s;
		lit = s;
		std::sort(big.begin(), big.end(), std::greater<char>());
		std::sort(lit.begin(), lit.end());
	}
	if (!suc) {
		printf("%s - %s = 0000", big.c_str(), lit.c_str());
	}
		
	return 0;
}
