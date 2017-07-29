#include <stdio.h>

int sdk[9][9], ck[10];
int q[81], size;

int check(int i, int j, int k)
{
	int a;
	for(a=0; a<=9; a++)
		ck[a] = 0;

	for(a=0; a<9; a++)
		ck[sdk[i][a]] = 1;

	if(ck[k] != 0)
		return 0;

	for(a=0; a<=9; a++)
		ck[a] = 0;

	for(a=0; a<9; a++)
		ck[sdk[a][j]] = 1;

	if(ck[k] != 0)
		return 0;
	else
		return 1;
}

int ck_sq(int i, int j, int k)
{
	int a, b;
	for(a=0; a<=9; a++)
		ck[a] = 0;

	a = (i/3) * 3;
	b = (j/3) * 3;

	for(i=a; i<a+3; i++)
		for(j=b; j<b+3; j++)
			ck[sdk[i][j]] = 1;

	if(ck[k] != 0)
		return 0;
	else
		return 1;
}

void print()
{
	int i, j;
	for(i=0; i<9; i++) {
		for(j=0; j<9; j++) 
			printf("%d ", sdk[i][j]);
		puts("");
	}
}

void go(int idx)
{
	int i, j, k;
	static int ok;
	if(!ok && idx == size) {
		ok = 1;
		print();
		return ;
	}

	i = q[idx]/10;
	j = q[idx]%10;

	for(k=1; !ok && k<=9; k++) {
		if(!ok && check(i, j, k) && ck_sq(i, j, k)) {
			sdk[i][j] = k;
			go(idx+1);
			sdk[i][j] = 0;
		}
	}
}

int main()
{
	int i, j;
	for(i=0; i<9; i++) {
		for(j=0; j<9; j++) {
			scanf("%d", &sdk[i][j]);
			if(sdk[i][j] == 0)
				q[size++] = i*10 + j;
		}
	}

	go(0); 

	return 0;
}
