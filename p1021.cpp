#include <iostream>
#include <cstdio>
#include <vector>

int depth(std::vector<std::vector<int>>& g, int dis, int cur, std::vector<bool>& vis) {
	static int deepest = 0;
	if (!vis[cur]) {
		vis[cur] = true;
		dis++;
		deepest = max(deepest, dis);
		for (auto x : g[cur]) {
			depth(g, dis, x, vis);
		}
	}
	return deepest;
}
int main() {

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> tree(N + 1);
	std::vector<int> com(N + 1);
	
	for (int i = 0 ; i <= N; i++)
		com[i] = i;



	int s, e;
	for (int i = N - 2; i >= 0; i--) {
		std::cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	vector<int> deep(N + 1, 0);
	int maxe = 0;

	for (int i = 1; i <= N; i++) {
		std::vector<bool> vis(N + 1, false);
		deep[i] = depth(g, 0, i, vis);
		maxe = max(maxe, deep[i]);
	}





}
