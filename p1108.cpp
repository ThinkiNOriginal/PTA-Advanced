#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


bool is_legal(string& str) {
	int dotcnt = 0;
	int afterdot = 0;
	int negcnt = 0;
	int len = str.size();
	bool dot = false;
	for (int i = 0; i < len; i++) {
		auto x = str[i];
		if (x == '-') {
			negcnt++;
			if (negcnt > 1)
				return false;
			continue;
		}
		if (x == '.') {
			dotcnt++;
			dot = true;
			if (dotcnt > 1)
				return false;
			continue;
		}else
			if (x < '0' or x > '9')
				return false;
		if (dot) {
			afterdot++;
			if (afterdot > 2)
				return false;
		}
	}
	return true;
}


int main() {
	int N;
	scanf("%d", &N);
	int cnt = 0;
	double total = 0;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		if (is_legal(tmp)) {
			double td = stod(tmp);
			if (-1000 <= td and td <= 1000) {
				total += td;
				cnt++;
			} else
				printf("ERROR: %s is not a legal number\n", tmp.c_str());

		} else {
			printf("ERROR: %s is not a legal number\n", tmp.c_str());
		}
	}
	if (cnt == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (cnt == 1) {
		printf("The average of 1 number is %.2lf", total);
	}
	else {
		printf("The average of %d numbers is %.2lf", cnt, total / cnt);
	}
	return 0;
}

