#include <stdio.h>

int RSP(char k)
{
	if(k == 'R') return 1;
	if(k == 'P') return 2;
	return 3;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n, W=0, L=0;
		scanf("%d", &n);

		while(n--) {
			char A, B;
			int a, b;
			scanf(" %c %c", &A, &B);
			a = RSP(A);
			b = RSP(B);

			if(a-b == 1 || a-b == -2) W++;
			else if(a == b) ;
			else L++;
		}
		if(W == L) puts("TIE");
		else {
			printf("Player ");
			W > L ? puts("1") : puts("2");
		}
	}

	return 0;
}
