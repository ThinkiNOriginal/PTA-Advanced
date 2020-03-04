#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<bool> v(N + 1, false);
	v[0] = true;
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		if (1 <= temp and temp <= N) {
			v[temp] = true;
		}
	}
	int res = -1;
	for (int i = 1; i <= N; i++) {
		if (!v[i]) {
			res = i;
			break;
		}
	}

	if (res == -1)
		res = N + 1;

	printf("%d\n", res);
	return 0;
}
