#include <vector>
#include <cstdio>
#include <unordered_set>

using namespace std;

const int maxsize = 100001;

struct Edge {
	int l;
	int r;
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge> edges(N);
	for (int i = 0; i < N; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		edges[i].l = l;
		edges[i].r = r;
	}
	for (int i = 0; i < M; i++) {
		unordered_set<int> usgoods;
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int temp;
			scanf("%d", &temp);
			usgoods.insert(temp);
		}
		
		bool incompatible = false;
		for (auto x : edges) {
			if (usgoods.count(x.l) and usgoods.count(x.r)) {
				incompatible = true;
				printf("No\n");
				break;
			}
		}
		if (!incompatible) {
			printf("Yes\n");
		}
	}
	return 0;
}

	
