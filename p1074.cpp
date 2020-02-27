#include <algorithm>
#include <vector>
#include <cstdio>
#include <stack>

const int maxsize = 100010;
struct Node {
	int add;
	int val;
	int next;
};


int main () {
	int add, N, K;
	scanf("%d %d %d", &add, &N, &K);
	std::vector<Node> v(maxsize);
	for (int i = 0; i < N; i++) {
		int add, val, next;
		scanf("%d %d %d", &add, &val, &next);
		v[add].add = add;
		v[add].val = val;
		v[add].next = next;
	}

	std::vector<Node> res;
	std::stack<Node> s;
	int p = add;
	int i = 0;

	while (p != -1) {
		res.push_back(v[p]);
		p = v[p].next;
	}

	int rlen = res.size();
	for (int i = 0; i + K <= rlen; i += K) {
		reverse(res.begin() + i, res.begin() + i + K);
	}

	int len = res.size();
	for (int i = 0; i < len - 1; i++) {
		printf("%05d %d %05d\n",res[i].add, res[i].val, res[i + 1].add);
	}
	printf("%05d %d -1\n", res[len - 1].add, res[len - 1].val);
	return 0;
}

