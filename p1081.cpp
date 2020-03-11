#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

struct Ration {
	long numerator;
	long denominator;
};

long gcd(long a, long b) {
	a = abs(a);
	b = abs(b);
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long lcm(long a, long b) {
	a = abs(a);
	b = abs(b);
	return a / gcd(a, b) * b;
}

Ration addRation(Ration& r1, Ration& r2) {
	auto nr1 = r1.numerator;
	auto dr1 = r1.denominator;
	auto nr2 = r2.numerator;
	auto dr2 = r2.denominator;
	auto dres = lcm(dr1, dr2);
	auto nres = nr1 * (dres / dr1) + nr2 * (dres / dr2);
	auto gcdres = gcd(nres, dres);
	Ration res;
	res.numerator = nres / gcdres;
	res.denominator = dres / gcdres; 
	return res;
}

int main() {
	freopen("case4", "r", stdin);
	int N;
	scanf("%d", &N);
	Ration res;
	res.numerator = 0;
	res.denominator = 1;
	for (int i = 0; i < N; i++) {
		Ration temp;
		scanf("%ld/%ld", &temp.numerator, &temp.denominator);
		res = addRation(res, temp);
	}

	long resn = res.numerator;
	long resd = res.denominator;

	if (resn == 0) {
		printf("0");
		return 0;
	}

	if (resn < 0) {
		printf("-");
		resn = - resn;
	}
	
	long whole = resn / resd;
	if (whole) {
		printf("%ld", whole);
	}
	if (resn % resd != 0) {
		if (whole)
			printf(" ");
		printf("%ld/%ld", resn % resd, resd);
	}
	return 0;
}

