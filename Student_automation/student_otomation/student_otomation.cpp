#include <iostream>
#include <fstream>
using namespace std;

// C++ OOP Student otomation:

class StudentOtomation {
private:
	string Name;
	string Surname;
	int Which_grade;
	string Gender;
	int Average;
public:
	// Encapsulation
	void setName(string Name) { this->Name = Name; }
	void setSurname(string Surname) { this->Surname = Surname; }
	void setWhich_grade(int Which_grade) { this->Which_grade = Which_grade; }
	void setGender(string Gender) { this->Gender = Gender; }
	void setAverage(int Average) { this->Average = Average; }

	string getName() { return Name; }
	string getSurname() { return Surname; }
	int getWhich_grade() { return Which_grade; }
	string getGender() { return Gender; }
	int getAverage() { return Average; }

	void listining(StudentOtomation[]);
};

void StudentOtomation::listining(StudentOtomation std[])
{
	cout << "Student information listed..." << endl;
	for (int i = 0; i < 2; i++) {
		cout << "-----------------------------------" << endl;
		cout << "Name          : " << std[i].getName() << endl;
		cout << "Surname       :  " << std[i].getSurname() << endl;
		cout << "Which Grade   :  " << std[i].getWhich_grade() << endl;
		cout << "Gender        :  " << std[i].getGender() << endl;
		cout << "Average       :  " << std[i].getAverage() << endl;
	}
}

void arrangement(StudentOtomation std[]) {

	StudentOtomation temp;

	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 1; j++) {
			if (std[j].getName().compare(std[j + 1].getName()) > 0) {
				temp = std[j];
				std[j] = std[j + 1];
				std[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		cout << "-------------------------" << endl;
		cout << "Name          : " << std[i].getName() << endl;
		cout << "Surname       :  " << std[i].getSurname() << endl;
		cout << "Which Grade   :  " << std[i].getWhich_grade() << endl;
		cout << "Gender        :  " << std[i].getGender() << endl;
		cout << "Average       :  " << std[i].getAverage() << endl;
	}
}

void Searching(StudentOtomation std[]) {
	bool result = false;
	string nema;
	cout << "Enter wanted student  :" << endl;
	cin >> nema;
	StudentOtomation temp;

	for (int i = 0; i < 2; i++) {
		if (std[i].getName().compare(nema) == 0 ){
			temp = std[i];
			result = true;
			break;
		}
	}
	if (result) {
		cout << "--------The Student Information : " << endl;
		cout << "Name          : " << temp.getName() << endl;
		cout << "Surname       :  " << temp.getSurname() << endl;
		cout << "Which Grade   :  " << temp.getWhich_grade() << endl;
		cout << "Gender        :  " << temp.getGender() << endl;
		cout << "Average       :  " << temp.getAverage() << endl;
	}
	else
	{
		cout << "There is no student sought." <<  endl;
	}
}

void writtenFile(StudentOtomation std[]) {
	for (int i = 0; i < 2; i++) {
		ofstream outFile("student_otomation.txt");
		if ( !outFile) {
			cout << "File not found.." << endl;
			exit(1);
		}
		for (int i = 0; i < 2; i++) {
			outFile << "--------------------------------\n" << endl;
			outFile << "Name           : " << std[i].getName() << endl;
			outFile << "Surname        : " << std[i].getSurname() << endl;
			outFile << "Which_Grade    : " << std[i].getWhich_grade() << endl;
			outFile << "Gender         : " << std[i].getGender() << endl;
			outFile << "Average        : " << std[i].getAverage() << endl;
		}
	}
}

void HighestScore(StudentOtomation std[]) {

	int average = 0;
	StudentOtomation temp;

	for (int i = 0; i < 2; i++) {

		if (average < std[i].getAverage()) {
			temp = std[i];
			average = std[i].getAverage();
		}
	}
		cout << "--------The scoring student : " << endl;
		cout << "Name          : " << temp.getName() << endl;
		cout << "Surname       :  " << temp.getSurname() << endl;
		cout << "Which Grade   :  " << temp.getWhich_grade() << endl;
		cout << "Gender        :  " << temp.getGender() << endl;
		cout << "Average       :  " << temp.getAverage() << endl;
}

int main() {
	StudentOtomation std[3];

	string Name;
	string Surname;
	int Which_grade;
	string Gender;
	int Average;

	cout << "Student Information : " << endl;
	for (int i = 0; i < 2; i++) {
		cout << "-----------------------------------" << endl;
		cout << "Name          : "; cin >> Name;
		cout << "Surname       : "; cin >> Surname;
		cout << "Which Grade   : "; cin >> Which_grade;
		cout << "Gender        : "; cin >> Gender;
		cout << "Average       : "; cin >> Average;

		std[i].setName(Name);
		std[i].setSurname(Surname);
		std[i].setWhich_grade(Which_grade);
		std[i].setGender(Gender);
		std[i].setAverage(Average);

		writtenFile(std);
		cout << "Written to file..." << endl;
	}

	system("cls");

	cout << "Sorted by Name Student Informations:" << endl;

	arrangement(std);

	cout << "----------------------------------------" << endl;

	HighestScore(std);

	cout << "----------------------------------------" << endl;

	Searching(std);

	return 0;
}