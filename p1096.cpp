#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int maxlen = 0;
	int target = -1;
	int len = sqrt(N) + 0.5;
	for (int i = 2; i < len; i++) {
		int sub = i;
		int j = 1;
		int cnt = 0;
		while (N % sub == 0) {
			sub = sub * (i + j);
			j++;
			cnt++;
		}
		if (cnt > maxlen) {
			maxlen = cnt;
			target = i;
		}
	}
	
	if (maxlen == 0) {
		printf("1\n%d\n", N);
	} else {
		printf("%d\n", maxlen);
		for (int i = 0; i < maxlen; i++) {
			if (i != 0)
				printf("*");
			printf("%d", i + target);
		}
	}
	return 0;
}

