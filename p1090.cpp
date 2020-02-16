#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>

int main() {
	int N;
	double p, r;
	scanf("%d %lf %lf", &N, &p, &r);
	std::vector<std::vector<int>> graph(N);
	int root = -1;
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == -1)
			root = i;
		else
			graph[tmp].push_back(i);
			
	}

	std::queue<int> q;
	q.push(root);
	double highest = 0;
	int cnt = 0;
	int level = 0;
	int leaves;
	int len = q.size();

	while (len) {
		
        leaves = len;
		for (int i = 0; i < len; i++) {
			auto x = q.front();
			q.pop();
			for (auto y : graph[x]) {
				q.push(y);
			}
		}
		len = q.size();
		level++;
	}

	highest = std::pow(1 + 0.01 * r, level - 1) * p;

	printf("%.2lf %d", highest, leaves);
	return 0;
}

		




