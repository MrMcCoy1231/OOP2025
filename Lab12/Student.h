#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Student
{
	string nume;
	string numarMatricol;
	string programInvatare;
	map <string, vector<float>> note;

public:

	Student(string nume, string numarMatricol, string programInvatare) : nume(nume), numarMatricol(numarMatricol), programInvatare(programInvatare) {}

	void adaugaNota(const string& disciplina, float nota) {
		note[disciplina].push_back(nota);
	}

	float calculeazaMedie() {
		float suma = 0;
		int count = 0;
		for (auto& entry : note) {
			for (float nota : entry.second) {
					suma += nota;
					count++;
			}

			return count > 0 ? suma / count : 0.0f;
		}


	}

	void afiseazaNote() {
		
		cout << "Student: " << nume << " (" << numarMatricol << "), Program: " << programInvatare << "\n";
		
		for (auto& entry : note) {
			
			cout << "  Materie: " << entry.first << " | Note: ";
			
			for (float n : entry.second) 
				cout << n << " ";

				cout << "\n";
		}
			cout << "  Medie generala: " << calculeazaMedie() << "\n";

	}

	string getNume(){ return nume; }
	string getNrMatricol(){ return numarMatricol; }
	string getProgram(){ return programInvatare; }

	map<string, vector<float>> getNote() {
		return note;
	}


};
