#include "comparator.h"
#include "final.h"
#include "check.h"

#include "check.cpp"
#include "comparator.cpp"
#include "final.cpp"

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {

    vector<Data> student;
    Data temporary;

    int readData;
    int studentCount;

    cout << "Pasirinkite:\n(1) duomenis ivesti;\n(2) duomenis nuskaityti is kursiokai.txt failo: ";
    checkChoice(readData);

    if (readData == 1){
        int countBy;
        int doRandom;
        
        cout << "\nPasirinkite:\n(1) skaiciuoti pagal namu darbu vidurki;\n(2) skaiciuoti pagal namu darbu mediana: ";
        checkChoice(countBy);
        cout << "\nAr norite egzamino ir namu darbo pazymius generuoti atsitiktinai?\n(1) taip;\n(2) ne: ";
        checkChoice(doRandom);
        cout << "\nIveskite studentu skaiciu: ";
        checkStudentCount(studentCount);
        cout << "\n";
        
        if (doRandom == 2){
            float temp;
            for (int i = 0; i < studentCount; i++){
                cout << "\nIveskite studento varda, pavarde, egzamino ivertinima ir namu darbus (spauskite enter): ";
                cin >> temporary.name >> temporary.surname;
                checkGrade(temporary.exam);
                while (cin.peek() != '\n'){
                    checkGrade(temp);
                    temporary.homework.push_back(temp);
                }
                
                if (countBy == 1){
                temporary.finalGradeMean = finalByMean(temporary);
                }

                if (countBy == 2){
                    temporary.finalGradeMedian = finalByMedian(temporary);
                }
                
                student.push_back(temporary);
                temporary.homework.clear();
            }
        }

        if (doRandom == 1){
            for (int i = 0; i < studentCount; i++){
            cout << "\nIveskite studento varda ir pavarde: ";
            cin >> temporary.name >> temporary.surname;
            srand(time(0));
            temporary.exam = rand() % 10 + 1;
            for (int j = 0; j < rand() % 20 + 1; j++){
                temporary.homework.push_back(rand() % 10 + 1);
            }

            if (countBy == 1){
                temporary.finalGradeMean = finalByMean(temporary);
            }

            if (countBy == 2){
                temporary.finalGradeMedian = finalByMedian(temporary);
            }

            student.push_back(temporary);
            temporary.homework.clear();
            }
        }

        cout << "\n\n";
        
        if (countBy == 1){
            cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (vid.)";
            cout << "\n------------------------------------------------------\n";
            cout.precision(3);
            for (int i = 0; i < studentCount; i++){
                cout << std::left << std::setw(20) << student[i].name << std::setw(20) << student[i].surname << std::setw(20) << student[i].finalGradeMean << "\n";
            }
        }

        if (countBy == 2){
            cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (med.)";
            cout << "\n------------------------------------------------------\n";
            cout.precision(3);
            for (int i = 0; i < studentCount; i++){
                cout << std::left << std::setw(20) << student[i].name << std::setw(20) << student[i].surname << std::setw(20) << student[i].finalGradeMedian << "\n";
            }
        }

    }



    if (readData == 2){

        std::ifstream dataFile("kursiokai.txt");
        string firstLine;
        getline(dataFile, firstLine);
        studentCount = 0;

        float temp;

        while (!dataFile.eof()){
            dataFile >> temporary.name >> temporary.surname;
            for (int i = 0; i < 5; i++){
                dataFile >> temp;
                temporary.homework.push_back(temp);
            }
            dataFile >> temporary.exam;
            temporary.finalGradeMean = finalByMean(temporary);
            temporary.finalGradeMedian = finalByMedian(temporary);
        
            student.push_back(temporary);
            temporary.homework.clear();
            studentCount++;
        }

        dataFile.close();

        sort(student.begin(), student.end(), compareNames);

        cout << "\n\n";
        cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (vid.)" << std::setw(20) << "Galutinis (med.)";
        cout << "\n--------------------------------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < studentCount; i++){
            cout << std::left << std::setw(20) << student[i].name << std::setw(20) << student[i].surname << std::setw(20) << student[i].finalGradeMean << std::setw(20) << student[i].finalGradeMedian << "\n";
        }
    }

        return 0;
}
