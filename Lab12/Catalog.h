#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
#include <algorithm>
using namespace std;

class Catalog
{
public:
	vector<Student> studenti;

	virtual void adaugaStudent(Student& student) = 0;
	virtual void afiseazaTot() = 0;
	virtual void clasament() = 0;
	virtual ~Catalog() {}
};

