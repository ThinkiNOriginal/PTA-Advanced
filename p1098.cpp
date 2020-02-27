#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void heapify(vector<int>& heap, int cur) {
	int i = 0;
	while (i <= (cur - 1) / 2) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		bool leftbigger = true;
		if (right <= cur) {
			if (heap[left] < heap[right])
				leftbigger = false;
		}
		if (leftbigger) {
			if (heap[i] < heap[left]) {
				swap(heap[i], heap[left]);
				i = left;
			}
		} else {
			if (heap[i] <heap[right]) {
				swap(heap[i], heap[right]);
				i = right;
			}
		}
	}
}



int main() {
	int N;
	scanf("%d", &N);
	vector<int> ori(N);
	vector<int> par(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &ori[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &par[i]);
	}

	int index = 0;
	while (is_sorted(par.begin(), par.begin() + index) and index < N)
		index++;

	bool insertion = true;
	for (int i = index; i <N; i++)
		if (par[i] != ori[i]) {
			insertion = false;
			break;
		}

	if (insertion) {
		printf("Insertion Sort\n");
		sort(par.begin(), par.begin() + index);
		
	} else {
		printf("Heap Sort\n");
		int index = 0;
		while (is_sorted(par.end() - index, par.end()) and index < N)
			index++;
		swap(par[0], par[N - index + 1]);
		heapify(par, N - index);
	}
	for (int i = 0; i < N; i++) {
			if (i != 0)
				printf(" ");
			printf("%d", par[i]);
	}
	return 0;
}



