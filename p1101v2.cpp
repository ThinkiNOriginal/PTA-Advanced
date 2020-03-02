#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> ori(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &ori[i]);

	vector<int> lr = ori;
	for (int i = 1; i < N; i++) {
		lr[i] = max(lr[i], lr[i - 1]);
	}

	vector<int> rl = ori;
	for (int i = N - 2; i >= 0; i--) {
		rl[i] = min(rl[i], rl[i + 1]);
	}

	vector<int> res;
	for (int i = 0; i < N; i++) {
		if (lr[i] == rl[i])
			res.push_back(lr[i]);
	}
	int len = res.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}


