//#include <bits/stdc++.h>
#include <iostream>

int main() {

	int res = 0;
	int q;
	std::cin >> q;
	int last = 0;
	int cur  = 0;
	int diff = 0;

	while (q) {
		std::cin >> cur;
		diff = cur - last;
		last = cur;
		if (diff > 0)
			res += 6 * diff + 5;
		else if (diff < 0)
			res += 4 *(-diff) + 5;
		else
			res += 5;
		q--;
	}

	std::cout << res;

	return 0;
}

