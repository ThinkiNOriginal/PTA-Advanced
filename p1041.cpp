#include <vector>
#include <iostream>
#include <cstdio>

const int maxsize = 100010;

int main() {
	int N;
	std::cin >> N;
	std::vector<int> v(maxsize, 0);
	int last = -1;
	int cur  = -1;
	std::vector<int> res(maxsize, 0);

	for (int i = 0; i < N; i++) {
		scanf("%d", &cur);
		v[cur]++;
		res[i] = cur;
	}

	for (auto x : res) {
		if (v[x] == 1) {
			printf("%d", x);
			return 0;
		}
	}

	printf("None");
	return 0;
}
		

