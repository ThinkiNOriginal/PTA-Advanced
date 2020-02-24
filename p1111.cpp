#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxcost = 1 << 20;

struct Node {
	int len = maxcost;
	int time = maxcost;
	bool oneway = false;
};


void Dijskra(vector<vector<Node>>& graph, vector<int>& prevD, vector<int>& prevT, vector<int>& dis, vector<int>& Ttime, int s, int e) {
	
	int len = graph.size();
	vector<bool> vis(len, false);
	vector<int> time(len, maxcost);
	vis[s] = true;
	auto tmpvis = vis;
	dis[s] = 0;
	time[s] = 0;
	Ttime[s] = 0;
	vector<int> inter(len, 0);
	inter[s] = 1;
	int current = s;
	
	while (!vis[e]) {
		for (int i = 0; i < len; i++) {
			if (!vis[i] and graph[current][i].len != maxcost) {
				auto x = graph[current][i].len + dis[current];
				auto y = graph[current][i].time + time[current];
				if (x < dis[i]) {
					dis[i] = x;
					time[i] = y; 
					prevD[i] = current;
				} else if (x == dis[i]) {
					if (y < time[i]) {
						time[i] = y;
						prevD[i] = current;
					}
				}
			}
		}
		int minD = maxcost;
		for (int i = 0; i < len; i++) {
			if (!vis[i]) {
				if (dis[i] < minD) {
					minD = dis[i];
					current = i;
				}
			}
		}
		vis[current] = true;
	}
	
	vis = tmpvis;
	current = s;
	while (!vis[e]) {
		for (int i = 0; i < len; i++) {
			if (!vis[i] and graph[current][i].len != maxcost) {
				auto z = graph[current][i].time + Ttime[current];
				if (z < Ttime[i]) {
					Ttime[i] = z;
					prevT[i] = current;
					inter[i] = inter[current] + 1;
				} else if (z == Ttime[i]) {
					if (inter[i] > inter[current] + 1) {
						inter[i] = inter[current] + 1;
						prevT[i] = current;
					}
				}
			}
		}
		int minD = maxcost;
		for (int i = 0; i < len; i++) {
			if (!vis[i]) {
				if (Ttime[i] < minD) {
					minD = dis[i];
					current = i;
				}
			}
		}
		vis[current] = true;
	}
}

int main () {

	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<Node>> graph(N, vector<Node>(N));

	for (int i = 0; i < M; i++) {
		int s, e, p, l, t;
		cin >> s >> e >> p >> l >> t;
		graph[s][e].len = l;
		graph[s][e].time = t;
		if (p == 0) {
			graph[e][s].len = l;
			graph[e][s].time = t;
		}

	
	}

	vector<int> prevD(N, -1);
	vector<int> prevT(N, -1);
	vector<int> dis(N, maxcost);
	vector<int> time(N, maxcost);
	int s, e;
	cin >> s >> e;
	Dijskra(graph, prevD, prevT, dis, time, s, e);
	vector<int> rd;
	int tmpe = e;
	while (tmpe != -1) {
		rd.push_back(tmpe);
		tmpe = prevD[tmpe];
	}
	vector<int> rt;
	tmpe = e;
	while (tmpe != -1) {
		rt.push_back(tmpe);
		tmpe = prevT[tmpe];
	}

	if (rt == rd) {
		printf("Distance = %d; ", dis[e]);
	} else {
		printf("Distance = %d: ", dis[e]);
		for (int i = rd.size() - 1; i > 0; i--) {
			printf("%d -> ", rd[i]);
		}
		printf("%d\n", rd[0]);
	}
	printf("Time = %d: ", time[e]);
	for (int i = rt.size() - 1; i > 0; i--) {
		printf("%d -> ", rt[i]);
	}
	printf("%d\n", rt[0]);


	return 0;
}


