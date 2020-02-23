#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int main () {
	int N;
	scanf("%d", &N);
	vector<double> v(N);
	double total = 0;
	for (int i = 0; i < N; i++) {
		double tmp;
		scanf("%lf", &tmp);
		total += tmp * (i - 0 + 1) * (N - i);
	}

	printf("%.2lf", total);
	return 0;


}
