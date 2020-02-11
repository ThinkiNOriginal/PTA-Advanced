#include <cstdio>
#include <iostream>
#include <vector>


int main() {

	int k;
	std::cin >> k;
	std::vector<int> v(k);
	int res = -1;
	int index = -1;

	for (int i = 0; i < k; i++) {
		scanf("%d", &v[i]);
	}

	std::vector<int> r = v;
	for (int i = 1; i < k; i++) {
		auto x = r[i];
		auto y = r[i - 1];
		r[i] = x > x + y ? x : x + y;
		x = r[i];
		if (res < x) {
			res = x;
			index = i;
		}
	}

	int remain = res;
	int h = index;
	int l = -1;
	while (index) {
		res -= v[index];
		if (res == 0) {
			l = index;
			break;
		}
		index--;
	}

	if (res < 0) {
		remain = 0;
		v[l] = v[0];
		v[h] = v[k - 1];
	}
	printf("%d %d %d", remain, v[l], v[h]);

	return 0;

}
