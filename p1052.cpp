#include <cstdio>
#include <vector>
#include <algorithm>

const int maxsize = 100010;

struct Node {
	int add;
	int val;
	int next;
};

bool cmp (Node& n1, Node& n2) {
	return n1.val < n2.val;
}

int main() {
	
	int N, add;
	scanf("%d %d", &N, &add);

	std::vector<Node> r(maxsize);

	for (int i = 0; i < N; i++) {
		int tmpadd;
		scanf("%d", &tmpadd);
		r[tmpadd].add = tmpadd;
		scanf("%d %d", &r[tmpadd].val, &r[tmpadd].next);
	}

	std::vector<Node> res;
	while (add != -1) {
		res.push_back(r[add]);
		add = r[add].next;
	}

	std::sort(res.begin(), res.end(), cmp);
	int len = res.size();
    if (len == 0) {
        printf("0 -1");
        return 0;
    }
	printf("%d %05d\n", len, res[0].add);
	for (int i = 0; i < len - 1; i++) {
		printf("%05d %d %05d\n", res[i].add, res[i].val, res[i + 1].add);
	}
	printf("%05d %d -1\n", res[len - 1].add, res[len - 1].val);
	



	return 0;
}

