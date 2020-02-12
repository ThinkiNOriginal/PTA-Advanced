#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

int main() {

	std::string s;
	//std::cin >> s;
	std::getline(std::cin, s);	
	int len = s.size();
	int res = -1;
	for (int i = 0; i < len; i++) {
		int tmpl = i;
		int	tmph = i + 1; 
		int tmp_len = 0;
		while (tmpl >= 0 and tmph < len and s[tmpl] == s[tmph]) {
			tmp_len += 2;
			tmpl--;
			tmph++;
		}
		res = std::max(res, tmp_len);	
		tmp_len = 1;
		tmpl = i - 1;
		tmph = i + 1;
		while (tmpl >=0 and tmph < len and s[tmpl] == s[tmph]) {
			tmp_len += 2;
			tmpl--;
			tmph++;
		}
		res = std::max(res, tmp_len);

	}

	printf("%d", res);
	return 0;
}

