#pragma once
#include <iostream>
#include "Catalog.h"
#include <algorithm>
class CatalogRO : public Catalog
{
public:
	void adaugaStudent(Student& student)override {
		if (student.getProgram() == "RO") {
			studenti.push_back(student);
		}
	}
	void afiseazaTot()override {
		for (auto& student : studenti) {
			student.afiseazaNote();
		}
	}

	void clasament()override {
		cout << "\n--- Clasament Catalog RO ---\n";

		vector<Student> copie = studenti;
		sort(copie.begin(), copie.end(), [](Student& a, Student& b) {
			return a.calculeazaMedie() > b.calculeazaMedie();
			});

		for (auto& s : copie)
			cout << s.getNume() << " - " << s.getNrMatricol() << " - " << s.calculeazaMedie() << "\n";

	}

	~CatalogRO() {
		cout << "Destructor CatalogRO\n";
	}
};

	