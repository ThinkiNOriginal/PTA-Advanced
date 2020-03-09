#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxsize = 100000;


struct Student {
    vector<int> p{-2, -2, -2, -2, -2, -2};
	int id;
	int rank;
	int total = 0; 
	int perferct = 0;
	bool pass = false;
};

bool cmp(Student& s1, Student& s2) {
	if (s1.total != s2.total) {
		return s1.total > s2.total;
	} else {
		if (s1.perferct != s2.perferct) {
			return s1.perferct > s2.perferct;
		}else {
			return s1.id < s2.id;
		}
	}
}

int main() {

	int N, K, M;
	cin >> N >> K >> M;
	vector<Student> vs(maxsize);
	vector<int> problems(K + 1);
	for (int i = 1; i <= K; i++)
		cin >> problems[i];

	for (int i = 0; i < M; i++) {
		int tid, tp, tg;
		cin >> tid >> tp >> tg;
		if (tg >= 0)
			vs[tid].pass = true;
		vs[tid].id = tid;
		vs[tid].p[tp] = max(vs[tid].p[tp], tg);
	}
	vector<Student> res;
	for (auto x : vs) {
		for (int i = 1;i <= K; i++) {
            auto temp = x.p[i];
			if (temp > 0)
				x.total += temp;
            if (temp == problems[i]) {
                x.perferct++;
            }
		}
		if (x.pass)
			res.push_back(x);
	}

	sort(res.begin(), res.end(), cmp);
	int len = res.size();
	res[0].rank = 1;
	for (int i = 1; i < len; i++) {
		if (res[i].total == res[i - 1].total)
			res[i].rank = res[i - 1].rank;
		else 
			res[i].rank = i + 1;
	} 

	for (int i = 0; i < len; i++) {
		printf("%d %05d %d", res[i].rank, res[i].id, res[i].total);
		for (int j = 1; j <= K; j++) {
			auto x = res[i].p[j];
			if (x == -2)
				printf(" -");
			else if (x == -1)
				printf(" 0");
			else
				printf(" %d", x);
		}
		printf("\n");
	}
		
		
	return 0;

}



