#include "output.h"

using std::cout;
using std::left;
using std::setw;


void results(std::vector<Data> student, int countBy){
    if (countBy == 0){
        cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)";
        cout << "\n--------------------------------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < student.size(); i++){
            cout << left << setw(20) << student[i].name << setw(20) << student[i].surname << setw(20) << student[i].finalGradeMean << setw(20) << student[i].finalGradeMedian << std::endl;
        }
    }

    if (countBy == 1){
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)";
        cout << "\n------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < student.size(); i++){
            cout << left << setw(20) << student[i].name << setw(20) << student[i].surname << setw(20) << student[i].finalGradeMean << std::endl;
        }
    }

    if (countBy == 2){
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (med.)";
        cout << "\n------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < student.size(); i++){
            cout << left << setw(20) << student[i].name << setw(20) << student[i].surname << setw(20) << student[i].finalGradeMedian << std::endl;
        }
    }
}