#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
	int fre = 0;
	int val = -1;
};

bool cmp (Node* n1, Node* n2) {
	if (n1 -> fre != n2 -> fre)
		return n1 -> fre > n2 -> fre;
	else
		return n1 -> val < n2 -> val;
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<Node> v(N + 1);
    vector<Node*> ans;
    vector<bool> vis(N + 1, false);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		v[temp].val = temp;
		if (i != 0) {
			printf("%d:", temp);
			int len = min(K, (int)ans.size());
            sort(ans.begin(), ans.end(), cmp);
            while (ans.size() > K) {
                auto x = ans.back();
                vis[x -> val] = false;
                ans.pop_back();
            }
			for (int i = 0; i < len; i++) {
				printf(" %d", ans[i] -> val);
			}
			printf("\n");
		}
		v[temp].fre++;
        if (!vis[temp]) {
            vis[temp] = true;
            ans.push_back(&v[temp]);
        }
	}
	return 0;
}


