#include <iostream>
#include <vector>
#include <cstdio>

const int maxsize = 1001;
int main() {
	int k;
	scanf("%d", &k);

	std::vector<double> p1(maxsize, 0);
	std::vector<double> p2(maxsize, 0);
	//vector<double> res(maxsize, 0);

	while (k) {
		int n;
		double an;
		scanf("%d %lf", &n, &an);
		p1[n] = an;
		k--;
	}

	scanf("%d", &k);
	while (k) {
		int n;
		double an;
		scanf("%d %lf", &n, &an);
		p2[n] = an;
		k--;
	}

	int cnt = 0;
	for (int i = 0; i < maxsize; i++) {
		//res[i] = p1[i] + p2[i];
		p2[i] += p1[i];
		if (p2[i] != 0)
			cnt++;
	}

	printf("%d", cnt);
	for (int i = maxsize - 1; i >= 0; i--) {
		if (p2[i] != 0)
			printf(" %d %.1lf", i, p2[i]);
	}

	return 0;


}
