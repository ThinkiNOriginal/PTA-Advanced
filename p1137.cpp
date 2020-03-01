#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Student {
	int online = -1;
	int midterm = -1;
	int finalexam = -1;
	int G = 0;
	string name;
};

bool cmp (Student& s1, Student& s2) {
	if (s1.G != s2.G) {
		return s1.G > s2.G;
	} else {
		return s1.name < s2.name;
	}
}

int main() {
	int P, M, N;
	scanf("%d %d %d", &P, &M, &N);
	map<string, Student> mapStudent;
	for (int i = 0; i < P; i++) {
		string tname;
		int temp;
		cin >> tname >> temp;
		mapStudent[tname].online = temp;
		mapStudent[tname].name = tname;
	}
	for (int i = 0; i < M; i++) {
		string tname;
		int temp;
		cin >> tname >> temp;
		mapStudent[tname].midterm = temp;
		mapStudent[tname].name = tname;
	}
	for (int i = 0; i < N; i++) {
		string tname;
		int temp;
		cin >> tname >> temp;
		mapStudent[tname].finalexam = temp;
		mapStudent[tname].name = tname;
	}

	vector<Student> res;
	for (auto& x : mapStudent) {
		double temp;
		if (x.second.finalexam < x.second.midterm) {
			temp = 0.4 * x.second.midterm + 0.6 * x.second.finalexam;
		} else {
			temp = x.second.finalexam;
		}

		x.second.G = int(temp + 0.5);

		if (x.second.online >= 200 and x.second.G >= 60) {
			res.push_back(x.second);
		}
	}

	sort(res.begin(), res.end(), cmp);
	for (auto x : res) {
		cout << x.name;
		printf(" %d %d %d %d\n", x.online, x.midterm, x.finalexam, x.G);
	}
	return 0;
}





