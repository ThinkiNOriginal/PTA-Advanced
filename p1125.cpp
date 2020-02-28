#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	priority_queue<double, vector<double>, greater<double>> pq;
	for (int i = 0; i < N; i++) {
		double temp;
		scanf("%lf", &temp);
		pq.push(temp);
	}

	while (pq.size() > 1) {
		auto x = pq.top();
		pq.pop();
		auto y = pq.top();
		pq.pop();
		pq.push((x + y) / 2);
	}

	int res = floor(pq.top());
	printf("%d", res);
	return 0;
}
