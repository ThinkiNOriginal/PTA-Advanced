#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool cmp(string& s1, string& s2) {
	return s1 < s2;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<vector<string>> v(K + 1);
	for (int i = 0; i < N; i++) {
		string tmp;
		int cnt;
		cin >> tmp >> cnt;
		for (int j = 0; j < cnt; j++) {
			int tmpc;
			scanf("%d", &tmpc);
			v[tmpc].push_back(tmp);
		}
	}

	for (int i = 1; i <= K; i++) {
		auto x = v[i];
		sort(x.begin(), x.end(), cmp);
		printf("%d %lu\n", i, x.size());
		for (auto y : x)
			printf("%s\n", y.c_str());
	}
	return 0;
}


