#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxsize = 10000;

struct Family {
	int id;
	int members;
	double avgsets;
	double avgarea;
};

bool cmp (Family& f1, Family& f2) {
	if (f1.avgarea != f2.avgarea) {
		return f1.avgarea > f2.avgarea;
	} else {
		return f1.id < f2.id;
	}
}

struct Node {
	vector<int> children;
	int id;
	int father = -1;
	int mother = -1;
	int mestate = 0;
	int area = 0;
};

void BFS(vector<Node>& v, vector<bool>& vis, int curP, int& id, int& members, double& avgsets, double& area) {
	queue<int> q;
	q.push(curP);
	vis[curP] = true;
	double sets = 0;
	double total_area = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		sets += v[x].mestate;
		total_area += v[x].area;
		id = min(x, id);
		members++;
		if (v[x].father != -1 and !vis[v[x].father]) {
			vis[v[x].father] = true;
			q.push(v[x].father);
		}
		if (v[x].mother != -1 and !vis[v[x].mother]) {
			vis[v[x].mother] = true;
			q.push(v[x].mother);
		}
		for (int i = 0; i < v[x].children.size(); i++) {
			if (!vis[v[x].children[i]]) {
				q.push(v[x].children[i]);
				vis[v[x].children[i]] = true;
			}
		}
	}
	area = total_area / members;
	avgsets = sets / members;

}

int main () {
	int N;
	scanf("%d", &N);
	vector<Node> v(maxsize);
	vector<bool> vis(maxsize, true);
	vector<int> testorder;
	for (int i = 0; i < N; i++) {
		int ti, tf, tm, td;
		scanf("%d %d %d %d", &ti, &tf, &tm, &td);
		testorder.push_back(ti);
		v[ti].id = ti;
		v[ti].father = tf;
		v[ti].mother = tm;
		vis[ti] = false;
		if (tf != -1) {
			v[tf].children.push_back(ti);
			vis[tf] = false;
		}
		if (tm != -1) {
			v[tm].children.push_back(ti);
			vis[tm] = false;
		}
		for (int j = 0; j < td; j++) {
			int tc;
			scanf("%d", &tc);
			v[ti].children.push_back(tc);
			if (v[tc].father == -1)
				v[tc].father = ti;
			else if (v[tc].mother == -1)
				v[tc].mother = ti;
			vis[tc] = false;
		}
		int te, ta;
		scanf("%d %d", &te, &ta);
		v[ti].mestate = te;
		v[ti].area = ta;
	}

	vector<Family> res;
	for (int i = 0; i < testorder.size(); i++) {
		auto x = testorder[i];
		int id = maxsize;
		int members = 0;
		double avgsets = 0;
		double avgarea = 0;
		Family f;
		if (!vis[x]) {
			BFS(v, vis, x, id, members, avgsets, avgarea);
			f.id = id;
			f.members = members;
			f.avgsets = avgsets;
			f.avgarea = avgarea;
			res.push_back(f);
		}
	}
	int cnt = res.size();
	printf("%d\n", cnt);
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < cnt; i++) {
		auto& x = res[i];
		printf("%04d %d %.3lf %.3lf\n", x.id, x.members, x.avgsets, x.avgarea);
	}
	return 0;

}




