#pragma once
#include "Catalog.h"
class CatalogEN : public Catalog {
public:
	void adaugaStudent(Student& student) override {
		if (student.getProgram() == "EN")
			studenti.push_back(student);
	}

	void afiseazaTot() override {
		cout << "\n--- Catalog EN ---\n";
		for (auto& s : studenti)
			s.afiseazaNote();
	}

	void clasament() override {
		cout << "\n--- Clasament Catalog EN ---\n";
		vector<Student> copie = studenti;
		sort(copie.begin(), copie.end(), [](Student& a, Student& b) {
			return a.calculeazaMedie() > b.calculeazaMedie();
			});
		for (auto& s : copie)
			cout << s.getNume() << " - Medie: " << s.calculeazaMedie() << "\n";
	}

	~CatalogEN() {
		cout << "Destructor CatalogEN\n";
	}
};