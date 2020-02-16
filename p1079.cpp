#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>


int main() {
	int N;
	double p, r;
	scanf("%d %lf %lf", &N, &p, &r);

	std::vector<std::vector<int>> graph(N);
	int rootP = 0;
	
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &k);
			graph[i].push_back(-k);
		} else {
		for (int j = 0; j < k; j++) {
			int tmp;
			scanf("%d", &tmp);
			graph[i].push_back(tmp);
		}
		}
	}

	std::queue<int> q;
	q.push(rootP);
	double totalsales = 0;
	int len = q.size();
	int level = 0;
	while (len) {
		for (int i = 0; i < len; i++) {
			auto x = q.front();
			q.pop();
			if (graph[x][0] < 0) {
				totalsales += std::pow(1 + 0.01 * r, level) * p * (-graph[x][0]);
			} else {
				for (auto y : graph[x])
					q.push(y);
			}
		}
		level++;
		len = q.size();
	}

	printf("%.1lf", totalsales);
	return 0;
}




