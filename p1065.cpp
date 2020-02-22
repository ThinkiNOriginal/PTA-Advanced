#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		printf("Case #%d: ", i + 1);
		if (a < 0 and b < 0 and a + b >= 0) {
			printf("false\n");
		} else if(a + b > c) {
			printf("true\n");
		} else if (a > 0 and b > 0 and a + b < 0) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	}
	return 0;
}
			
			
