#include "Math.h"
#include <string.h>
#include <stdarg.h>
#define _CRT_SECURE_NO_WARNINGS
int Math :: Add(int a, int b)
{
	return a + b;
}

 int Math :: Add(int a, int b, int c)
{
	return a + b + c;
}

 double Math::Add(double a, double b)
{
	return a + b;
}

 double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

 int Math::Mul(int a, int b)
{
	return a * b;
}
 int Math::Mul(int a, int b,int c)
{
	return a * b*c;

}
double Math::Mul(double a, double b)
{
	 return a * b;

}

double Math::Mul(double a, double b,double c)
{
	return a * b * c;


}

int Math::Add(int count, ...)
{
	va_list arg;
	va_start(arg, count);

	int s = 0;
	for (int i = 0;i < count;i++)
		s += va_arg(arg, int);
	
	va_end(arg);
	
	return s;

}

char* Math::Add(const char* a, const char* b)
{	
	if (a == nullptr || b == nullptr)
		return nullptr;
	int lena = strlen(a);
	int lenb = strlen(b);
	char* c = new char[lena + lenb + 1];

	strcpy(c, a);
	strcat(c, b);

	return c;
}