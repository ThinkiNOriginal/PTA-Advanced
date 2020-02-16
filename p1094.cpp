#include <vector>
#include <cstdio>
#include <queue>


int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	std::vector<std::vector<int>> tree(N + 1);
	for (int i = 0; i < M; i++) {
		int p, k;
		scanf("%d %d", &p, &k);
		for (int j = 0; j < k; j++) {
			int de;
			scanf("%d", &de);
			tree[p].push_back(de);
		}
	}

	std::queue<int> q;
	q.push(01);
	int generation = 0;
	int population = 0;
	int resg = 0;
	int len = q.size();

	while (len) {
		generation++;
		if (len > population) {
			resg = generation;
			population = len;
		}

		for (int i = 0; i < len; i++) {
			auto x = q.front();
			q.pop();
			for (auto y : tree[x])
				q.push(y);
		}
		
		len = q.size();
	}

	printf("%d %d", population, resg);
	return 0;
}

	

