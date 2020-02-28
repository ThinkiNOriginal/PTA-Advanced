#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* buildTree(vector<int>& in, vector<int>& post, int inL, int inR, int postL, int postR) {
	if (inL > inR or postL > postR)
		return nullptr;
	Node* tree = new Node;
	int temp = post[postR];
	tree -> val = temp;
	int target = -1;
	for (int i = inL; i <= inR; i++) {
		if (temp == in[i]) {
			target = i;
			break;
		}
	}
	tree -> left = buildTree(in, post, inL, target - 1, postL, postL + target - inL - 1);
	tree -> right = buildTree(in, post, target + 1, inR, postL + target - inL, postR - 1);
	return tree;
}

vector<int> BFS(Node* tree) {
	queue<Node*> q;
	q.push(tree);
	vector<vector<int>> level;
	int depth = 0;
	while (!q.empty()) {
		int len = q.size();
		vector<int> temp(len, 0);
		depth++;
		for (int i = 0; i < len; i++) {
			auto x = q.front();
			temp[i] = x -> val;
			q.pop();
			if (x -> left)
				q.push(x -> left);
			if (x -> right)
				q.push(x -> right);
		}
		if (depth % 2 != 0)
			reverse(temp.begin(), temp.end());
		level.push_back(temp);
	}
	vector<int> res;
	for (auto x : level) {
		for (auto y : x) {
			res.push_back(y);
		}
	}
	return res;
}


int main() {
	int N;
	scanf("%d", &N);
	vector<int> inorder(N);
	vector<int> post(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &inorder[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &post[i]);

	Node* tree = buildTree(inorder, post, 0, N - 1, 0, N - 1);
	auto res = BFS(tree);
	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	return 0;
}
