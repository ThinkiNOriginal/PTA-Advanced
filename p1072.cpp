#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxsize = 1 << 30;

struct Station {
	float mindis = 1 << 20;
	int id;
	float avgdis = 0;
};

bool cmp (Station& s1, Station& s2) {
	if (s1.mindis != s2.mindis) {
		return s1.mindis > s2.mindis;
	} else {
		if (s1.avgdis != s2.avgdis) {
			return s1.avgdis < s2.avgdis;
		} else {
			return s1.id < s2.id;
		}
	}
}

Station Dijskra(vector<vector<int>>& graph, int s, int houses, int thresh) {
	int len = graph.size();
	vector<bool> vis(len, false);
	vector<int> dis(len, maxsize);
	vis[s] = true;
	dis[s] = 0;
	int cur = s;
	bool allvisited = false;
	while (!allvisited) {
		for (int i = 1; i < len; i++) {
			if (!vis[i] and graph[cur][i]) {
				auto tempdis = dis[cur] + graph[cur][i];
				if (tempdis < dis[i]) {
					dis[i] = tempdis;
				}
			}
		}
		int mindis = maxsize;
		for (int i = 1; i < len; i++) {
			if (!vis[i] and mindis > dis[i]) {
				mindis = dis[i];
				cur = i;
			}
		}
		vis[cur] = true;
		int total_dis = 0;
		float min_dis = maxsize;
		bool excess_range = false;

		allvisited = true;
		for (int i = 1; i <= houses; i++) {
			if (!vis[i]) {
				allvisited = false;
				break;
			}
			total_dis += dis[i];
			min_dis = min(min_dis, (float)dis[i]);
			if (!excess_range)
				excess_range = dis[i] > thresh;
		}
		
		if (allvisited) {
			Station res;
			res.avgdis = float(total_dis) / houses;
			res.mindis = min_dis;
			res.id = s - houses;
			if (excess_range)
				res.id = -1;
			return res;
		}
	}
}


int main() {
	int N, M, K, DS;
	cin >> N >> M >> K >> DS;
	int gsize = N + 1 + M;
	vector<vector<int>> graph(gsize, vector<int>(gsize, 0));
	for (int i = 0; i < K; i++) {
		string l, r;
		int c;
		cin >> l >> r >> c;
		int s, e;
		if (l[0] == 'G') {
			s = stoi(l.substr(1)) + N;
		} else {
			s = stoi(l);
		}
		if (r[0] == 'G') {
			e = stoi(r.substr(1)) + N;
		} else {
			e = stoi(r);
		}
		graph[s][e] = c;
		graph[e][s] = c;
	}

	vector<Station> res;
	for (int i = N + 1; i < gsize; i++) {
		auto temp = Dijskra(graph, i, N, DS);
		if (temp.id != -1) {
			res.push_back(temp);
		}
	}
	
	if (res.empty()) {
		printf("No Solution\n");
		return 0;
	}
	sort(res.begin(), res.end(), cmp);
	printf("G%d\n%.1f %.1f", res[0].id, res[0].mindis, res[0].avgdis);
	return 0;
}

			
