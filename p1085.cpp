#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>


int main() {
	long N, p;
	scanf("%ld %ld", &N, &p);
	std::vector<long> r(N);
	for (int i = 0; i < N; i++)
		scanf("%ld", &r[i]);

	std::sort(r.begin(), r.end());
	long res = -1;	
	for (int i = 0; i < N; i++) {
		auto x = std::upper_bound(r.begin() + i + 1, r.end(), r[i] * p);
		res = std::max(res, x - r.begin() - i);
	}

	printf("%ld", res);
	return 0;
}

