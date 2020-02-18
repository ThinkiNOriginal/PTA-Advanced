#include <vector>
#include <cstdio>
#include <algorithm>

const int maxsize = 1 << 30;

struct Edge {
	int cost = 0;
	int dist = 0;
};

std::vector<int> Dijskra(std::vector<std::vector<Edge>>& graph, std::vector<int>& dist, std::vector<int>& cost, int s, int e) {

	int len = graph.size();
	std::vector<bool> visited(len, false);
	std::vector<int>  prev(len, -1);
	dist[s] = 0;
	visited[s] = true;
	cost[s] = 0;
	int cur = s;

	while (!visited[e]) {
		for (int i = 0; i < len; i++) {
			if (graph[cur][i].dist and !visited[i]) {
				auto tmpdis = graph[cur][i].dist + dist[cur];
				if (tmpdis < dist[i]) {
					dist[i] = tmpdis;
					prev[i] = cur;
					cost[i] = graph[cur][i].cost + cost[cur];
				} else if (tmpdis == dist[i]) {
					if (graph[cur][i].cost + cost[cur] < cost[i]) {
						cost[i] = graph[cur][i].cost + cost[cur];
						prev[i] = cur;
					}
				}
			}
		}

		int minLen = maxsize;
		for (int i = 0; i < len; i++) {
			if (!visited[i] and dist[i] < minLen) {
				cur = i;
				minLen = dist[i];
			}
		}

		visited[cur] = true;

	}
	return prev;
}

int main () {
	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	std::vector<std::vector<Edge>> graph(N, std::vector<Edge>(N));

	for (int i = 0; i < M; i++) {
		int s, e, d, c;
		scanf("%d %d %d %d", &s, &e, &d, &c);
		graph[s][e].cost = c;
		graph[s][e].dist = d;
		graph[e][s].cost = c;
		graph[e][s].dist = d;
	}

	std::vector<int> dist(N, maxsize);
	std::vector<int> cost(N, maxsize);
	auto prev = Dijskra(graph, dist, cost, S, D);
	std::vector<int> normal_order;
	int DD = D;
	while (D != -1) {
		normal_order.push_back(D);
		D = prev[D];
	}
	for (int i = normal_order.size() - 1; i >= 0; i--) {
		printf("%d ", normal_order[i]);
	}
	printf("%d %d", dist[DD], cost[DD]);
	return 0;
}
		


