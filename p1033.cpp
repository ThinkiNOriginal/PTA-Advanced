#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

const double maxcost = 1000000;

struct Stops {
	double price;
	double dist;
};

bool cmp (Stops& s1, Stops& s2) {
	return s1.dist < s2.dist;
}

int main() {

	double CM, D, Davg;
	int N;
	std::cin >> CM >> D >> Davg >> N;
	std::vector<Stops> v(N);
	std::vector<double> cost(D + 1, maxcost);
	cost[0] = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> v[i].price >> v[i].dist;
	}
	std::sort(v.begin(), v.end(), cmp);

	double one_tank_dis = CM * Davg;


	for (int i = 1; i <= D; i++) {
		for (int j = 0; j < N; j++) {
			auto yd = v[j].dist;
			auto yp = v[j].price;
			if (0 < i - yd and i - yd <= one_tank_dis) {
				cost[i] = std::min(cost[i], cost[i - 1] + 1 / Davg * yp);
			}
		}
	}

	if (cost[D] == maxcost) {
		for (int i = D; i >= 0; i--) {
			if (cost[i] != maxcost) {
				printf("The maximum travel distance = %.2f", double(i));
				break;
			}
		}
	} else
		printf("%.2f", cost[D]);
	return 0;
	


}
