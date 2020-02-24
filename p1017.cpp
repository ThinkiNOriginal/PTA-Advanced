#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int h_to_m = 60;
const int m_to_s = 60;
const int h_to_s = h_to_m * m_to_s;
const int maxm   = 25 * h_to_s;

struct Custom {
	int arrive;
	int service;
};

bool cmp (Custom& c1, Custom& c2) {
	return c1.arrive < c2.arrive;
}

int main () {
	freopen("case1", "r", stdin);
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> w(K, 8 * h_to_s);
	vector<Custom> v(N);
	int total_wait = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int h, m, s, service;
		scanf("%d:%d:%d %d", &h, &m, &s, &service);
		int arrive = h * h_to_s + m * m_to_s + s;
		service = min(60, service);	
		v[i].arrive = arrive;
		v[i].service = service;
	}
	sort(v.begin(), v.end(), cmp);
		
	for (int i = 0; i < N; i++) {

		if (v[i].arrive > 17 * h_to_s) {
			continue;
		}

		int target = -1;
		int earliest = maxm;
		for (int j = 0; j < K; j++) {
			if (w[j] < earliest) {
				earliest = w[j];
				target = j;
			}
		}
		if (earliest > 17 * h_to_s)
			break;
		

		if (v[i].arrive < w[target]) {
			total_wait += w[target] - v[i].arrive;
			w[target] += v[i].service * m_to_s;
		} else {
			w[target] = v[i].arrive + v[i].service * m_to_s;
		}
		cnt++;
	}

	printf("%.1f", float(total_wait) / cnt / 60);
}

		
		


