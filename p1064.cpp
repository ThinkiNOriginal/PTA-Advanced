#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> inorder(int len, int cur) {
	static vector<int> res;
	if (cur < len) {
		inorder(len, cur * 2 + 1);
		res.push_back(cur);
		inorder(len, cur * 2 + 2);
	}
	return res;
}

int main () {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	auto pos = inorder(N, 0);
	sort(v.begin(), v.end());
	vector<int> CBST(N);
	for (int i = 0; i < N; i++) {
		CBST[pos[i]] = v[i];
	}

	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", CBST[i]);
	}
	return 0;
}

