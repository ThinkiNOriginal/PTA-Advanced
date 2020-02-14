#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

struct Item {
	long val;
	int exp;
};

int main() {
	
	long N;
	scanf("%ld", &N);
	
	if (N == 1) {
		printf("1=1");
		return 0;
	}

	std::vector<Item> r;

	long iter = N;
	int cnt = 0;
	while (iter % 2 == 0) {
		cnt++;
		iter /= 2;
	}
	r.push_back({2, cnt});
	
	for (int i = 3; i <= N; i += 2) {
		cnt = 0;
		while (iter % i == 0) {
			cnt++;
			iter /= i;
		}

		if (cnt)
			r.push_back({i, cnt});

		if (iter == 1)
			break;
	}
		
	printf("%ld=", N);
	cnt = 0;
	for (auto x : r) {
		if (cnt) {
			printf("*");
		}
		if (x.exp == 1) {
			cnt++;
			printf("%ld", x.val);
		}
		else if (x.exp > 1) {
			cnt++;
			printf("%ld^%d", x.val, x.exp);
		}
	}

	return 0;




}
