#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxsize = 2020;

struct Node {
	int val;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* build_BST(Node* tree, int x) {
	if (tree) {
		if (x <= tree -> val) {
			tree -> left = build_BST(tree -> left, x);
		} else {
			tree -> right = build_BST(tree -> right, x);
		}
	} else {
		tree = new Node;
		tree -> val = x;
	}
	return tree;
}

vector<int> BFS(Node* tree) {
	queue<Node*> q;
	q.push(tree);
	int len = q.size();
	vector<int> res;
	while (len) {
		res.push_back(len);
		for (int i = 0; i < len; i++) {
			auto x = q.front();
			q.pop();
			if (x -> left) {
				q.push(x -> left);
			}
			if (x -> right)
				q.push(x -> right);
		}
		len = q.size();
	}
	return res;
}
				





int main () {
	int N;
	scanf("%d", &N);
	Node* tree = nullptr;

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		tree = build_BST(tree, tmp);
	}

	auto res = BFS(tree);
	int n1 = 0;
	int n2 = 0;
	if (res.size() == 1)
		n1 = 1;
	else {
		n1 = res[res.size() - 1];
		n2 = res[res.size() - 2];
	}
	printf("%d + %d = %d", n1, n2, n1 + n2);
	return 0;
}
	


