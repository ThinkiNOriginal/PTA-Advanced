#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int id;
	int weight = 0;
	int PW = 0;
	int father = -1;
	vector<int> children;
};

bool cmp(vector<int>& v1, vector<int>& v2) {
	int len = min(v1.size(), v2.size());
	for (int i = 0; i < len ;i++) {
		if (v1[i] == v2[i])
			continue;
		if (v1[i] > v2[i])
			return true;
		else 
			return false;
	}
	return false;
}

void preOrder(vector<Node>& tree, int cur, const int len) {
	if (cur < len) {
		if (tree[cur].father != -1)
			tree[cur].PW = tree[tree[cur].father].PW + tree[cur].weight;
		else
			tree[cur].PW = tree[cur].weight;
		for (auto x : tree[cur].children)
			preOrder(tree, x, len);
	}
}

int main() {
	int N, M, S;
	scanf("%d %d %d", &N, &M, &S);
	vector<int> weight(N);
	vector<Node> tree(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
		tree[i].weight = weight[i];
	}
	
	for (int i = 0; i < M; i++) {
		int tempid, cnt;
		scanf("%d %d", &tempid, &cnt);
		for (int j = 0; j < cnt; j++) {
			int tc;
			scanf("%d", &tc);
			tree[tempid].children.push_back(tc);
			tree[tc].father = tempid;
		}
	}
	preOrder(tree, 0, N);
	vector<vector<int>> res;
	for (int i = 0; i < N; i++) {
		if (tree[i].PW == S and tree[i].children.empty()) {
			auto p = i;
			vector<int> temp;
			while (p != -1) {
				temp.push_back(tree[p].weight);
				p = tree[p].father;
			}
			reverse(temp.begin(), temp.end());
			res.push_back(temp);
		}
	}
	sort(res.begin(), res.end(), cmp);
	for (auto x : res) {
		int len = x.size();
		for (int i = 0; i < len; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", x[i]);
		}
		printf("\n");
	}



	return 0;
}



