#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main() {

	std::string s;
	std::cin >> s;
//	int len = s.size();
	int summ = 0;
	for (auto x : s)
		summ += x - '0';
	std::string res = std::to_string(summ);
	int len = res.size();
	std::vector<std::string> rec{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (int i = 0; i < len; i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << rec[res[i] - '0'];
	}
	return 0;
}
