#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int maxsize = 10000;

bool is_prime(int N) {
	if (N <= 1)
		return false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (N % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> rank(maxsize, -1);
	vector<bool> checked(maxsize, false);
	for (int i = 1; i <= N; i++) {
		int id;
		scanf("%d", &id);
		rank[id] = i;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int test;
		scanf("%d", &test);
		printf("%04d: ", test);
		if (rank[test] == -1) {
			printf("Are you kidding?\n");
			continue;
		}
		if (checked[test]) {
			printf("Checked\n");
		} else {
			checked[test] = true;
			if (rank[test] == 1) {
				printf("Mystery Award\n");
			} else if (is_prime(rank[test])) {
				printf("Minion\n");
			} else {
				printf("Chocolate\n");
			}
		}
	}
	return 0;
}


