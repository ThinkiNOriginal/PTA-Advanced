#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	
	int N;
	scanf("%d", &N);
	
	int tmp;
	
	std::	vector<int> vp;
	std::vector<int> vn;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp < 0)
			vn.push_back(tmp);
		else if (tmp > 0)
			vp.push_back(tmp);
	}

	scanf("%d", &N);
	std::	vector<int> rp;
	std::vector<int> rn;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp < 0)
			rn.push_back(tmp);
		else if (tmp > 0)
			rp.push_back(tmp);
	}

	sort(vn.begin(), vn.end());
	sort(vp.begin(), vp.end());
	sort(rp.begin(), rp.end());
	sort(rn.begin(), rn.end());


	int len1 = vp.size() - 1;
	int len2 = rp.size() - 1;
	long long res = 0;	
	while (len1 >= 0 and len2 >= 0) {
		res += vp[len1] * rp[len2];
		len1--;
		len2--;
	}

	len1 = vn.size();
	len2 = rn.size();

	int i = 0;
	int j = 0;
	while (i < len1 and j < len2) {
		res += vn[i] * rn[j];
		i++;
		j++;
	}



	printf("%lld", res);
	return 0;
}












	
	


