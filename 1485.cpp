#include <stdio.h>

typedef struct {
	int x, y;
} Pos;

int square(int x)
{
	return x*x;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int i, isSquare=0;
		int a, b, c;
		Pos pos[4];
		for(i=0; i<4; i++) {
			scanf("%d%d", &pos[i].x, &pos[i].y);
		}
	
		a = square(pos[0].x-pos[1].x)+square(pos[0].y-pos[1].y);
		b = square(pos[0].x-pos[2].x)+square(pos[0].y-pos[2].y);
		c = square(pos[0].x-pos[3].x)+square(pos[0].y-pos[3].y);

		if((a == b && c == a+b) || (a == c && b == a+c) || (b == c && a == b+c)) 
			isSquare = 1;
		printf("%d\n", isSquare);
	}

	return 0;
}

