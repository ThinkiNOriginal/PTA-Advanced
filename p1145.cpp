#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPrime (int n) {
	if (n <= 1)
		return false;
	int len = sqrt(n);
	for (int i = 2; i <= len; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int nextPrime(int n) {
	while (!isPrime(n)) {
		n++;
	}
	return n;
}
			

int main() {
	int Msize, N, M;
	scanf("%d %d %d", &Msize, &N, &M);
	int PMsize = nextPrime(Msize);
	vector<int> hash(PMsize, -1);
	
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		int step = 0;
		int curP = temp % PMsize;
		int initP = curP;
		bool found = false;
		while (step <= PMsize) {
			if (hash[curP] == -1) {
				hash[curP] = temp;
				found = true;
				break;
			}
			step++;
			curP = initP + pow(step, 2);
			curP %= PMsize;
		}
		if (!found) {
			printf("%d cannot be inserted.\n", temp);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		int step = 0;
		int curP = temp % PMsize;
		int initP = curP;
		while (step <= PMsize) {
			cnt++;
			if (hash[curP] == temp) {
				break;
			} else if (hash[curP] == -1) {
				break;
			}
			step++;
			curP = initP + pow(step, 2);
			curP %= PMsize;
		}
	}
	printf("%.1f\n", float(cnt) / M);
	return 0;
}
				


		




