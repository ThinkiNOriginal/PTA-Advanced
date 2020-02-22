#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main () {
	int N;
	cin >> N;
	string ori;
	getline(cin, ori);
	getline(cin, ori);
	int rescnt = 300;
	int leno = ori.size();
	for (int i = 1; i < N; i++) {
		string cmp;
		getline(cin, cmp);
		int len = cmp.size();
		int ii = 0;
		int j = 0;
		int tmpcnt = 0;
		while (ii < leno and j < len) {
			if (ori[leno - ii - 1] == cmp[len - j - 1]) {
				ii++;
				j++;
				tmpcnt++;
			} else
				break;
		}
		rescnt = min(rescnt, tmpcnt);
	}

	if (rescnt == 0)
		printf("nai\n");
	else {
		for (int i = leno - rescnt; i < leno; i++)
			printf("%c", ori[i]);
	}
	return 0;
}
		

