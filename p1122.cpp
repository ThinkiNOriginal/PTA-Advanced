#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

bool isHC(vector<vector<bool>>& g, vector<int>& v) {
	int len = v.size();
	vector<bool> vis(g.size(), false);
	vis[0] = true;
	for (int i = 1; i < len; i++) {
		if (!vis[v[i]])
			vis[v[i]] = true;
		else
			return false;
		if (!g[v[i]][v[i - 1]])
			return false;
	}
	if (v[0] != v[len - 1])
		return false;

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
	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		graph[l][r] = true;
		graph[r][l] = true;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		vector<int> v(temp);
		for (int j = 0; j < temp; j++) {
			scanf("%d", &v[j]);
		}
		if (isHC(graph, v)) 
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
