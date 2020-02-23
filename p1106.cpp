#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>


using namespace std;

void BFS(vector<vector<int>>& tree, double price, double rate, double& lp, int& members) {
	queue<int> q;
	q.push(0);
	int level = 0;
	int len = q.size();
	while (len) {
		for (int i = 0; i < len; i++) {
			auto x = tree[q.front()];
			q.pop();
			if (x.empty()) {
				members++;
				lp = pow(1 + 0.01 * rate, level) * price;
			} else {
				for (auto tmp : x)
					q.push(tmp);
			}
		}
		len = q.size();
		if (members)
			break;
		level++;
	}
		
}
	


int main() {
	int N;
	double P, R;
	scanf("%d %lf %lf", &N, &P, &R);
	vector<vector<int>> tree(N);
	for (int i = 0; i < N; i++) {
		int ki;
		scanf("%d", &ki);
		for (int j = 0; j < ki; j++) {
			int tmp;
			scanf("%d", &tmp);
			tree[i].push_back(tmp);
		}
	}

	double lp = 0;
	int members = 0;
	BFS(tree, P, R, lp, members);
	printf("%.4lf %d", lp, members);
	return 0;
}



