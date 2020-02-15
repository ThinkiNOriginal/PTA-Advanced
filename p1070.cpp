#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

struct Mooncake {
	double amounts;
	double price;
	double unitprice;
};

bool cmp (Mooncake& m1, Mooncake& m2) {
	return m1.unitprice > m2.unitprice;
}

int main() {
	int N, D;
	scanf("%d %d", &N, &D);

	std::vector<Mooncake> r(N);
	for (int i = 0; i < N; i++)
		scanf("%lf", &r[i].amounts);
	
	for (int i = 0; i < N; i++) {
		scanf("%lf", &r[i].price);
		r[i].unitprice = r[i].price / r[i].amounts;
	}

	std::sort(r.begin(), r.end(), cmp);
		
	int i = 0;
	double profits = 0;
	while (i < N) {
		if (D > r[i].amounts) {
			profits += r[i].price;
			D -= r[i].amounts;
			i++;
		} else {
			profits += r[i].unitprice * D;
			break;
		}
	}

	printf("%.2lf", profits);
	return 0;
}



