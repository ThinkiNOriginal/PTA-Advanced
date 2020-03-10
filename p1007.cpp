#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int K;
	scanf("%d", &K);
	vector<int> vecNum(K);
	for (int i = 0; i < K; i++)
		scanf("%d", &vecNum[i]);

	int maxm = -1;
	int target = -1;
	auto vecSum = vecNum;
	for (int i = 1; i < K; i++) {
		if (i > 0)
			vecSum[i] = max(vecSum[i] + vecSum[i - 1], vecSum[i]);
		if (vecSum[i] > maxm) {
			maxm = vecSum[i];
			target = i;
		}
	}
	
	if (maxm == -1) {
		printf("0 %d %d", vecNum[0], vecNum[K - 1]);
		return 0;
	}

	int resL = -1;
	int resR = target;
	int resMax = maxm;
	while (target >= 0) {
		maxm = maxm - vecNum[target];
		if (maxm == 0)
			resL = target;
		target--;
	}
	printf("%d %d %d", resMax, vecNum[resL], vecNum[resR]);
	return 0;
}



