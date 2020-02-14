#include <vector>
#include <cstdio>

const int maxsize = 80;

int main() {
	char A[80] = "";
	char B[80] = "";

	scanf("%s %s", A, B);
//	printf("%s %s", A, B);
	std::vector<bool> type(2 * maxsize, false);

	int i = 0;
	while (B[i] != '\0') {	
		auto x = B[i++];
		if ('a' <= x and x <= 'z')
			x = x - 'a' + 'A';	
		type[x - '0'] = true;
	}

	i = 0;
	while (A[i] != '\0') {	
		auto x = A[i++];
		if ('a' <= x and x<= 'z')
			x = x - 'a' + 'A';
		if (!type[x - '0']) {
			type[x - '0'] = true;
			printf("%c", x);
		}
	}

	return 0;
}

