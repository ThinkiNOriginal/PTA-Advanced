#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int Nv, Ne;
	scanf("%d %d", &Nv, &Ne);
	vector<vector<bool>> graph(Nv + 1, vector<bool>(Nv + 1, false));
	for (int i = 0; i < Ne; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		graph[l][r] = true;
		graph[r][l] = true;
	}

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int cnt;
		scanf("%d", &cnt);
		vector<int> temp(cnt);
		for (int j = 0; j < cnt; j++) {
			scanf("%d", &temp[j]);
		}

		bool not_c = false;
		for (int j = 0; j < cnt; j++) {
			for (int k = j + 1; k < cnt; k++) {
				if (!graph[temp[j]][temp[k]]) {
					not_c = true;
					break;
				}
			}
			if (not_c) {
				printf("Not a Clique\n");
				break;
			}
		}
		if (not_c)
			continue;

		bool not_m = false;
		for (int j = 1; j <= Nv; j++) {
			bool connected = true;
			for (int k = 0; k < cnt; k++) {
				if (!graph[j][temp[k]]) {
					connected = false;
					break;
				}
			}
			if (connected) {
				not_m = true;
				printf("Not Maximal\n");
				break;
			}
		}
		if (not_m)
			continue;

		printf("Yes\n");
	}
	return 0;
}
