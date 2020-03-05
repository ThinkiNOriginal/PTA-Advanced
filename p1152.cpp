#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	if (n < 2)
		return false;
	
	int len = sqrt(n);
	for (int i = 2; i <= len; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	string str;
	cin >> str;
	
	for (int i = 0; i <= N - M; i++) {
		string temp = str.substr(i, M);
		auto num = stoi(temp);
		if (isPrime(num)) {
			cout << temp << endl;
			return 0;
		}
	}

	cout << "404" << endl;
	return 0;
}

			

