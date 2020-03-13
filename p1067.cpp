#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> vecPos(N);
	int unsorted = 0;
	for (int i = 0; i < N; i++) {
		int val;
		scanf("%d", &val);
		vecPos[val] = i;
		if (val != i and val != 0) {
			unsorted++;
		}
	}

	int T = 1;
	int res = 0;
	while (unsorted > 0) {
		if (vecPos[0] == 0) {
			while (vecPos[T] == T)
				T++;
			swap(vecPos[0], vecPos[vecPos[T]]);
			res++;
		} else {
			swap(vecPos[0], vecPos[vecPos[0]]);
			res++;
			unsorted--;
		}
		
	}

	printf("%d\n", res);
	return 0;
}


