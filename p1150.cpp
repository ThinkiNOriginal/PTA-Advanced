#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;


int is_TS_cycle(vector<vector<int>>& graph, vector<int>& path, vector<int>& cnt) {
	int plen = path.size();
	int dis = 0;
	cnt[path[0]]++;
	for (int i = 1; i < plen; i++) {
		auto prev = path[i - 1];
		auto curp = path[i];
		if (graph[curp][prev]) {
			dis += graph[curp][prev];
			cnt[curp]++;
		}
		else
			return -1;
	}
	return dis;
}
		

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++) {
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		graph[l][r] = c;
		graph[r][l] = c;
	}
	int K;
	scanf("%d", &K);
	int mindis = 1 << 30;
	int index = -1;
	for (int i = 1; i <= K; i++) {
		int temp;
		scanf("%d", &temp);
		vector<int> tempv(temp);
		for (int j = 0; j < temp; j++) {
			scanf("%d", &tempv[j]);
		}
		vector<int> cnt(N + 1, 0);
		auto res = is_TS_cycle(graph, tempv, cnt);
		printf("Path %d: ", i);
		if (res > 0) {
			printf("%d ", res);
			
		} else {
			printf("NA ");
		}
		int more_once = 0;
		bool NA = false;
		for (int i = 1; i <= N; i++) {
			if (cnt[i] == 0) {
				NA = true;
				printf("(Not a TS cycle)\n");
				break;
			}
			if (cnt[i] > 1)
				more_once++;
		}
		if (NA)
			continue;
		if (more_once == 1 and tempv[0] == tempv[temp - 1]) {
			if (mindis > res) {
				mindis = res;
				index = i;
			}
			printf("(TS simple cycle)\n");
		}
		else if(tempv[0] != tempv[temp - 1]) {
			printf("(Not a TS cycle)\n");
		} else {
			if (mindis > res) {
				mindis = res;
				index = i;
			}
			printf("(TS cycle)\n");
		}
	}
	printf("Shortest Dist(%d) = %d\n", index, mindis);
	return 0;
}
			


