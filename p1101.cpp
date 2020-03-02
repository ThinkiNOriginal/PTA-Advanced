#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int maxsize = 1 << 30;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	map<int,int> m;
	int maxma = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
		maxma = max(maxma, v[i]);
		v[i] = maxma;
		m[v[i]]++;
	}
	vector<int> res;
	for (auto x : m) {
		if (x.second == 1)
			res.push_back(x.first);
	}


	int len = res.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}


