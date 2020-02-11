#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>


struct Node {
	int id;
	std::vector<int> children;
};

int main() {

	int N = 0;
	std::cin >> N;
	if (N == 0)
		return 0;
	
	std::vector<Node*> v(100);
	int M;
	std::cin >> M;
	while (M--) {
		int id, K;
		std::cin >> id >> K;
		Node* n_node = new Node;
		std::vector<int> tmpc(K);
		for (int i = 0; i < K; i++)
			scanf("%d", &tmpc[i]);
		n_node -> id = id;
		n_node -> children = tmpc;
		v[id] = n_node;
	}
						
	std::queue<int> q;
	q.push(1);
	std::vector<int> leaves;
	while (!q.empty()) {
		int len = q.size();
		int cnt_leaf = 0;
		for (int i = 0; i < len; i++) {
			auto x = v[q.front()];
			q.pop();
			if (x) {
				for (auto y : x -> children)
					q.push(y);
			} else {
				cnt_leaf++;
			}
		}
		leaves.push_back(cnt_leaf);
	}
		
	
	int lenL = leaves.size();
	for (int i = 0; i < lenL; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", leaves[i]);
	}


	return 0;



}
