#include <cstdio>
#include <string>
#include <vector>
#include <iostream>


int main() {
	std::string s1;
	std::string s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);
	
	std::vector<bool> v(256, false);
	for (auto x : s2)
		v[x - 32] = true;

	int len = s1.size() - 1;
	int i = 0;
	while (len >= 0) {
		if (v[s1[len] - 32])
			s1.erase(len, 1);
		len--;
	}

	std::cout << s1;
	return 0;
}
