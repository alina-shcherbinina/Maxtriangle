#pragma once
#ifndef _GEOMETRY_H
#define _GEOMETRY_H

struct Point {
	double x, y;
};

struct Triangle
{
	Point vertexes[3]; // три вершины треугольника
	double area; // площадь треугольника (если нужно)
};

// Расстояние между двумя точками по их координатам
double calcDistance(const Point &pa, const Point &pb);
double calcAreaBySides(double a, double b, double c);
// Площадь треугольника по координатам точек
double calcAreaByPoints(Triangle& tr);

#endif