#include <string>
#include <vector>
#include <cstdio>
#include <iostream>


int main() {
	int N;
	scanf("%d", &N);
	int M, L;
	scanf("%d", &M);
	std::vector<int> Eva(M + 1);
	for (int i = 1; i <= M; i++)
		scanf("%d", &Eva[i]);
	scanf("%d", &L);
	std::vector<int> Stripe(L + 1);
	for (int i = 1; i <= L; i++)
		scanf("%d", &Stripe[i]);

	std::vector<std::vector<int>> r(M + 1, std::vector<int>(L + 1, 0));
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= L; j++) {
			auto x = std::max(r[i - 1][j], r[i - 1][j - 1]);
			x = std::max(x, r[i][j - 1]);
			if (Eva[i] == Stripe[j]) {
				r[i][j] = x + 1;
			} else {
				r[i][j] = x;
			}
		}
	}

	printf("%d", r[M][L]);
	return 0;
}


