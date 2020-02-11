#include <cstdio>
#include <vector>
#include <iostream>

int main() {

	long N;
	std::cin >> N;
	std::vector<long> v(N);

	for (int i = 0; i < N; i++) {
		scanf("%ld", &v[i]);
	}

	std::cin >> N;
	std::vector<long> r(N);
	
	for (int i = 0; i < N; i++)
		scanf("%ld", &r[i]);

	int len1 = v.size();
	int len2 = r.size();
	//int mid = (v.size() + r.size() - 1) / 2;
	int mid = (len1 + len2 - 1) / 2;
	int i = 0;
	int j = 0;
	int target = -1;
	bool choice = true;
	while (mid >= 0 and i < len1 and j < len2) {
		if (v[i] < r[j]) {
			target = i;
			choice = true;
			i++;
		}
		else {
			target = j;
			choice = false;
			j++;
		}
		mid--;
	}

	while (mid >= 0 and i <len1) {
		target = i;
		choice = true;
		i++;
		mid--;
	}

	while (mid >= 0 and j < len2) {
		target = j;
		choice = false;
		j++;
		mid--;
	}

	if (choice)
		printf("%ld", v[target]);
	else
		printf("%ld", r[target]);

	return 0;
}










