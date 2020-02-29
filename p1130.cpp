#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

struct Node {
	string val;
	Node* left;
	Node* right;
};

string infix(Node* tree) {
	static string res;
	if (tree) {
		if (tree -> left or tree -> right)
			res += '(';
		infix(tree -> left);
		res += tree -> val;
		infix(tree -> right);
		if (tree -> right or tree -> left)
			res += ')';
	}
	return res;
}	



int main() {
	int N;
	scanf("%d", &N);
	vector<Node> tree(N + 1);
	vector<bool> root(N + 1, true);

	for (int i = 1; i <= N; i++) {
		string val;
		int l, r;
		cin >> val >> l >> r;
		tree[i].val = val;
		if (l != -1) {
			tree[i].left = &tree[l];
			root[l] = false;
		}
		if (r != -1) {
			tree[i].right = &tree[r];
			root[r]= false;
		}
	}
	int rootP = -1;
	for (int i = 1; i <= N; i++) {
		if (root[i]) {
			rootP = i;
			break;
			}
	}


	auto res = infix(&tree[rootP]);
	int len = res.size();
	if (res[0] == '(') {
		res.erase(len - 1, 1);
		res.erase(0, 1);
	}
	cout << res << endl;
	return 0;
}



