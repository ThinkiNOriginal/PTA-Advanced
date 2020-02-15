#include <unordered_set>
#include <vector>
#include <cstdio>


int main () {
	int N;
	scanf("%d", &N);
	std::vector<std::unordered_set<int>> v(N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int j = 0; j < tmp; j++) {
			int cur;
			scanf("%d", &cur);
			v[i].insert(cur);
		}
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		s1--;
		s2--;
		int same = 0;
		int total = v[s1].size() + v[s2].size();
		for (auto x : v[s1]) {
			if (v[s2].count(x))
				same++;
		}
		printf("%.1f%%\n", float(same) / (total - same) * 100);
	}
	return 0;
}
