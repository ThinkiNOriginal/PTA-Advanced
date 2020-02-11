#include <cstdio>
#include <iostream>
#include <string>
#include <vector>


std::string d_to_13(int x) {
	int d2 = x / 13;
	int d1 = x % 13;
	std::vector<char> v{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
	std::string res;
	res += v[d2];
	res += v[d1];
	return res;
}

int main() {
	int x;
	printf("#");
	for (int i = 0; i < 3; i++) {
		std::cin >> x;
		printf("%s", d_to_13(x).c_str());
	}
	
	return 0;
}
