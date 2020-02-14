#include <cstdio>
#include <vector>


int main() {
	int NP, NG;
	scanf("%d %d", &NP, &NG);

	std::vector<int> weights(NP);
	for (int i = 0; i < NP; i++) {
		scanf("%d", &weights[i]);
	}

	std::vector<int> rank(NP, 0);
	std::vector<int> order(NP);
	for (int i = 0; i < NP; i++) {
		scanf("%d", &order[i]);
	}

	int rounds = 1;
	int cnt    = 0;
	int totalcnt = 0;
	int winnerW = -1;
	int winnerP = -1;
	int ulti = -1;
	
	while (true) {
		winnerW = -1;
		winnerP = -1;
		cnt = 0;
		totalcnt = 0;
		for (int i = 0; i < NP; i++) {
			auto x = order[i];
			if (rank[x] == 0) {
				ulti = x;
				if (winnerW == -1) {
					winnerW = weights[x];
					winnerP = x;
				} else if (winnerW < weights[x]) {
					winnerW = weights[x];
					rank[winnerP] = rounds;
					winnerP = x;
				} else if (winnerW > weights[x]) {
					rank[x] = rounds;
				}
				cnt++;
				totalcnt++;
			}
			if (cnt == NG) {
				cnt = 0;
				winnerW = -1;
				winnerP = -1;
			}
		}
		rounds++;
		if (totalcnt == 1)
			break;
	}
	int ranking = 2;
	int samelevel = 0;
	std::vector<int> res(NP);
	for (int i = rounds - 1; i >= 1; i--) {
		ranking += samelevel;
		samelevel = 0;
		for (int j = 0; j < NP; j++) {
			if (rank[j] == i) {
				res[j] = ranking;
				samelevel++;
			}
		}
	}
	res[ulti] = 1;
	
	for (int i = 0; i < NP; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}

	


}





