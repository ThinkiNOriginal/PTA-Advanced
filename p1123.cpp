#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int val;
	int height = 1;
	int diff   = 0;
	Node *left = nullptr;
	Node *right = nullptr;
};



int depth(Node* tree) {
	if (tree) {
		tree -> height = max(depth(tree -> left), depth(tree -> right)) + 1;
		return tree -> height;
	} else {
		return 0;
	}
}


Node* LL(Node* tree) {
	auto p = tree -> left;
	tree -> left = p -> right;
	p -> right = tree;
	return p;
}

Node* RR(Node* tree) {
	auto p = tree -> right;
	tree -> right = p -> left;
	p -> left = tree;
	return p;
}

Node* LR(Node* tree) {
	auto p = tree -> left -> right;
	tree -> left -> right = p -> left;
	p -> left = tree -> left;
	tree -> left = p;
	return LL(tree);
}

Node* RL(Node* tree) {
//	auto p = tree -> right -> left;
//	tree -> right -> left = p -> right;
//	p -> right = tree -> right;
	auto p = tree -> right -> left;
	tree -> right -> left = p -> right;
	p -> right = tree -> right;
	tree -> right  = p;
	return RR(tree);
	
}



void Balance(Node*& tree) {
	if (tree) {
		auto left_d = depth(tree -> left);
		auto right_d = depth(tree -> right);
		if (left_d - right_d == 2) {
			if (depth(tree -> left -> left) > depth(tree -> left -> right))
				tree = LL(tree);
			else
				tree = LR(tree);
		
		} else if (right_d - left_d == 2) {
			if (depth(tree -> right -> right) > depth(tree -> right -> left))
				tree = RR(tree);
			else
				tree = RL(tree);
		}
	}
}
		


Node* buildAVL(Node* tree, int cur) {
	if (tree) {
		if (cur < tree -> val) {
			tree -> left = buildAVL(tree -> left, cur);
			Balance(tree -> left);
			Balance(tree);
		} else {
			tree -> right = buildAVL(tree -> right, cur);
			Balance(tree -> right);
			Balance(tree);
		}

	} else {
		tree = new Node;
		tree -> val = cur;
	}
	return tree;
}




vector<int> levelorder(Node *tree, bool& isCBT) {
	queue<Node*> q;
	vector<int> res;
	q.push(tree);
	int len = q.size();
	bool prev_level = false;
	while (!q.empty()) {
		bool gap = false;
		for (int i = 0; i < len; i++) {
			auto x = q.front();
			res.push_back(x -> val);
			q.pop();
			if (x -> left) {
				if (gap or prev_level)
					isCBT = false;
				q.push(x -> left);
			}
			else
				gap = true;
			if (x -> right) {
				if (gap or prev_level)
					isCBT = false;
				q.push(x -> right);
			}
			else
				gap = true;
		}
		len = q.size();
		prev_level = gap;
	
	}
	return res;
}


int main() {
	int N;
	scanf("%d", &N);
	Node *tree = nullptr;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
//		printf("%d ", temp);
		tree = buildAVL(tree, temp);
	}

	bool isCBT = true;
	auto res = levelorder(tree, isCBT);
	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	if (isCBT) {
		printf("YES\n");
	} else
		printf("NO\n");

	return 0;
}


