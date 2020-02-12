#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

struct Student {
	char rn[13];
	int   grades;
	int   final_r;
	int   local_r;
	int   ln;
};

bool cmp (const Student& s1, const Student& s2) {
	if (s1.grades != s2.grades)
		return s1.grades > s2.grades;
	else
		return std::strcmp(s1.rn, s2.rn) < 0;
}

bool cmp2 (const Student& s1, const Student& s2) {
	if (s1.grades != s2.grades)
		return s1.grades > s2.grades;
	else
		return std::strcmp(s1.rn, s2.rn) < 0;
}


int main() {

	int N;
	scanf("%d", &N);
	std::vector<std::vector<Student>> v(N);
	std::vector<Student> all;
	int total_num = 0;

	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		total_num += K;
		std::vector<Student> tmp(K);
		for (int j = 0; j < K; j++) {
			scanf("%s %d", tmp[j].rn, &tmp[j].grades);
			tmp[j].ln = i + 1;
		}
		v[i] = tmp;
	}


	for (auto& x : v) {
		std::sort(x.begin(), x.end(), cmp);
		int len = x.size();
		x[0].local_r = 1;
		all.push_back(x[0]);
		for (int i = 1; i < len; i++) {
			if (x[i].grades == x[i - 1].grades) {
				x[i].local_r = x[i - 1].local_r;
			} else
				x[i].local_r = i + 1;
			all.push_back(x[i]);
	}}
	
	std::sort(all.begin(), all.end(), cmp2);
	all[0].final_r = 1;
	for (int i = 1; i < total_num; i++) {
		if (all[i].grades == all[i - 1].grades) {
			all[i].final_r = all[i - 1].final_r;
		} else
			all[i].final_r = i + 1;
	}

	printf("%d\n", total_num);
	for (auto x : all)
		printf("%s %d %d %d\n", x.rn, x.final_r, x.ln, x.local_r);

	return 0;

}

