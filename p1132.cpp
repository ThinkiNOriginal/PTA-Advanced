#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	// freopen("case1", "r", stdin);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		int len = temp.size();
		string strA = temp.substr(0, len / 2);
		string strB = temp.substr(len / 2);
		int A = stoi(strA);
		int B = stoi(strB);
		int Z = stoi(temp);
        if (A == 0 or B == 0) {
            printf("No\n");
        }
		else if (Z % (A * B) == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
