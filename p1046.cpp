#include <algorithm>
#include <cstdio>
#include <vector>

int main() {

	int N;
	scanf("%d", &N);
	std::vector<int> v(N + 1, 0);
	int total_dis = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i]);
		total_dis += v[i];
	}

	std::vector<int> r(N + 1, 0);
	for (int i = 1; i <= N; i++)
		r[i] = r[i - 1] + v[i];

	int M;
	scanf("%d", &M);
	while (M--) {
		int s, e;
		scanf("%d %d", &s, &e);
		int mid = s < e ? r[e - 1] - r[s - 1] : r[s - 1] - r[e - 1]; 
		printf("%d\n", std::min(mid, total_dis - mid));
	}
	return 0;
}
