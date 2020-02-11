#include <cstdio>
#include <vector>
#include <iostream>
#include <string>


int main() {
	
	std::string s;
	std::cin >> s;
	
	int len = s.size();
	int ver = (len + 2) / 3 - 1;
	int bot = len - 2 * ver;
	int cur = 0;
	int space = bot - 2;

	for (int i = 0; i < ver; i++) {
		printf("%c", s[cur]);
		for (int sp = 0; sp < space; sp++)
			printf(" ");
		printf("%c\n", s[len - cur - 1]);
		cur++;
	}

	for (int i = 0; i < bot; i++) {
		printf("%c", s[cur]);
		cur++;
	}

	return 0;
}
