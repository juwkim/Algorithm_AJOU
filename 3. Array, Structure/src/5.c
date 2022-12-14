#include <stdio.h>
#include <stdlib.h>
#define PHI 3.14
#define area(r) (PHI) * (r) * (r)

typedef struct {
	float x;
	float y;
} point;

typedef struct {
	point center;
	float radius;
} circle;


int main()
{
	circle* one = (circle*)malloc(sizeof(circle));
	if (one == NULL)
		return 1;

	one->center.x = 1.24;
	one->center.y = 3.82;
	one->radius = 4.93;


	printf("�� �߽���ǥ<%.2f, %.2f>, ������: %.2f\n", one->center.x, one->center.y, one->radius);
	printf("������: %.2f\n", area(one->radius));
	return 0;
}