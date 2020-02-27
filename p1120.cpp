#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxsize = 50;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(maxsize, 0);
	for (int i = 0; i < N; i++) {
		char temp[5];
		scanf("%s", temp);
		int cnt = 0;
		for (int j = 0; j < strlen(temp); j++) {
			cnt += temp[j] - '0';
		}
		v[cnt]++;
	}

	vector<int> res;
	for (int i = 0; i < maxsize; i++) {
		if (v[i] != 0)
			res.push_back(i);
	}
	int len = res.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", res[i]);
	}
	return 0;
}


			
