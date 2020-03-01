#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* buildTree(vector<int>& pre, vector<int>& ino, int preL, int preR, int inL, int inR) {
	if (preL > preR or inL > inR)
		return nullptr;
	int temp = pre[preL];
	Node* tree = new Node;
	tree -> val = temp;
	int gap = - 1;
	for (int i = inL; i <= inR; i++) {
		if (ino[i] == temp) {
			gap = i;
			break;
		}
	}
	tree -> left = buildTree(pre, ino, preL + 1, preL + gap - inL, inL, gap - 1);
	tree -> right = buildTree(pre, ino, preL + 1 + gap - inL, preR, gap + 1, inR);
	return tree;
}

int post(Node* tree) {
	if (tree) {
		if (tree -> left)
			return post(tree -> left);
		if (tree -> right)
			return post(tree -> right);
		return tree -> val;
	}
	return -1;
}
int main() {
	int N;
	freopen("case1", "r", stdin);
	scanf("%d", &N);
	vector<int> pre(N);
	vector<int> ino(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &ino[i]);
	
	auto tree = buildTree(pre, ino, 0, N - 1, 0, N - 1);
	auto res = post(tree);
	printf("%d", res);
	return 0;
}



