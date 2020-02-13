#include <vector>
#include <cstdio>
#include <iostream>

const int maxsize = 80;
const int beeds   = 1001;

int main() {

	//char s[beeds];
	//char e[beeds];

	char s[beeds] = "";
	char e[beeds] = "";

	scanf("%s %s", s, e);


	std::vector<int> sr(maxsize, 0);
	std::vector<int> er(maxsize, 0);
	
	for (int i = 0; i < beeds; i++) {
		auto x = s[i];
		auto y = e[i];
		if ('0' <= x and x <= '9')
			sr[x - '0']++;
		else if ('a' <= x and x <= 'z')
			sr[x - 'a' + 10]++;
		else if ('A' <= x and x <= 'Z')
			sr[x - 'A' + 40]++;

		if ('0' <= y and y <= '9')
			er[y - '0']++;
		else if ('a' <= y and y <= 'z')
			er[y - 'a' + 10]++;
		else if ('A' <= y and y <= 'Z')
			er[y - 'A' + 40]++;
	}
	
	int lack = 0;
	int more = 0;
	for (int i = 0; i < maxsize; i++) {
		auto x = sr[i];
		auto y = er[i];
		if (y and x < y)
			lack += y - x;
		else
			more += x - y;	
	}
	
	if (lack)
		printf("No %d", lack);
	else
		printf("Yes %d", more);

	return 0;


}
