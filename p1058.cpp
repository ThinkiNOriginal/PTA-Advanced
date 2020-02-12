#include <cstdio>



int main() {
	char A[30], B[30];
	scanf("%s %s", A, B);
	int Ag, As, Ak, Bg, Bs, Bk;
	sscanf(A, "%d.%d.%d", &Ag, &As, &Ak);
	sscanf(B, "%d.%d.%d", &Bg, &Bs, &Bk);

	int rkc = (Ak + Bk) / 29;
	int rk = (Ak + Bk) % 29;
	int rs = (As + Bs + rkc) % 17;
	int rsc = (As + Bs + rkc) / 17;
	int rg = (Ag + Bg + rsc);

	printf("%d.%d.%d", rg, rs, rk);
	return 0;
}
