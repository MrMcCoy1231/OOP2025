#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
Sort::Sort(int nr, int mini, int maxi)
{
	srand(time(NULL));
	v = new int[nr];
	this->dimensiune_vector = nr;
	for (int i = 0;i < nr;i++)
		v[i] = mini + rand() % (maxi - mini + 1);

}

Sort::Sort() :v(new int[6] {1, 2, 3, 4, 5, 6})
{
	this->dimensiune_vector = 6;
}

Sort ::Sort(int* a, int nr)
{
	v = new int[nr];
	this->dimensiune_vector = nr;
	for (int i = 0;i < nr;i++)
		v[i] = a[i];
}

Sort::Sort(int count, ...)
{
	v = new int[count];
	this->dimensiune_vector = count;
	va_list arg;

	va_start(arg, count);

	for (int i = 0;i < count;i++)
		v[i] = va_arg(arg,int);

	va_end(arg);

}

Sort::Sort(char* c)
{
	v = new int[strlen(c)];
	int k = 0;
	for (int i = 0;i < strlen(c);i++)
	{
		
		int x = 0;
		while (c[i] != ',' || c[i]!=NULL)
		{
			
			x = x * 10 + (c[i] - '0');
			i++;
		}
		v[k++] = x;
	}
	this->dimensiune_vector = k;
}

void Sort::InsertSort(bool ascendent) {
	int n = this->dimensiune_vector;

		for (int i = 1; i < n; i++) 
		{
			int key = v[i];
			int j = i - 1;
			while (j >= 0 && ((ascendent && v[j] > key) || (!ascendent && v[j] < key))) {
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = key;
		}
	

}
int Sort :: partitie(int mini, int maxi, bool ascendent)
{
	int pivot = v[maxi];
	int i = mini - 1;

	for (int j = mini;j < maxi;j++)
	{
		if ((ascendent && v[j] < pivot) || (!ascendent && v[j] > pivot))
		{
			i++;
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}

	}
	int aux = v[i + 1];
	v[i + 1] = v[maxi];
	v[maxi] = aux;
	return i + 1;
}
void Sort :: QuickSort1(int mini, int maxi, bool ascendent)
{
	if (mini < maxi)
	{
		int pivot = partitie(mini, maxi, ascendent);
		QuickSort1(mini, pivot - 1, ascendent);
		QuickSort1(pivot + 1, maxi, ascendent);
	}
}
void Sort::QuickSort(bool ascendent)
{
	QuickSort1(0, dimensiune_vector - 1, ascendent);
}

void Sort :: BubbleSort(bool ascendent) {
	
	for (int i = 0; i < dimensiune_vector - 1; i++) 
	{
		for (int j = 0; j < dimensiune_vector - i - 1; j++) 
		{
			if ((ascendent && v[j] > v[j + 1]) || (!ascendent && v[j] < v[j + 1])) 
			{
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0;i < dimensiune_vector;i++)
		std::cout << v[i] << " ";
}
int Sort::GetElementsCount()
{
	return dimensiune_vector;
}
int Sort::GetElementFromIndex(int index)
{
	return v[index];
}

