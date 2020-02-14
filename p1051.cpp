#include <stack>
#include <cstdio>
#include <vector>


int main() {
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++) {
		std::stack<int> s;
		int stop = 1;
		int cur;
		bool suc = true;
		for (int j = 0; j < N; j++) {
			scanf("%d", &cur);
			if (s.empty()){
				s.push(stop++);
			}
			while (stop <= cur) {
				s.push(stop++);
			}
			if (s.size() > M) {
				suc = false;
			}
			if (s.top() == cur)
				s.pop();
		}
		if (s.empty() and suc)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}


			
