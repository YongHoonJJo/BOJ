#include <stdio.h>

int A, B, ans;
int a[200001], b[200002];
bool check[100000001];

int main()
{
	int i;
	scanf("%d%d", &A, &B);

	for(i=0; i<A; i++) {
		scanf("%d", a+i);
		check[a[i]]=1;
	}

	for(i=0; i<B; i++) {
		scanf("%d", b+i);
		if(check[b[i]])
			ans+=2;
	}

	printf("%d\n", A+B-ans);
	return 0;
}
