#include <iostream>
#include <locale.h>
#include "geometry.h"
#include "file.h"
#include "search.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	if (argc < 3)
	{
		cout << "Запуск: Triangles.exe inf.txt outf.txt" << endl;
		return -1;
	}
	const char* inFileName = argv[1]; // Имя входного файла
	const char* outFileName = argv[2]; // Имя выходного файла
	int pointNum = countPoints(inFileName);

	if (pointNum < 0) {
		cout << "Входной файл не существует" << endl;
		return -2;
	}

	else if (pointNum < 4)
	{
		cout << "Входной файл слишком мал" << endl;
		return -3;
	}

	Point *pointArray = new Point[pointNum];
	if (!readPoints(inFileName, pointArray, pointNum))
	{
		cout << "Неизвестная ошибка при вводе точек " << endl;
		return -3;
	}
	const int maxTrNum = 3;
	Triangle trArray[maxTrNum];
	searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum);
	if (writeTriangles(outFileName, trArray, maxTrNum) == false)
	{
		cout << "Не удалось записать результат" << endl;
		return -4;
	}
	cout << "Программа успешно завершена" << endl;
	delete[] pointArray;
	return 0;
}

istream& operator >>(istream& in, Point& p)
{
	in >> p.x >> p.y;
	// Результатом должен быть сам поток
	// Это позволяет команды типа cin>>a>>b>>c
	return in;
}

ostream& operator <<(ostream& out,
	const Point& p)
{
	out << "(" << p.x << " " << p.y << ")";
	return out;
}

ostream& operator <<(ostream& out,
	const Triangle& tr)
{
	out << "A=" << tr.vertexes[0] <<
		" B=" << tr.vertexes[1] <<
		" C=" << tr.vertexes[2] <<
		" area=" << tr.area;
	return out;
}

