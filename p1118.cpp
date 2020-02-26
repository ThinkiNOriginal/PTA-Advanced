#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxsize = 10010;


void BFS(vector<vector<int>>& graph, vector<int>& ancestor, vector<bool>& vis, int cur) {
	queue<int> q;
	int len = vis.size();
	q.push(cur);
	vis[cur] = true;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		//for (int i = 1; i <= len; i++) {
		//	if (graph[x][i] and !vis[i]) {
		//		vis[i] = true;
		//		q.push(i);
		//		ancestor[i] = cur;
		//	}
		//}
		for (auto y : graph[x]) {
			if (!vis[y]) {
				vis[y] = true;
				q.push(y);
				ancestor[y] = cur;
			}
		}

	}
		
}


int main () {
	int N;
	scanf("%d", &N);
	//vector<vector<int>> graph(maxsize, vector<int>(maxsize, 0));
	vector<vector<int>> graph(maxsize);
	vector<bool> birds(maxsize, false);
	int total_birds = 0;
	for (int i = 0; i < N; i++) {
		int c;
		scanf("%d", &c);
		vector<int> temp(c);
		for (int j = 0; j < c; j++) {
			scanf("%d", &temp[j]);
			if (!birds[temp[j]])
				total_birds++;
			birds[temp[j]] = true;
		}
		for (int j = 1; j < c; j++) {
			int s = temp[j - 1];
			int e = temp[j];
			//graph[s][e] = 1;
			//graph[e][s] = 1;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}
	}

	vector<bool> vis(total_birds + 1, false);
	vector<int> ancestor(total_birds + 1, 0);
	for (int i = 1; i <= total_birds; i++)
		ancestor[i] = i;

	int trees = 0;
	for (int i = 1; i <= total_birds; i++) {
		if (!vis[i]) {
			BFS(graph, ancestor, vis, i);
			trees++;
		}
	}

	printf("%d %d\n", trees, total_birds);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		if (ancestor[l] == ancestor[r])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

