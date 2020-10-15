#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct Data {
    string name, surname;
    float exam, homework[20], finalGrade, finalGradeMean, finalGradeMedian;
};


bool compareNames(Data firstStudent, Data secondStudent){
    
    if (firstStudent.name != secondStudent.name){
        return firstStudent.name < secondStudent.name;
    }

    else{
        return firstStudent.surname < secondStudent.surname;
    }
}

float countMean(float Array[], int size){

    float sum = 0;

    for (int i = 0; i < size; i++){
        sum += Array[i];
    }

    return sum / (size * 1.0);
}

float findMedian(float Array[], int size){

    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (Array[i] > Array[j]){
                std::swap(Array[i], Array[j]);
            }
        }
    }

    if (size % 2 == 0){
        return (Array[size / 2] + Array[size / 2 - 1]) * 1.0 / 2;
    }
    
    else {
        return Array[size / 2];
    }
}

float countFinal(Data student, int countBy, int countHomework){
    
    if (countBy == 1){
        return countMean(student.homework, countHomework) * 0.4 + student.exam * 0.6;
    }

    if (countBy == 2){
        return findMedian(student.homework, countHomework) * 0.4 + student.exam * 0.6;
    }

}

int main() {

    int readData;
    int studentCount;

    cout << "Pasirinkite:\n(1) duomenis ivesti;\n(2) duomenis nuskaityti is kursiokai.txt failo: ";
    cin >> readData;

    if (readData == 1){
        int countBy;
        int doRandom;
        
        cout << "\nPasirinkite:\n(1) skaiciuoti pagal namu darbu vidurki;\n(2) skaiciuoti pagal namu darbu mediana: ";
        cin >> countBy;
        cout << "\nStudentu skaicius: ";
        cin >> studentCount;
        cout << "\nAr norite egzamino ir namu darbo pazymius generuoti atsitiktinai?\n(1) Taip;\n(2) ne: ";
        cin >> doRandom;
        cout << "\n";

        vector<Data> student;
        student.reserve(studentCount);
        Data temporary;
        int countHomework;
        
        if (doRandom == 2){
            for (int i = 0; i < studentCount; i++){
                cout << "Iveskite studento varda, pavarde, egzamino ivertinima ir namu darbus (uzbaigimui iveskite 0): ";
                cin >> temporary.name >> temporary.surname >> temporary.exam;
                countHomework = 0;
                cin >> temporary.homework[countHomework];
                while (temporary.homework[countHomework] != 0){
                    countHomework++;
                    cin >> temporary.homework[countHomework];
                }
                temporary.finalGrade = countFinal(temporary, countBy, countHomework);
                student.push_back(temporary);
            }
        }

        if (doRandom == 1){
            for (int i = 0; i < studentCount; i++){
            cout << "Iveskite studento varda ir pavarde: ";
            cin >> temporary.name >> temporary.surname;
            srand(time(0));
            temporary.exam = rand() % 10 + 1;
            countHomework = rand() % 21;
            if (countHomework == 0){
                student[i].homework[0] = 0;
                countHomework = 1;
            }
            for (int j = 0; j < countHomework; j++){
                temporary.homework[j] = rand() % 10 + 1;
            }
            temporary.finalGrade = countFinal(temporary, countBy, countHomework);
            student.push_back(temporary);
            }
        }

        cout << "\n\n";
        
        if (countBy == 1){
            cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (vid.)";
        }

        if (countBy == 2){
            cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (med.)";
        }

        cout << "\n------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < studentCount; i++){
            cout << std::left << std::setw(20) << student[i].name << std::setw(20) << student[i].surname << std::setw(20) << student[i].finalGrade << "\n";
        }

    }



    if (readData == 2){

        vector<Data> student;
        Data temporary;

        std::ifstream dataFile("kursiokai.txt");
        string firstLine;
        getline(dataFile, firstLine);
        studentCount = 0;

        while (!dataFile.eof()){
            dataFile >> temporary.name >> temporary.surname;
            for (int i = 0; i < 5; i++){
                dataFile >> temporary.homework[i];
            }
            dataFile >> temporary.exam;
            temporary.finalGradeMean = countFinal(temporary, 1, 5);
            temporary.finalGradeMedian = countFinal(temporary, 2, 5);
            student.push_back(temporary);
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
