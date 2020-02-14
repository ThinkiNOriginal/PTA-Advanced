#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>


int main() {
	std::vector<std::string> day{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	std::string s1, s2, s3, s4;
	std::cin >> s1 >> s2 >> s3 >> s4;
	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = s3.size();
	int len4 = s4.size();
	int len = std::min(len1, len2);
	bool isday = true;
	for (int i = 0; i < len; i++) {
		if (isday and s1[i] == s2[i] and 'A' <= s2[i] and s2[i] <= 'G') {
			printf("%s", day[s2[i] - 'A'].c_str());
			isday = false;
		}
		else if (!isday and s1[i] == s2[i]) {
			if ('A' <= s2[i] and s2[i] <= 'N') {
				printf(" %d", s2[i] - 'A' + 10);
				break;
			} else if('0' <= s2[i] and s2[i] <= '9') {
				printf(" %02d", s2[i] - '0' + 0);
				break;
			}
		}
	}

	len = std::min(len3, len4);
	for (int i = 0; i < len; i++) {
		auto x = s3[i];
		auto y = s4[i];
		if (std::isalpha(x) and std::isalpha(y) and x == y) {
			printf(":%02d", i);
			break;
		}
	}
	return 0;

}
