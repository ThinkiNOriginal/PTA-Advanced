#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>


struct Man {
	char id[9];
	int  vg;
	int  tg;
};

bool cmp (Man& m1, Man& m2) {
	auto x = m1.vg + m1.tg;
	auto y = m2.vg + m2.tg;
	if (x != y)
		return x > y;
	else {
		if (m1.vg != m2.vg)
			return m1.vg > m2.vg;
		else
			return strcmp(m1.id, m2.id) < 0;
	}
}
		


int main () {
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);
	std::vector<Man> sages;
	std::vector<Man> nobleman;
	std::vector<Man> foolman;
	std::vector<Man> smallman;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		char ti[9];
		int tv, tt;
		scanf("%s %d %d", ti, &tv, &tt);
		Man m;
		strcpy(m.id, ti);
		m.vg = tv;
		m.tg = tt;
		if (tv < L or tt < L)
			continue;

		cnt++;
		if (tv >= H and tt >= H)
			sages.push_back(m);
		else if (L <= tt and tt < H and H <= tv)
			nobleman.push_back(m);
		else if (L <= tt and tt < H and L <= tv and tv <H and tt <= tv)
			foolman.push_back(m);
		else
			smallman.push_back(m);
	}

	printf("%d\n", cnt);
	std::sort(sages.begin(), sages.end(), cmp);
	for (auto x : sages) {
		printf("%s %d %d\n", x.id, x.vg, x.tg);
	}
	std::sort(nobleman.begin(), nobleman.end(), cmp);
	for (auto x : nobleman) {
		printf("%s %d %d\n", x.id, x.vg, x.tg);
	}
	
	std::sort(foolman.begin(), foolman.end(), cmp);
	for (auto x : foolman) {
		printf("%s %d %d\n", x.id, x.vg, x.tg);
	}	
	std::sort(smallman.begin(), smallman.end(), cmp);
	for (auto x : smallman) {
		printf("%s %d %d\n", x.id, x.vg, x.tg);
	}	
	return 0;
}


