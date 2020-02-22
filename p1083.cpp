#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct Student {
	string name;
	string id;
	int    grade;
};

bool cmp (Student& s1, Student& s2) {
	return s1.grade > s2.grade;
}

int main () {

	int N;
	scanf("%d", &N);
	vector<Student> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].id >> v[i].grade;
	}

	vector<Student> r;
	int gl = 0;
	int gh = 0;
	scanf("%d %d", &gl, &gh);
	
	for (auto x : v) {
		if (gl <= x.grade and x.grade <= gh)
			r.push_back(x);
	}

	sort(r.begin(), r.end(), cmp);
	int len = r.size();
	if (len == 0) {
		printf("NONE\n");
	} else {
		for (auto x : r) {
			printf("%s %s\n", x.name.c_str(), x.id.c_str());
		}
	}
	




	return 0;
}

