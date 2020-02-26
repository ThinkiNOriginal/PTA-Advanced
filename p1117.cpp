#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;


int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	
	int res = 0;
	for (int i = 0; i <= N; i++) {
		auto s = upper_bound(v.begin(), v.end(), i);
		int cmp = v.end() - s;
		if (cmp >= i) {
			res = max(res, i);
		}
	}
	printf("%d", res);
	return 0;
}
