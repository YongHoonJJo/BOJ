#include <stdio.h>

typedef struct pos {
	int r, c;
} Pos;

Pos p[500];

int d[500][500];

int matrix(int f, int r)
{
	int i, ans=0x7fffffff;
	if(f == r) return 0;
	if(d[f][r]) return d[f][r];

	for(i=f; i<r; i++) {
		int a = matrix(f, i);
		int b = matrix(i+1, r);
		int tmp = a + b + p[f].r * p[i].c * p[r].c;
		ans =  ans > tmp ? tmp : ans;
	}
	return d[f][r] = ans;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	
	for(i=0; i<n; i++) 
		scanf("%d%d", &p[i].r, &p[i].c);  

	printf("%d\n", matrix(0, n-1));
	return 0;
}
