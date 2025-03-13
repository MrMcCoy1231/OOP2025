#include "Canvas2.h"
#include <stdarg.h>
#include <iostream>
Canvas2::Canvas2(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;

	mat = new char* [lines];
	for (int i = 0;i < lines;i++)
	{
		mat[i] = new char [columns];
		for (int j = 0;j < columns;j++)
			mat[i][j] = ' ';

	}
}

void Canvas2::set_pixel(int x, int y, char value)
{
	mat[x][y] = value;
}

void Canvas2::set_pixels(int count, ...)
{
	va_list arg;
	va_start(arg, count);

	for (int i = 0;i < count;i++)
	{
		int x = va_arg(arg, int);
		int y = va_arg(arg, int);
		int value = va_arg(arg, int);
		set_pixel(x, y, value);
	}
	
	va_end(arg);
}

void Canvas2::clear()
{
	for (int i = 0;i < lines;i++)
		for (int j = 0;j < columns;j++)
			mat[i][j] = ' ';
}

void Canvas2::print() const
{
	for (int i = 0;i < lines;i++)
	{
		for (int j = 0;j < columns;j++)
			std :: cout << mat[i][j];
		std :: cout << '\n';
	}

}