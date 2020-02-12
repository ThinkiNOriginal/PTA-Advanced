#include <vector>
#include <iostream>

const int maxsize = 1001;
int main() {
	int K;
	std::cin >> K;
	std::vector<double> p1(maxsize, 0);
	while (K--) {
		int exp = 0;
		double coe = 0;
		std::cin >> exp >> coe;
		p1[exp] = coe;
	}
	std::cin >> K;
	std::vector<double> p2(maxsize, 0);
	while (K--) {
		int exp = 0;
		double coe = 0;
		std::cin >> exp >> coe;
		p2[exp] = coe;
	}
	int resL = 2 * maxsize;
	std::vector<double> res(resL, 0);

	for (int i = 0; i < maxsize; i++) {
		for (int j = 0; j < maxsize; j++) {
			res[i + j] += p1[i] * p2[j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < resL; i++)
		if (res[i] != 0)
			cnt++;

	printf("%d", cnt);

	for (int i = resL; i >= 0; i--)
		if (res[i] != 0) {
			printf(" %d %.1f", i, res[i]);
		}
	return 0;
		

}


