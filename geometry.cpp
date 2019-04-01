#include <iostream>
#include <math.h>
#include "geometry.h"

double calcDistance(const Point &pa, const Point &pb)
// const указывает, что содержимое не будет меняться
{
	return sqrt((pb.x - pa.x) * (pb.x - pa.x) + (pb.y - pa.y) * (pb.y - pa.y));
}

double calcAreaBySides(double a, double b, double c)
{
	double p2 = (a + b + c) / 2.0;
	// Не забываем проверить, что корень извлечется
	if (p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c)
		return 0.0;
	return sqrt(p2*(p2 - a)*(p2 - b)*(p2 - c));
}