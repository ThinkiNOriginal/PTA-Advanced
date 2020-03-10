#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main() {
	int N;
	cin >> N;
	string str;
	cin >> str;
	string tmps = str;
	unordered_set<char> repe;

	int i = 0;
	while (i < tmps.size()) {
		bool re = true;
		for (int j = 1; j < N; j++) {
			if (tmps[i + j] != tmps[i]) {
				re = false;
				i += j;
				break;
			}
		}
		if (re) {
			repe.insert(tmps[i]);
			tmps.erase(i, N);
		}
	}

	unordered_set<char> nonre;
	for (auto x : tmps) {
		nonre. insert(x);
	}

	i = 0;
	vector<char> res;
	unordered_set<char> r;
	while (i < str.size()) {
		if (repe.count(str[i]) and !nonre.count(str[i])) {
			str.erase(i, N - 1);
			if (!r.count(str[i])) {
				res.push_back(str[i]);
				r.insert(str[i]);
			}
		}
		i++;
	}

	for (auto x : res) {
		printf("%c", x);
	}
	printf("\n");
	cout << str << endl;
	return 0;
}


