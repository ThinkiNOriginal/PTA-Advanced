#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

struct Gap {
	int s;
	int e;
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int curV = 0;
	int close = 1 << 30;
	int i = 0;
	int j = 0;
	std::vector<int> r(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &r[i]);

	std::vector<Gap> res;
	while (i < N and j <= N) {
		if (curV < M) {
			curV += r[j];
			j++;
		} else if (curV > M) {
			close = std::min(close, curV);
			curV -= r[i];
			i++;
		} else {
			res.push_back({i, j - 1});
			curV -= r[i];
			i++;
		}
	}
//	printf("%d", close);

	if (res.empty()) {
		M = close;
		i = 0;
		j = 0;
		curV = 0;
	while (i < N and j <= N) {
		if (curV < M) {
			curV += r[j];
			j++;
		} else if (curV > M) {
			curV -= r[i];
			i++;
		} else {
			res.push_back({i, j - 1});
			curV -= r[i];
			i++;
		}
	}
	}

	for (auto x : res) {
		printf("%d-%d\n", x.s + 1, x.e + 1);
	}
	
	return 0;
}




