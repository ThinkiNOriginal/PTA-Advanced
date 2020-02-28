#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

bool BFS(vector<vector<bool>>& graph) {
	int len = graph.size();
	vector<bool> vis(len, false);
	vis[0] = true;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (int i = 1; i < len; i++) {
			if (graph[x][i] and !vis[i]) {
				vis[i] = true;
				q.push(i);
			}
		}
	}
	for (auto x : vis) {
		if (!x)
			return false;
	}
	return true;
}


int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));
	vector<int> degrees(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		graph[l][r] = true;
		graph[r][l] = true;
		degrees[l]++;
		degrees[r]++;
	}

	int odds = 0;
	for (int i = 1; i <= N; i++) {
		if (i != 1)
			printf(" ");
		printf("%d", degrees[i]);
		if (degrees[i] % 2 != 0)
			odds++;
	}
	bool connected = BFS(graph);
	printf("\n");
	if (odds == 0 and connected)
		printf("Eulerian");
	else if (odds == 2 and connected) {
		printf("Semi-Eulerian");
	} else
		printf("Non-Eulerian");
	
	return 0;
}

