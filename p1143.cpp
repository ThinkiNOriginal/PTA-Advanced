#include <vector>
#include <cstdio>
#include <unordered_set>
#include <algorithm>

using namespace std;

int LCA(vector<int>& tree, int l, int r, int treeL, int treeR) {
	if (l > r)
		swap(l, r);
	auto x = tree[treeL];
	int gap = -1;
	for (int i = treeL; i <= treeR; i++) {
		if (x < tree[i]) {
			gap = i - 1;
			break;
		}
	}
	if (l < x and r < x) {
		return LCA(tree, l, r, treeL + 1, gap);
	} else if (x < l and x < r) {
		return LCA(tree, l, r, gap + 1, treeR);
	} else {
		return x;
	}
}


int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	unordered_set<int> usV;
	vector<int> tree(N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		tree[i] = temp;
		usV.insert(temp);
	}

	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		bool absence_l = false;
		bool absence_r = false;
		if (!usV.count(l)) 
			absence_l = true;
		if (!usV.count(r))
			absence_r = true;
		if (absence_l and absence_r) {
			printf("ERROR: %d and %d are not found.\n", l, r);
		} else if (absence_l) {
			printf("ERROR: %d is not found.\n", l);
		} else if (absence_r) {
			printf("ERROR: %d is not found.\n", r);
		}
		if (absence_l or absence_r)
			continue;

		auto res = LCA(tree, l , r, 0, N - 1);
		if (res == l) {
			printf("%d is an ancestor of %d.\n", l, r);
		} else if (res == r) {
			printf("%d is an ancestor of %d.\n", r, l);
		} else {
			printf("LCA of %d and %d is %d.\n", l, r, res);
		}
	}
	return 0;
}
