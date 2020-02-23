#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end(), greater<int>());
	
	int m, n;
	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			n = i;
			m = N / i;
		}
	}
	

	vector<vector<int>> matrix(m, vector<int>(n, 0));

	int i = 0;
	int row = 0;
	int col = 0;
	int bup = 0;
	int bdown = m;
	int bleft = 0;
	int bright = n;
	matrix[0][0] = v[0];
	while (i < N - 1) {

		while (col < bright - 1 and matrix[row][col + 1] == 0) {
			col++;	
			i++;
			matrix[row][col] = v[i];
		}  
		while (row < bdown - 1 and matrix[row + 1][col] == 0) {
			row++;
			i++;
			matrix[row][col] = v[i];
		} 
		while (col >= bleft + 1 and matrix[row][col - 1] == 0) {
			col--;
			i++;
			matrix[row][col] = v[i];
		} 
		while (row >= bup + 1 and matrix[row - 1][col] == 0) {
			row--;
			i++;
			matrix[row][col] = v[i];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j != 0)
				printf(" ");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}


	return 0;

}
