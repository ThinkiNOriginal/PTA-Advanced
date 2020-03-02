#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;


struct School {
	string name;
	int rank;
	double TWSd = 0;
	int TWSi = 0;
	int Ns = 0;
};

bool cmp (School& s1, School& s2) {
	if (s1.TWSi != s2.TWSi) {
		return s1.TWSi > s2.TWSi;
	} else if (s1.Ns != s2.Ns) {
		return s1.Ns < s2.Ns;
	} else {
		return s1.name < s2.name;
	}
}

int main() {
	int N;
	cin >> N;
	map<string,School> mapSchool;
	for (int i = 0; i < N; i++) {
		string id;
		double score;
		string name;
		cin >> id >> score >> name;
		for (auto& x : name) {
			if (x >= 'A' and x <= 'Z')
				x -= 'A' - 'a';
		}
		mapSchool[name].Ns++;
		mapSchool[name].name = name;
		switch(id[0]) {
			case 'B':
				mapSchool[name].TWSd += score / 1.5;
				break;
			case 'A':
				mapSchool[name].TWSd += score;
				break;
			case 'T':
				mapSchool[name].TWSd += score * 1.5;
				break;
		}
	}

	vector<School> res;
	for (auto x : mapSchool) {
		x.second.TWSi = int(x.second.TWSd);
		res.push_back(x.second);
	}
	sort(res.begin(), res.end(), cmp);
	int len = res.size();
	res[0].rank = 1;
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i != 0) {
			if (res[i].TWSi == res[i - 1].TWSi) {
				res[i].rank = res[i - 1].rank;
			} else {
				res[i].rank = i + 1;
			}
		}
		printf("%d ", res[i].rank);
		printf("%s %d %d\n", res[i].name.data(), res[i].TWSi, res[i].Ns);
	}
	return 0;
}



