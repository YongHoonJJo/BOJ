#include <stdio.h>

int main(void)
{
	int test, H, W, N;
	int y, x, temp;
	scanf("%d", &test);

	while(test--)
	{
		scanf("%d %d %d", &H, &W, &N);
		y = N%H;
		x = (N/H)+1;
		if(!y)
		{
			y = H;
			x--;
		}

		printf("%d", y);
		if(x < 10)
			printf("0");
		printf("%d\n", x);
	}

	return 0;
}
