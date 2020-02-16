#include <vector>
#include <cstdio>
#include <queue>

int BFS(std::vector<std::vector<int>>& graph, std::vector<bool>& vis, int cur) {
	std::queue<int> q;
	q.push(cur);
	vis[cur] = true;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (auto adj : graph[x]) {
			if (!vis[adj]) {
				vis[adj] = true;
				q.push(adj);
			}
		}
	}
	return 0;
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	std::vector<std::vector<int>> graph(N + 1);

	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i < K; i++) {
		int abrupt;
		scanf("%d", &abrupt);
		std::vector<bool> vis(N + 1, false);
		vis[abrupt] = true;
		int cnt = 0;
		for (int i = 1; i <=N; i++) {
			if (!vis[i]) {
				BFS(graph, vis, i);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}

	return 0;
}



