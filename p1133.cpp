#include <vector>
#include <cstdio>

using namespace std;

const int maxsize = 100000;

struct Node {
	int add;
	int val;
	int next;
};

int main() {
	int add, N, K;
	scanf("%d %d %d", &add, &N, &K);
	vector<Node> link(maxsize);
	vector<Node> neg;
	vector<Node> gK;
	vector<Node> lK;

	for (int i = 0; i < N; i++) {
		int t_add, t_val, t_next;
		scanf("%d %d %d", &t_add, &t_val, &t_next);
		link[t_add].add = t_add;
		link[t_add].val = t_val;
		link[t_add].next = t_next;
	}

	auto p = add;
	while (p != -1) {
		auto& x = link[p];
		if (x.val < 0) {
			neg.push_back(x);
		} else if (x.val > K) {
			gK.push_back(x);
		} else {
			lK.push_back(x);
		}
		p = link[p].next;
	}
	vector<Node> ans;
	for (auto x : neg)
		ans.push_back(x);
	for (auto x : lK)
		ans.push_back(x);
	for (auto x : gK)
		ans.push_back(x);
	
	int len = ans.size();
	for (int i = 0; i < len - 1; i++) {
		printf("%05d %d %05d\n", ans[i].add, ans[i].val, ans[i + 1].add);
	}
	printf("%05d %d -1\n", ans[len - 1].add, ans[len - 1].val);
	return 0;
}

	
