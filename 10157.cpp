#include <stdio.h>

int a[1005][1005];
int C, R, K;

void Down(int r, int c, int cnt);
void Right(int r, int c, int cnt);
void Up(int r, int c, int cnt);
void Left(int r, int c, int cnt);

int main()
{
	scanf("%d%d%d", &C, &R, &K);

	if(C*R < K) puts("0");
	else Down(1, 1, 0);				
	return 0;
}

void Down(int r, int c, int cnt)
{
	int i;
	for(i=r; i<=R; i++) {
		if(!a[i][c]) { 
			a[i][c] = ++cnt;
			if(K == cnt) {
				printf("%d %d\n", c, i);
				return ;
			}
		}
		else break;
	}
	Right(--i, c+1, cnt);
}

void Right(int r, int c, int cnt)
{
	int i;
	for(i=c; i<=C; i++) {
		if(!a[r][i]) {
			a[r][i] = ++cnt;
			if(K == cnt) {
				printf("%d %d\n", i, r);
				return ;
			}
		}
		else break;
	}
	Up(r-1, --i, cnt);
}

void Up(int r, int c, int cnt)
{
	int i;
	for(i=r; i>=1; i--) {
		if(!a[i][c]) { 
			a[i][c] = ++cnt;
			if(K == cnt) {
				printf("%d %d\n", c, i);
				return ;
			}
		}
		else break;
	}
	Left(++i, c-1, cnt);
}

void Left(int r, int c, int cnt)
{
	int i;
	for(i=c; i>=1; i--) {
		if(!a[r][i]) {
			a[r][i] = ++cnt;
			if(K == cnt) {
				printf("%d %d\n", i, r);
				return ;
			}
		}
		else break;
	}
	Down(r+1, ++i, cnt);
}
