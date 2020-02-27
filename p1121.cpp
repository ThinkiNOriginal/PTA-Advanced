#include <vector>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int maxsize = 100000;

struct Edge {
	int l;
	int r;
};

int main() {
	int N;
	scanf("%d", &N);
	vector<Edge> company(N);
	for (int i = 0; i < N; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		company[i].l = l;
		company[i].r = r;
	}
	scanf("%d", &N);
	vector<int> resC;
	vector<bool> partyM(maxsize, false);
	unordered_set<int> party;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		partyM[temp] = true;
		party.insert(temp);
	}

	for (auto x : company) {
//		if (party.count(x.l) and !party.count(x.r)) {
//			res.push_back(x.l);
//		}
//		if (party.count(x.r) and !party.count(x.l)) {
//			res.push_back(x.r);
//		}
		if (party.count(x.l) and party.count(x.r)) {
			//resC.push_back(x.r);
			//resC.push_back(x.l);
			partyM[x.r] = false;
			partyM[x.l] = false;
		}
	}
	
	vector<int> res;
 	for (int i = 0; i < maxsize; i++)
		if (partyM[i])
			res.push_back(i);
		

	int len = res.size();
	sort(res.begin(), res.end());
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf(" ");
		printf("%05d", res[i]);
	}
	return 0;
}
