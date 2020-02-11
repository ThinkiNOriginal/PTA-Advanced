#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

int main() {
	long x;
	long y;
	//scanf("%ld %ld", &x, &y);
	x = -1000000;
	y = 9;
	long res = x + y;
	bool neg = res >= 0 ? false : true;
	res = res < 0 ? -res : res;
	std::string s = std::to_string(res);
	int len = s.size();
	len--;
	int cnt = 0;
	while (len >= 0) {
		if (cnt == 2) {
			cnt = 0;
			if (len - 1 >= 0)
				s.insert(len, 1, ',');
			len--;
		} else {
			cnt++;
			len--;
		}
	}
	if (neg)
		s = '-' + s;
	
	printf("%s\n", s.c_str());

	return 0;
}

