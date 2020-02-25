#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int main() {
//	freopen("case2", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int s1 = 0;
	int len = N / 2 - 1;
	for (int i = 0; i <= len; i++)
		s1 += v[i];

	int s2 = 0;
	for (int i = len + 1; i < N; i++)
		s2 += v[i];

	printf("%d %d\n", N % 2 == 0 ? 0 : 1, s2 - s1);
	return 0;
}
