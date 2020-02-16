#include <cstdio>
#include <vector>
#include <iostream>


const int maxsize = 100010;



int main() {

	int add1, add2, N;
	scanf("%d %d %d", &add1, &add2, &N);
	std::vector<int> v(maxsize, -2);

    if (add1 == add2) {
        printf("%05d", add1);
        return 0;
    }

	while (N--) {
		int tmpadd;
		char c;
		int next;
		scanf("%d %c %d", &tmpadd, &c, &next);
		v[tmpadd] = next;
	}

	int len1 = 0;
	int p1   = add1;
	while (p1 != -1) {
		p1 = v[p1];
		len1++;
	}

	int len2 = 0;
	int p2   = add2;
	while (p2 != -1) {
		p2 = v[p2];
		len2++;
	}

	int diff = len1 - len2;
	if (diff > 0) {
		while (diff > 0) {
			add1 = v[add1];
			diff--;
		}
	} else if(diff < 0) {
		diff = -diff;
		while (diff > 0) {
			add2 = v[add2];
			diff--;
		}
	}

	while (add1 != add2) {
		add1 = v[add1];
		add2 = v[add2];
	}




	if (add1 >= 0)
		printf("%05d", add1);
	else
		printf("-1");

	return 0;

}
