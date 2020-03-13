#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

const int maxsize = 100010;

int LSOne(int i) {
	return (i & (-i));
}

int rsq(int b, vector<int>& FT) {
	int sum = 0;
	while (b > 0) {
		sum += FT[b];
		b -= LSOne(b);
	}
	return sum;
}

void adjust(int k, int v, vector<int>& FT) {
	while (k < maxsize) {
		FT[k] += v;
		k += LSOne(k);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> FenwickTree(maxsize, 0);
	stack<int> sr;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		char command[11];
		scanf("%s", command);
		auto c = command[1];
		if (c == 'o') {
			if (cnt == 0) {
				printf("Invalid\n");
			} else {
				auto x = sr.top();
				printf("%d\n", x);
				sr.pop();
				cnt--;
				adjust(x, -1, FenwickTree);
			}
		} else if (c == 'e') {
			if (cnt == 0) {
				printf("Invalid\n");
			} else {
				auto x = cnt % 2 == 0 ? cnt / 2 : (cnt + 1) / 2;
				//x--;
				int l = 0;
				int h = maxsize;
				while (l < h) {
					int m = (l + h) / 2;
					int fre = rsq(m, FenwickTree);
					if (fre >= x) {
						h = m;
					} else if (fre < x) {
						l = m + 1;
					}
					//printf("%d %d %d\n", x, l, h);
				}
				printf("%d\n", l);
			}
		} else if (c == 'u') {
			int x;
			scanf("%d", &x);
			sr.push(x);
			adjust(x, 1, FenwickTree);
			cnt++;
		}
	}
	return 0;
}

