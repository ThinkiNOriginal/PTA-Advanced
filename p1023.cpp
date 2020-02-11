#include <iostream>
#include <string>
#include <vector>

std::string dou_num(std::string ori){
	std::string cur;
	int c = 0;
	int len = ori.size();
	int tmp = 0;
	for (int i = len - 1; i >= 0; i--) {
		tmp = 2 * (ori[i] - '0') + c;
		c = tmp / 10;
		cur = std::to_string(tmp % 10) + cur;
	}
	if (c)
		cur = '1' + cur;
	return cur;
		
}
int main () {
	std::string ori;
	std::cin >> ori;
	std::vector<int> rec(10);
	std::vector<int> cur(10);
	for (auto x : ori)
		rec[x - '0']++;
	std::string curS = dou_num(ori);
	for (auto x : curS)
		cur[x - '0']++;
	
	bool suc = true;
	for (int i = 0; i < 10; i++)
		if (rec[i] != cur[i]) {
			suc = false;
			break;
		}
	if (suc)
		printf("Yes\n");
	else
		printf("No\n");

	printf("%s", curS.c_str());

	return 0;
}

