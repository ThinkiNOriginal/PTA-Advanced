#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
};

vector<int> BFS(Node* tree) {
	queue<Node*> q;
	q.push(tree);
	vector<int> res;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		res.push_back(x -> val);
		if (x -> right) {
			q.push(x -> right);
		}
		if (x -> left) {
			q.push(x -> left);
		}
	}
	return res;
}

vector<int> inorder(Node* tree) {
	static vector<int> res;
	if (tree) {
		inorder(tree -> right);
		res.push_back(tree -> val);
		inorder(tree -> left);
	}
	return res;
}
			
		
int main() {
	int N;
	scanf("%d", &N);
	vector<Node> tree(N);
	vector<bool> root(N, true);
	for (int i = 0; i < N; i++) {
		string l, r;
		cin >> l >> r;
		tree[i].val = i;
		if (l[0] != '-') {
			tree[i].left = &tree[stoi(l)];
			root[stoi(l)] = false;
		}
		if (r[0] != '-') {
			tree[i].right = &tree[stoi(r)];
			root[stoi(r)] = false;
		}
	}
	int rootp = -1;
	for (int i = 0; i < N; i++) {
		if (root[i]) {
			rootp = i;
			break;
		}
	}
	
	auto level = BFS(&tree[rootp]);
	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", level[i]);
	}
	printf("\n");
	auto invert = inorder(&tree[rootp]);
	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", invert[i]);
	}
	printf("\n");
	return 0;
}


