#include <cstdio>
#include <iostream>
#include <string>


int main() {

	int M;
	scanf("%d", &M);
	std::string unlock = "23:59:59";
	std::string lock   = "00:00:00";
	std::string resS, resE;

	while (M) {
		M--;
		std::string id, start, end;
		std::cin >> id >> start >> end;
		if (start < unlock) {
			unlock = start;
			resS = id;
		}
		if (end > lock) {
			lock = end;
			resE = id;
		}
	}

	printf("%s %s", resS.c_str(), resE.c_str());
	
	return 0;
}
