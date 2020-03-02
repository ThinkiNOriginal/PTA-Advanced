#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	string D;
	int N;
	cin >> D >> N;
	for (int i = 1; i < N; i++) {
		string tmp;
		int len = D.size();
		for (int j = 0; j < len; j++) {
			int cnt = 1;
			for (int k = j + 1; k < len; k++) {
				if (D[k] == D[j]) {
					cnt++;
					j = k;
				} else {
					break;
				}
			}
			tmp += D[j] + to_string(cnt);
		}
		D = tmp;
	}
	cout << D << endl;
	return 0;
}


