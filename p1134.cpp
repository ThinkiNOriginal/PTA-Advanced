#include <unordered_set>
#include <vector>
#include <cstdio>

using namespace std;

struct Edge {
	int l;
	int r;
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge> edges(M);
	for (int i = 0; i < M; i++) {
		int tl, tr;
		scanf("%d %d", &tl, &tr);
		Edge e;
		e.l = tl;
		e.r = tr;
		edges[i] = e;
	}

	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int nv;
		scanf("%d", &nv);
		unordered_set<int> vertex;
		for (int j = 0; j < nv; j++) {
			int tv;
			scanf("%d", &tv);
			vertex.insert(tv);
		}
		bool no = false;
		for (auto x : edges) {
			if (vertex.count(x.l) or vertex.count(x.r)){
				continue;
			} else {
				no = true;
				break;
			}
		}
		if (no)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}


		
