#include <string>
#include <cstdio>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int M, N, S;
	cin >> M >> N >> S;
	unordered_set<string> r;
	int cur = 0;
	bool found = false;
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (!r.count(temp)) {
			cur++;
			if (cur >= S and (cur - S) % N == 0) {
				found = true;
				cout << temp << endl;
				r.insert(temp);
			}
		}
	}
	if (!found)
		printf("Keep going...");
	return 0;
}	

