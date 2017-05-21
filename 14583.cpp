#include <stdio.h>
#include <math.h>
#define PI	3.141592

int main()
{
	double r, c;
	double x, r1, c1, theta;
	scanf("%lf%lf", &r, &c);

	theta = atan(c/r);
	theta /= 2;

	x = r * tan(theta);
	
	c1 = c - x;
	r1 = sqrt(r*r+x*x);

	c1 = c1 * sin(PI/2-theta);

	printf("%.2lf %.2lf\n", r1/2, c1);
	return 0;
}
