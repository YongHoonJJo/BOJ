#include <stdio.h>

int main()
{
	int i, n;
	int cup[4]={0, 1};

	scanf("%d", &n);
	while(n--) {
		int a, b, t;
		scanf("%d%d", &a, &b);
		t = cup[a];
		cup[a] = cup[b];
		cup[b] = t;
	}

	for(i=1; i<4; i++)
		if(cup[i])
			printf("%d\n", i);

	return 0;
}
