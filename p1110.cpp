#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int val;
	int left = -1;
	int right = -1;
};


bool is_CBT(vector<Node>& tree, int root, int& lastnode) {
	queue<int> q;
	q.push(root);
	int len = 1;
	bool prevlevel = false;
	while (len) {
		//printf("%d\n", len);
		bool gap = false;
		for (int i = 0; i < len; i++) {
			auto x = tree[q.front()];
			lastnode = x.val;
			q.pop();
			if (x.left != -1) {
				if (gap or prevlevel)
					return false;
				q.push(x.left);
			}
			else {
				gap = true;
			}
			if (x.right != -1) {
				if (gap or prevlevel)
					return false;
				q.push(x.right);
			}
			else {
				gap = true;
			}
		}
		len = q.size();
		prevlevel = gap;
	}
	return true;
}


int main () {
	int N;
	cin >> N;
	vector<Node> v(N);
	vector<bool> root(N, true);
	for (int i = 0; i < N; i++) {
		string l, r;
		cin >> l >> r;
		v[i].val = i;
		if (l[0] != '-') {
			v[i].left = stoi(l);
			root[stoi(l)] = false;
		}
		if (r[0] != '-') {
			v[i].right = stoi(r);
			root[stoi(r)] = false;
		}
	}

	int rootP = -1;
	for (int i = 0; i < N; i++)
		if (root[i]) {
			rootP = i;
			break;
		}

	int lastnode = -1;
	if (is_CBT(v, rootP, lastnode)) {
		printf("YES %d", lastnode);
	} else {
		printf("NO %d", rootP);
	}
	return 0;
}



