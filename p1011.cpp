#include <iostream>
#include <cstdio>
#include <vector>


int main() {

	double r1 = -1;
	int    s1 = -1;
	double r2 = -1;
	int    s2 = -1;
	double r3 = -1;
	int    s3 = -1;
	
	for (int i = 0; i < 3; i++){
		double tmp;
		std::cin >> tmp;
		if (tmp > r1){
			r1 = tmp;
			s1 = i;
		}
	}

for (int i = 0; i < 3; i++){
		double tmp;
		std::cin >> tmp;
		if (tmp > r2){
			r2 = tmp;
			s2 = i;
		}
	}

for (int i = 0; i < 3; i++){
		double tmp;
		std::cin >> tmp;
		if (tmp > r3){
			r3 = tmp;
			s3 = i;
		}
	}

	double res = (r1 * r2 * r3 * 0.65 - 1) * 2;
	std::vector<char> v{'W', 'T', 'L'};
	printf("%c %c %c %.2lf", v[s1], v[s2], v[s3], res);

	return 0;
}
