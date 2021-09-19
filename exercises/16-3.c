#include <math.h>
#include <stdio.h>

#define PI (4 * atan(1))
#define DEG_TO_RAD(X) ((X) / (180 / PI))
#define RAD_TO_DEG(X) ((X) * (180 / PI))

typedef struct {
	double magnitude;
	double angle;
} Polar;

typedef struct {
	double x;
	double y;
} Rect;

Rect polar_to_rect(Polar p_cords)
{
	Rect r_cords;

	r_cords.x = p_cords.magnitude * cos(DEG_TO_RAD(p_cords.angle));
	r_cords.y = p_cords.magnitude * sin(DEG_TO_RAD(p_cords.angle));

	return r_cords;
}

int main(void)
{
	Polar p_cords;
	Rect r_cords;

	printf("Enter the magnitude and angle (in degrees) of a vector (q to quit): ");
	while (scanf("%lf%lf", &p_cords.magnitude, &p_cords.angle) == 2) {
		p_cords.angle = p_cords.angle;
		r_cords = polar_to_rect(p_cords);
		printf("Rectangular coordinates: x = %.4lf, y = %.4lf\n", r_cords.x, r_cords.y);
		printf("Enter the magnitude and angle of the next vector (q to quit): ");
	}

	return 0;
}
