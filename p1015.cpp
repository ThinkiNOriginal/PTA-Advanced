#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

bool isPrime(int x) {
	int end = std::sqrt(x);
	if (x < 2)
		return false;
	else {
		for (int i = 2; i <= end; i++) {
			if (x % i == 0)
				return false;
		}
	}

	return true;
}


int reverse_num (int x, int radix) {
	std::vector<int> v;
	while (x) {
		v.push_back(x % radix);
		x /= radix;
	}

//	std::reverse(v.begin(), v.end());
	int len = v.size();
	int res = 0;
	for (int i = 0; i < len; i++)
		res += pow(radix, len - i - 1) * v[i];

	return res;
}


int main() {
	int N, radix;
	while (scanf("%d", &N)) {
		if (N < 0)
			break;
		scanf("%d", &radix);

		if (isPrime(N)) {
			auto re = reverse_num(N, radix);
			if (isPrime(re))
				printf("Yes\n");
			else
				printf("No\n");
		} else
			printf("No\n");
	}
	return 0;

}














