#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


int main() {
	
	int M, N;
	scanf("%d %d", &M, &N);
	int cnt  = 0;
	int dominant = -1;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			if (cnt == 0 or tmp == dominant) {
				dominant = tmp;
				cnt++;
			} else if (tmp != dominant)
				cnt--;

			
		}

	}

	printf("%d", dominant);
	return 0;
}
