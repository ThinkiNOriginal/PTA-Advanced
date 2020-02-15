#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(std::string& s1, std::string& s2) {
	return s1 + s2 < s2 + s1;
}

int main() {
	int N;
	scanf("%d", &N);

	std::string res;
	std::string tmp;
	std::vector<std::string> r(N);
	for (int i = 0; i < N; i++) {
		std::cin >> r[i];
	}
	std::sort(r.begin(), r.end(), cmp);
	for (auto x : r)
		res += x;

//	for (int i = 0; i < N; i++) {
//		for (int j = i + 1; j < N; j++) {
//			if (r[i] + r[j] > r[j] + r[i]) {
//				std::swap(r[i], r[j]);
//			}
//		}
//		res += r[i];
//	}

	int i = 0;
	while (res[i] == '0') {
		i++;
	}
	res.erase(0, i);
	if (res.empty())
		res = "0";

	std::cout << res;
	return 0;
}
