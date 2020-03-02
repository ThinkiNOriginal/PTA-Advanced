#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

enum Color {red, black};

struct Node {
	int val;
	Color color = black;
	Node* left;
	Node* right;
};

bool cmp (int i1, int i2) {
	return abs(i1) < abs(i2);
}

Node* buildTree(Node* tree, int cur) {
	if (tree) {
		auto x = abs(tree -> val);
		if (abs(cur) < x) {
			tree -> left = buildTree(tree -> left, cur);
		} else {
			tree -> right = buildTree(tree -> right, cur);
		}
	} else {
		tree = new Node;
		tree -> val = cur;
		if (cur < 0)
			tree -> color = red;
		else
			tree -> color = black;
	}
	return tree;
}

int BlackNodesL(Node* tree, int cur) {
	if (tree) {
		if (tree -> color == black)
			cur++;
		cur = BlackNodesL(tree -> left, cur);
	}
	return cur;
}

int BlackNodesR(Node* tree, int cur) {
	if (tree) {
		if (tree -> color == black)
			cur++;
		cur = BlackNodesR(tree -> right, cur);
	}
	return cur;
}


bool isRB(Node* tree, Node* root) {
	if (tree) {
		if (root -> color == red)
			return false;
		if (tree -> color == red) {
			if (tree -> left and tree -> left -> color == red)
				return false;
			if (tree -> right and tree -> right -> color == red)
				return false;
		}
		if (BlackNodesL(tree -> left, 0) != BlackNodesR(tree -> right, 0))
			return false;
		return isRB(tree -> left, root) and isRB(tree -> right, root);
	}
	return true;
}

int main() {
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int N;
		scanf("%d", &N);
		Node* tree = nullptr;
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			tree = buildTree(tree, temp);
		}
		if (isRB(tree, tree)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

	
