#include <iostream>
#include <vector>
#include <cstdio>

typedef long long ll;
int main() {
	ll n, b;
	std::cin >> n >> b;
	std::vector<ll> s;
	int q = 0;
	int r = 0;
	while (n) {
		r = n % b;
		s.push_back(r);
		n /= b;
	}
	int len = s.size();
	int size = len / 2;
	len--;
	bool isP = true;
	for (int i = 0; i < size; i++) {
		if (s[i] != s[len - i]){
			isP = false;
			break;
		}
	}
	
	if (isP)
		printf("Yes\n");
	else
		printf("No\n");

	for (int i = len; i >= 0; i--) {
		if (i != len)
			std::cout << " ";
		std::cout <<s[i];
	}
	return 0;
}	
