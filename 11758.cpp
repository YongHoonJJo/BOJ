#include <stdio.h>

int cross(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	int i, x[3], y[3];
	int ccw;

	for(i=0; i<3; i++)
		scanf("%d%d", x+i, y+i);

	ccw = cross(x[1]-x[0], y[1]-y[0], x[2]-x[0], y[2]-y[0]);

	if(ccw > 0) puts("1");
	else ccw == 0 ? puts("0") : puts("-1");
	return 0;
}
