#include <vector>
#include <cstdio>
#include <cmath>

int next_prime(int n) {
    if (n <= 2) {
        return 2;
    }
	while (true) {
		bool is_prime = true;
		for (int i = 2; i <= std::sqrt(n); i++) {
			if (n % i ==0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			return n;
		}

		n++;
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int len = next_prime(N);
	std::vector<int> hash(len, -1);

	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		int des = tmp;
		int step = 0;
		bool found = false;
		while (step < len) {
			if (hash[des % len] != -1) {
                step++;
				des = tmp + std::pow(step, 2);
			} else {
				found = true;
				hash[des % len] = tmp;
				printf("%d", des % len);
				break;
			}
		}
		if (!found) {
			printf("-");
		}
		if (i != M - 1)
			printf(" ");
	}
	return 0;
}


