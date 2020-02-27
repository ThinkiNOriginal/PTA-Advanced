#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
	int N;
	scanf("%d", &N);
	vector<int> ori(N);
	vector<int> par(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &ori[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &par[i]);

	bool insertion = true;
	int step = 1;
	while (is_sorted(par.begin(), par.begin() + step))
		step++;

	for (int i = step; i < N; i++) {
		if (ori[i] != par[i]) {
			insertion = false;
			break;
		}
	}

	if (insertion) {
		printf("Insertion Sort\n");
		sort(par.begin(), par.begin() + step);
		for (int i = 0; i < N; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", par[i]);
		}
		return 0;
	}		

	printf("Merge Sort\n");
	step = 2;
	for (int s = 1;; s++) {
		bool exit = false;
		for (int i = 0; i < N; i += step) {
			int tmp = min(i + step, N);
			if (!is_sorted(par.begin() + i, par.begin() + tmp)) {
					exit = true;
					break;
			}
		}
		if (exit)
			break;
		step = pow(2, s);
	}
	
	for (int i = 0; i < N; i += step) {
		int tmp = min(i + step, N);
		sort(par.begin() + i, par.begin() + tmp);
	}

	for (int i = 0; i < N; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", par[i]);
	}
	return 0;
}


