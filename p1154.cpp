#include <vector>
#include <cstdio>
#include <unordered_set>


using namespace std;

struct Edge {
	int l;
	int r;
};

int kColors(vector<Edge>& edges, vector<int>& colors) {
	for (auto x : edges) {
		if (colors[x.l] == colors[x.r])
			return -1;
	}
	unordered_set<int> usc;
	for (auto x : colors)
		usc.insert(x);
	return usc.size();
}
	
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge> edges(M);
	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		edges[i].l = l;
		edges[i].r = r;
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		vector<int> color(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &color[j]);
		}
		auto res = kColors(edges, color);
		if (res == -1)
			printf("No\n");
		else
			printf("%d-coloring\n", res);

	}
	return 0;
}

