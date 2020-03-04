#include <vector>
#include <cstdio>

using namespace std;

bool not_topo(vector<vector<bool>> graph, vector<int> serial) {
	int len = serial.size();
	int glen = graph.size();
	int p = 0;
	while (p < len) {
		auto x = serial[p];
		for (int i = 1; i < glen; i++) {
			if (x != i and graph[i][x])
				return true;;
		}
		for (int i = 1; i < glen; i++) {
			graph[x][i] = false;
		}
		p++;
	}
	return false;
}
		

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		graph[s][e] = true;
	}
	int K;
	scanf("%d", &K);
	vector<int> res;
	for (int i = 0; i < K; i++) {
		vector<int> temp(N);
		for (int j = 0; j < N; j++)
			scanf("%d", &temp[j]);

		if (not_topo(graph, temp)) {
			res.push_back(i);
		}
	}
	int len = res.size();
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	return 0;
}
		

