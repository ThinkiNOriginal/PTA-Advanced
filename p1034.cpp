#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

const int maxsize = 2000; // magic number;

struct Person {
	int gang;
	int total_time;
	int time;
};

struct Head {
	int val;
	int members;
};

Head BFS(vector<vector<int>>& graph, vector<bool>& vis, int cur,int threshold) {
	queue<int> q;
	q.push(cur);
	int total_time = 0;
	vector<int> head(maxsize, 0);
	unordered_set<int> cluster;
	while (!q.empty()) {
		auto x = q.front();
		cluster.insert(x);
		vis[x] = true;
		q.pop();
		for (int i = 0; i < maxsize; i++) {
			if (graph[x][i]) {
				q.push(i);
				total_time += graph[x][i];
				head[x] += graph[x][i];
				head[i] += graph[x][i];
				graph[x][i] = 0;
				graph[i][x] = 0;
			}
		}
	}
	Head res;
	auto members = cluster.size();
	if (total_time <= threshold or members < 3) 
		res.val = -1;
	else {
		int maxm = -1;
		int temp = -1;
		for (auto x : cluster) {
			if (head[x] > maxm) {
				maxm = head[x];
				temp = x;
			}
		}
		res.val = temp;
		res.members = members;
	}
	return res;
}
				


int main() {
	int N, K;
	cin >> N >> K;
	int cnt = -1;
	map<string,int> mapPerson;
	vector<bool> vis(maxsize, true);
	vector<vector<int>> graph(maxsize, vector<int>(maxsize, 0));
	for (int i = 0; i < N; i++) {
		string l, r;
		int time;
		cin >> l >> r >> time;
		int templ, tempr;

		if (!mapPerson.count(l)) {
			cnt++;
			mapPerson[l] = cnt;
			templ = cnt;
		} else {
			templ = mapPerson[l];
		}

		if (!mapPerson.count(r)) {
			cnt++;
			mapPerson[r] = cnt;
			tempr = cnt;
		} else {
			tempr = mapPerson[r];
		}

		graph[templ][tempr] += time;
		graph[tempr][templ] += time;
		vis[templ] = false;
		vis[tempr] = false;
			
	}

	map<string, int> mapRes;
	for (int i = 0; i < maxsize; i++) {
		if (!vis[i]) {
			auto ans = BFS(graph, vis, i, K);
			if (ans.val != -1) {
				for (auto x : mapPerson) {
					if (x.second == ans.val) {
						mapRes[x.first] = ans.members;
						break;
					}
				}
			}
		}
	}
	printf("%lu\n", mapRes.size());
	for (auto x : mapRes) {
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}




		
		


