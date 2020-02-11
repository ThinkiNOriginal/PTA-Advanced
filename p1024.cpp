#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
std::string isP(std::string str, bool& isp) {


	std::string r_str = str;
	std::reverse(r_str.begin(), r_str.end());

	int c = 0;
	int len = str.size();
	int tmp;
	std::string res;
	for (int i = len - 1; i >= 0; i--) {
		tmp = str[i] - '0' + r_str[i] - '0' + c;
		int q = tmp % 10;
		c = tmp / 10;
		res = std::to_string(q) + res;
	}
	if (c)
		res = '1' + res;

	len = res.size();
	for (int i = len / 2; i >= 0; i--) {
		if (res[i] != res[len - i - 1]) {
			isp = false;
			break;
		}
	}

	return res;
		

}




int main () {
	std::string ori;
	int k;
	std::cin >> ori >> k;
	int lenO = ori.size();
	bool isp = true;
	for (int i = lenO - 1; i >= 0; i--) {
		if (ori[i] != ori[lenO - i - 1]){
			isp = false;
			break;
		}
	}	
	if (isp) {
		printf("%s\n0\n", ori.c_str());
		return 0;
	}
	//std::string cur;
	for (int i = 1; i <= k; i++){
		isp = true;
		ori = isP(ori, isp);
		if (isp) {
			printf("%s\n%d\n", ori.c_str(), i);
			return 0;
		}
	}
	printf("%s\n%d\n", ori.c_str(), k);
	return 0;
}
