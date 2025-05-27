#include <iostream>
#include "Catalog.h"
#include "Student.h"
#include "CatalogRO.h"
#include "CatalogEN.h"

using namespace std;

int main() {
CatalogRO catalogRO;
CatalogEN catalogEN;

Student s1("Andrei Popescu", "1234", "RO");
s1.adaugaNota("Matematica", 9.5);
s1.adaugaNota("Matematica", 10);
s1.adaugaNota("Romana", 8.5);
catalogRO.adaugaStudent(s1);

Student s2("John Smith", "5678", "EN");
s2.adaugaNota("Mathematics", 9.0);
s2.adaugaNota("English", 10.0);
s2.adaugaNota("Computer Science", 8.0);
catalogEN.adaugaStudent(s2);

Student s3("Ioana Ionescu", "2345", "RO");
s3.adaugaNota("Matematica", 10);
s3.adaugaNota("Romana", 9);
s3.adaugaNota("Informatica", 10);
catalogRO.adaugaStudent(s3);

Student s4("Michael Jackson", "5378", "EN");
s4.adaugaNota("Mathematics", 2.0);
s4.adaugaNota("English", 5.0);
s4.adaugaNota("Computer Science", 8.0);
catalogEN.adaugaStudent(s4);

catalogRO.afiseazaTot();
catalogRO.clasament();

catalogEN.afiseazaTot();
catalogEN.clasament();

return 0;
}