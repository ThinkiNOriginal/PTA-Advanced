#include <vector>
#include <iostream>
#include <queue>


struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* BuildTree(std::vector<int>& in, std::vector<int>& pos, int inL, int inR, int posL, int posR) {

	if (inL > inR or posL > posR)
		return nullptr;

	int gap = -1;
	int rv  = pos[posR];
	for (int i = inL; i <= inR; i++)
		if (in[i] == rv) {
			gap = i;
			break;
		}

	Node* root = new Node;
	root -> val = rv;
	root -> left = BuildTree(in, pos, inL, gap - 1, posL, posL - inL + gap - 1);
	root -> right = BuildTree(in, pos, gap + 1, inR, posL - inL + gap, posR - 1);
	return root;


}


std::vector<int> LevelTraverse(Node* tree) {
	std::queue<Node*> q;
	q.push(tree);
	std::vector<int> res;
	int len = q.size();
	while (len) {
		for (int i = 0; i < len; i++) {
			auto x = q.front();
			res.push_back(x -> val);
			q.pop();
			auto xl = x -> left;
			auto xr = x -> right;
			if (xl)
				q.push(xl);
			if (xr)
				q.push(xr);
		}
		len = q.size();
	}
	
	return res;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> in(N);
	std::vector<int> pos(N);
	for (int i = 0; i < N; i++)
		std::cin >> pos[i];
	for (int i = 0; i < N; i++)
		std::cin >> in[i];

	Node* tree = BuildTree(in, pos, 0, N - 1, 0, N - 1);
	std::vector<int> res = LevelTraverse(tree);
	
	int len = res.size();
	for (int i = 0; i < len; i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << res[i];
	}

	return 0;
}
