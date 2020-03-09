#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>


const int maxdis = 1 << 30;

std::vector<int> Dijkstra(std::vector<std::vector<int>>& graph, std::vector<int>& max_Teams, std::vector<int>& teams, std::vector<int>& ways, int s, int e) {
	int len = graph.size();
	std::vector<int> dist(len, maxdis);
	std::vector<bool> visited(len, false);
	dist[s] = 0;
	ways[s] = 1;
	max_Teams[s] = teams[s];
	visited[s] = true;
	int recent = s;

	while (!visited[e]) {
		for (int i = 0; i < len; i++) {
			if (graph[recent][i] and !visited[i]) {
				auto tmpdis = dist[recent] + graph[recent][i];
				if (tmpdis < dist[i]) {
					dist[i] = tmpdis;
					ways[i] = ways[recent];
					max_Teams[i] = max_Teams[recent] + teams[i];
				} else if (tmpdis == dist[i]) {
					max_Teams[i] = std::max(max_Teams[recent] + teams[i], max_Teams[i]);
					ways[i] += way[recent];

				}
			}
		}

		int minTemp = maxdis;
		for (int i = 0; i < len; i++) {
			if (!visited[i] and dist[i] < minTemp) {
				minTemp = dist[i];
				recent = i;
			}
		}
				
		visited[recent] = true;
	}
	return dist;
}
			



int main() {
	int N, M, CS, CE;
	scanf("%d %d %d %d", &N, &M, &CS, &CE);

	std::vector<std::vector<int>> graph(N, std::vector<int>(N, 0));
	std::vector<int> teams(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &teams[i]);

	for (int i = 0; i < M; i++) {
		int ts, te, tc;
		scanf("%d %d %d", &ts, &te, &tc);
		graph[ts][te] = tc;
		graph[te][ts] = tc;
	}

	std::vector<int> max_Teams(N, 0);
	std::vector<int> ways(N, 0);
	std::vector<int> dist = Dijkstra(graph, max_Teams, teams, ways, CS, CE);

	printf("%d %d", ways[CE], max_Teams[CE]);


	return 0;
}
