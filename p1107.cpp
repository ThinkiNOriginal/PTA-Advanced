#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>


using namespace std;

const int maxsize = 1001;


void BFS(vector<vector<int>>& people, vector<bool>& vis, int& members, int cur) {
	queue<int> q;
	q.push(cur);
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (auto y : people[x]) {
			if (!vis[y]) {
				vis[y] = true;
				q.push(y);
				members++;
			}
		}
	}
}


int main () {
	int N;
	scanf("%d", &N);
	vector<vector<int>> hobby(maxsize);
	//vector<vector<int>> people(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> people(N + 1);
	for (int i = 1; i <= N; i++) {
		int hs;
		scanf("%d:", &hs);
		for (int j = 0; j < hs; j++) {
			int tmp;
			scanf("%d", &tmp);
			hobby[tmp].push_back(i);
		}
	}

	for (int i = 1; i < maxsize; i++) {
		auto x = hobby[i];
		if (!x.empty()) {
			int len = x.size();
			for (int j = 1; j < len; j++) {
				auto l = x[j];
				auto r = x[j - 1];
				people[l].push_back(r);
				people[r].push_back(l);
			}
		}
	}

	vector<bool> vis(N + 1, false);
	vis[0] = true;
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		int members = 1;
		if (!vis[i]) {
			vis[i] = true;
			BFS(people, vis, members, i);
			res.push_back(members);
		}
	}

	sort(res.begin(), res.end(), greater<int>());
	int len = res.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	return 0;
}



