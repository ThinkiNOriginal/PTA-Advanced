#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;

const int maxsize = 1 << 30;

int Dijskra(vector<vector<int>>& graph, vector<int>& happiness, vector<int>& cities, vector<int>& prev, vector<int>& dis, vector<int>& hap, int s, int e) {
	int len = happiness.size();
	vector<int> routes(len, 0);
	routes[s] = 1;
	vector<bool> vis(len, false);
	vis[s] = true;
	dis[s] = 0;
	int current = s;
	
	while (!vis[e]) {
		for (int i = 0; i < len; i++) {
			if (!vis[i] and graph[current][i]) {
				auto tempd = dis[current] + graph[current][i];
				if (tempd < dis[i]) {
					dis[i] = tempd;
					prev[i] = current;
					cities[i] = cities[current] + 1;
					hap[i] = hap[current] + happiness[i];
					routes[i] = routes[current];
				} else if (tempd == dis[i]) {
					auto temph = hap[current] + happiness[i];
					routes[i] += routes[current];
					if (temph > hap[i]) {
						hap[i] = temph;
						prev[i] = current;
						cities[i] = cities[current] + 1;
					} else if (temph == hap[i]) {
						auto tempc = cities[current] + 1;
						if (tempc < cities[i]) {
							cities[i] = tempc;
							prev[i] = current;
						}
					}
				}
			}
		}
		int cmpdis = maxsize;
		int cmphap = -1;
		int cmpcit = maxsize;
		for (int i = 0; i < len; i++) {
		//	if (!vis[i] and dis[i] < cmpdis) {
		//		current = i;
		//		cmpdis = dis[i];
		//	}
			if (!vis[i]) {
				if (dis[i] < cmpdis) {
					current = i;
					cmpdis = dis[i];
					cmphap = hap[i];
					cmpcit = cities[i];
				} else if (dis[i] == cmpdis) {
					if (hap[i] > cmphap) {
						cmphap = hap[i];
						current = i;
						cmpcit = cities[i];
					} else if (hap[i] == cmphap) {
						if (cmpcit > cities[i]) {
							current = i;
							cmpcit = cities[i];
						}
					}
				}
			}

		}
		vis[current] = true;
	}
	return routes[e];
}
					

	

int main() {
	int N, K;
	string S;
	cin >> N >> K >> S;
	map<string,int> rm;
	vector<int> happiness(N, 0);
	rm[S] = 0;
	for (int i = 1; i < N; i++) {
		string temps;
		int  tempi;
		cin >> temps >> tempi;
		rm[temps] = i;
		happiness[i] = tempi;
	}

	vector<vector<int>> graph(N, vector<int>(N, 0));
	for (int i = 0; i < K; i++) {
		string l, r;
		int tempc;
		cin >> l >> r >> tempc;
		int s = rm[l];
		int e = rm[r];
		graph[s][e] = tempc;
		graph[e][s] = tempc;
	}

	int len = N;
	vector<int> cities(len, 0);
	vector<int> prev(len, -1);
	vector<int> dis(len, maxsize);
	vector<int> hap(len, 0);
	int end = rm["ROM"];
	auto rs = Dijskra(graph, happiness,cities, prev, dis, hap, 0, end);
	printf("%d %d %d %d\n", rs, dis[end], hap[end], hap[end] / (cities[end]));
	vector<int> vr;
	while (end != -1) {
		vr.push_back(end);
		end = prev[end];
	}
	reverse(vr.begin(), vr.end());
	len = vr.size();
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf("->");
		for (auto x : rm) {
			if (x.second == vr[i]) {
				cout << x.first;
				break;
			}
		}
	}
	return 0;
}
	






	
