#include <algorithm>
#include <vector>
#include <cstdio>


int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	std::vector<int> v(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	std::sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (std::binary_search(v.begin() + i + 1, v.end(), M - v[i])) {
			printf("%d %d", v[i], M - v[i]);
			return 0;
		}
	}

	printf("No Solution");
	return 0;
}
