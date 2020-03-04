#include <vector>
#include <cstdio>

using namespace std;

void postorder(vector<int>& v, vector<int>& res, int cur, int size) {
	if (cur < size) {
		postorder(v, res, cur * 2 + 1, size);
		postorder(v, res,cur * 2 + 2, size);
		res.push_back(v[cur]);
	}
}

bool maxHeap(vector<int>& v, int cur, int size) {
	if (cur < size) {
		int left = 2 * cur + 1;
		int right = 2 * cur + 2;
		auto x = v[cur];
		if (left < size and v[left] > x)
			return false;
		if (right < size and v[right] > x)
			return false;
		return maxHeap(v, left, size) and maxHeap(v, right, size);
	}
	return true;
}

bool minHeap(vector<int>& v, int cur, int size) {
	if (cur < size) {
		int left = 2 * cur + 1;
		int right = 2 * cur + 2;
		auto x = v[cur];
		if (left < size and v[left] < x)
			return false;
		if (right < size and v[right] < x)
			return false;
		return minHeap(v, left, size) and minHeap(v, right, size);
	}
	return true;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		vector<int> temp(N);
		for (int j = 0; j < N; j++)
			scanf("%d", &temp[j]);

		if (maxHeap(temp, 0, N)) {
			printf("Max Heap\n");
		} else if (minHeap(temp, 0, N)) {
			printf("Min Heap\n");
		} else {
			printf("Not Heap\n");
		}
		vector<int> res;
		postorder(temp, res, 0, N);
		for (int j = 0; j < N; j++) {
			if (j != 0)
				printf(" ");
			printf("%d", res[j]);
		}
		printf("\n");
	}
	return 0;
}
			


