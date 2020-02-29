#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int M;
		scanf("%d", &M);
		vector<int> temp(M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp[j]);
		}
		bool failure = false;
		for (int m = 0; m < M; m++) {
			for (int n = m + 1; n < M; n++) {
				if (temp[m] == temp[n]) {
					failure = true;
					break;
				}
				if (abs(temp[n] - temp[m]) == abs(m - n)) {
					failure = true;
					break;
				}
			}
			if (failure)
				break;
		}
		if (failure) {
				printf("NO\n");
			} else {
				printf("YES\n");
			}
	}
	return 0;
}
