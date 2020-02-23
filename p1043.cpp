#include <vector>
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* buildBST(Node* tree, int cur) {

	if (!tree) {
		Node* n = new Node;
		n -> val = cur;
		return n;
	}

	if (cur < tree -> val) {
		tree -> left = buildBST(tree -> left, cur);
	} else
		tree -> right = buildBST(tree -> right, cur);

	return tree;
}

vector<int> preorder(Node* tree) {
	static vector<int> v;
	if (tree) {
		v.push_back(tree -> val);
		preorder(tree -> left);
		preorder(tree -> right);
	}
	return v;
}

vector<int> preorderR(Node* tree) {
	static vector<int> v;
	if (tree) {
		v.push_back(tree -> val);
		preorderR(tree -> right);
		preorderR(tree -> left);
	}
	return v;
}

vector<int> postorder(Node* tree) {
	static vector<int> v;
	if (tree) {
		postorder(tree -> left);
		postorder(tree -> right);
		v.push_back(tree -> val);
	}
	return v;
}

vector<int> postorderR(Node* tree) {
	static vector<int> v;
	if (tree) {
		postorderR(tree -> right);
		postorderR(tree -> left);
		v.push_back(tree -> val);
	}
	return v;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	Node* tree = nullptr;
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
		tree = buildBST(tree, v[i]);
	}

	auto pre = preorder(tree);
	bool found = false;
	
	vector<int> res;
	if (pre == v) {
		printf("YES\n");
		res = postorder(tree);
		found = true;
	} else {
		auto vr = preorderR(tree);
		if (v == vr) {
			printf("YES\n");
			res = postorderR(tree);
			found = true;
		}
	}

	if (found) {
		for (int i = 0; i < N; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", res[i]);
		}
	} else {
		printf("NO");
	}
	return 0;
}



