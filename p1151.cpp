#include <vector>
#include <cstdio>
#include <unordered_set>
#include <map>

using namespace std;

int LCA(map<int,int>& mappos, vector<int>& ino, vector<int>& pre, int l, int r, int inL, int inR, int preL, int preR) {
	int val = pre[preL];
	if (val == l or val == r)
		return val;

	auto lp = mappos[l];
	auto rp = mappos[r];
	auto slit = mappos[val];

	bool existl = lp < slit;
	bool existr = rp < slit;

	if (existl and existr) {
			return LCA(mappos, ino, pre, l, r, inL, slit - 1, preL + 1, preL + slit - inL);
	} else if (!existr and !existl) {
			return LCA(mappos, ino, pre, l, r, slit + 1, inR, preL + 1 + slit - inL, preR);
	} else {
		return val;
	}
}




int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	vector<int> ino(N);
	vector<int> pre(N);
	map<int,int> mappos;
	unordered_set<int> usheap;
	for (int i = 0; i < N; i++) {
		scanf("%d", &ino[i]);
		mappos[ino[i]] = i;
		usheap.insert(ino[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &pre[i]);
	}

	for (int i = 0; i < M; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		auto existl = usheap.count(l);
		auto existr = usheap.count(r);
		if (!existl and !existr) {
			printf("ERROR: %d and %d are not found.\n", l, r);
		} else if (!existl) {
			printf("ERROR: %d is not found.\n", l);
		} else if (!existr) {
			printf("ERROR: %d is not found.\n", r);
		} else {
			auto res = LCA(mappos, ino, pre, l, r, 0, N - 1, 0, N - 1);
			if (res == l) {
				printf("%d is an ancestor of %d.\n", l, r);
			} else if (res == r) {
				printf("%d is an ancestor of %d.\n", r, l);
			} else {
				printf("LCA of %d and %d is %d.\n", l, r, res);
			}
		}
	}
	return 0;
}
		


