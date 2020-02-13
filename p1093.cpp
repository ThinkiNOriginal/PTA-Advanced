#include <cstdio>
#include <vector>

const int maxsize = 100007;

int main() {

	char str[maxsize] = "";
	std::vector<int> cntP(maxsize, 0);
	//std::vector<int> cntT(maxsize, 0);
	scanf("%s", str);

	int ps = 0;
	for (int i = 1; i < maxsize; i++) {
		if (str[i] == 'A')
			cntP[i] = ps;
		else if (str[i] == 'P')
			ps++;
	}

	int ts = 0;
	long long pats = 0;
	for (int i = maxsize - 1; i >= 0; i--) {
		auto x = str[i];
		if (x == 'T')
			ts++;
		else if (x == 'A') {
			//cntT[i] = ts;
			pats += ts * cntP[i];
		}
	}


	printf("%lld", pats % 1000000007);
	return 0;
}
		
			
