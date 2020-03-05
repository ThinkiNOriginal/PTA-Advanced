#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> paths(vector<int>& heap, vector<int> temp, int cur, int len) {
	static vector<vector<int>> res;
	if (cur < len) {
		int left = 2 * cur + 1;
		int right = 2 * cur + 2;
		temp.push_back(heap[cur]);
		if (left >= len) {
			res.push_back(temp);
			return res;
		}
		paths(heap, temp, right, len);
		paths(heap, temp, left, len);
	}
		return res;
}


int main() {
	int N;
	scanf("%d", &N);
	vector<int> heap(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &heap[i]);
	vector<int> tmp;
	auto res = paths(heap, tmp, 0, N);
	bool minsorted = true;
	bool maxsorted = true;
	for (auto x : res) {
		int len = x.size();
				for (int i = 0; i < len; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", x[i]);
		}
		printf("\n");
		if (minsorted and !is_sorted(x.begin(), x.end()))
			minsorted = false;
		if (maxsorted and !is_sorted(x.begin(), x.end(), [](int a, int b) { return a > b;}))
			maxsorted = false;
	}
	if (minsorted and !maxsorted) {
		printf("Min Heap\n");
	} else if (maxsorted and !minsorted) {
		printf("Max Heap\n");
	} else {
		printf("Not Heap\n");
	}
	return 0;
}



