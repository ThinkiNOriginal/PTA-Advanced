#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

struct Users {
	char name[11];
	char pwd[11];
};

int main() {
	int N;
	scanf("%d", &N);
	std::vector<Users> r;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		Users u;
		//char tname[11] = "";
		//char tpwd [11] = "";
		scanf("%s %s", u.name, u.pwd);
		bool change = false;
		int j = 0;
		while (u.pwd[j] != '\0') {
			auto& x = u.pwd[j];
			j++;
			switch(x) {
				case '1':
					x = '@';
					change = true;
					break;
				case '0':
					x = '%';
					change = true;
					break;
				case 'l':
					x = 'L';
					change = true;
					break;
				case 'O':
					x = 'o';
					change = true;
					break;
			}
		}
			
			if (change) {
				r.push_back(u);
				cnt++;
			}
		
	}
	int len = r.size();
	if (len) {
		printf("%d\n", len);
		for (int i = 0; i < len; i++)
			printf("%s %s\n", r[i].name, r[i].pwd);
	} else {
		if (N == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", N);
	}
	return 0;
}

			

