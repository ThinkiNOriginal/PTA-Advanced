#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int id;
	int val;
	int left = -1;
	int right = -1;
};

vector<int> inorder(vector<Node>& tree, int root) {
	static vector<int> res;
	if (root != -1) {
		inorder(tree, tree[root].left);
		res.push_back(tree[root].id);
		inorder(tree, tree[root].right);
	}
	return res;
}


vector<int> BFS(vector<Node>& tree, int root) {
	queue<int> q;
	q.push(root);
	vector<int> res;
	res.push_back(tree[root].val);
	while (!q.empty()) {
		auto x = tree[q.front()];
		q.pop();
		if (x.left != -1) {
			res.push_back(tree[x.left].val);
			q.push(x.left);
		}
		if (x.right != -1) {
			res.push_back(tree[x.right].val);
			q.push(x.right);
		}
	}
	return res;
}



int main () {
	int N;
	cin >> N;
	vector<Node> tree(N);
	for (int i = 0; i < N; i++) {
		int tmpl, tmpr;
		cin >> tmpl >> tmpr;
		if (tmpl !=  -1)
			tree[i].left = tmpl;
		if (tmpr != -1)
			tree[i].right = tmpr;
		tree[i].id = i;
	}


	auto res = inorder(tree, 0);
	vector<int> r(N);
	for (int i = 0; i < N; i++) {
		cin >> r[i];
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < N; i++) {
		tree[res[i]].val = r[i];
	}

	auto lres = BFS(tree, 0);
	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", lres[i]);
	}
	return 0;
}


