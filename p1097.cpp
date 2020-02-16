#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>


const int maxsize = 10001;

struct Node {
	int add;
	int val;
	int next;
};

int main() {
	int add, N;
	scanf("%d %d", &add, &N);
	std::vector<Node> link(100010);
	std::vector<bool> exi(maxsize, false);

	for (int i = 0; i < N; i++) {
		int tmpadd = 0;
		scanf("%d", &tmpadd);
		link[tmpadd].add = tmpadd;
		scanf("%d %d", &link[tmpadd].val, &link[tmpadd].next);
	}

	std::vector<Node> resl;
	std::vector<Node> reml;
	while (add != -1) {
		auto& x = link[add];
		if (!exi[std::abs(x.val)]) {
			resl.push_back(x);
			exi[std::abs(x.val)] = true;
		} else {
			reml.push_back(x);
		}
		add = link[add].next;
	}

	int len = resl.size();
	for (int i = 0; i < len - 1; i++) {
		printf("%05d %d %05d\n", resl[i].add, resl[i].val, resl[i + 1].add);
	}
	printf("%05d %d -1\n", resl[len - 1].add, resl[len - 1].val);

	len = reml.size();
	for (int i = 0; i < len - 1; i++) {
		printf("%05d %d %05d\n", reml[i].add, reml[i].val, reml[i + 1].add);
	}
	if (len > 0)
		printf("%05d %d -1\n", reml[len - 1].add, reml[len - 1].val);

	
	return 0;
}
		

