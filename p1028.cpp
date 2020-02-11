#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Student {
	std::string id;
	std::string name;
	int grades;
};

bool cmp1 (Student& s1, Student& s2) {
	return s1.id < s2.id;
}

bool cmp2 (Student& s1, Student& s2) {
	if (s1.name != s2.name)
		return s1.name < s2.name;
	else
		return s1.id < s2.id;
}

bool cmp3 (Student& s1, Student& s2) {
	if (s1.grades != s2.grades)
		return s1.grades < s2.grades;
	else
		return s1.id < s2.id;
}

int main() {
	int N, C;
	std::cin >> N >> C;

	std::vector<Student> v(N);

    for (int i = 0; i < N; i++) {
		std::cin >> v[i].id >> v[i].name >> v[i].grades;
	}

	switch(C) {
		case 1:
			sort(v.begin(), v.end(), cmp1);
			break;
		case 2:
			sort(v.begin(), v.end(), cmp2);
			break;
		case 3:
			sort(v.begin(), v.end(), cmp3);
			break;
	}



	for (auto x : v) {
		printf("%s %s %d\n", x.id.c_str(), x.name.c_str(), x.grades);
	}

	return 0;
}

