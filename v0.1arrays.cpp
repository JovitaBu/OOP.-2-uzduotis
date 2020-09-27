#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct Data {
    string name, surname;
    float exam, homework[20], finalGrade;
};

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

int main() {

    int countBy;
    int studentCount;
    int doRandom;
    cout << "Pasirinkite:\n(1) skaiciuoti pagal namu darbu vidurki;\n(2) skaiciuoti pagal namu darbu mediana: ";
    cin >> countBy;
    cout << "Studentu skaicius: ";
    cin >> studentCount;
    cout<< "Ar norite egzamino ir namu darbo pazymius generuoti atsitiktinai? (1) Taip; (2) ne: ";
    cin >> doRandom;
    
    
    Data student[studentCount];
    int sum;
    int countHomework;

    if (doRandom == 2){
        for (int i = 0; i < studentCount; i++){
            cout << "Iveskite studento varda, pavarde, egzamino ivertinima ir namu darbus (uzbaigimui iveskite 0): ";
            cin >> student[i].name >> student[i].surname >> student[i].exam;
            countHomework = 0;
            cin >> student[i].homework[countHomework];
            while (student[i].homework[countHomework] != 0){
                sum += student[i].homework[countHomework];
                countHomework++;
                cin >> student[i].homework[countHomework];
            }
            if (countBy == 1){
                student[i].finalGrade = countMean(student[i].homework, countHomework) * 0.4 + student[i].exam * 0.6;
            }
            if (countBy == 2){
                student[i].finalGrade = findMedian(student[i].homework, countHomework) * 0.4 + student[i].exam * 0.6;
            }
        }
    }
        
    if (doRandom == 1){
        for (int i = 0; i < studentCount; i++){
            cout << "Iveskite studento varda ir pavarde: ";
            cin >> student[i].name >> student[i].surname;
            srand(time(0));
            student[i].exam = rand() % 10 + 1;
            countHomework = rand() % 21;
            if (countHomework == 0){
                student[i].homework[0] = 0;
                countHomework = 1;
            }
            else {
                for (int j = 0; j < countHomework; j++){
                    student[i].homework[j] = rand() % 10 + 1;
                }
            }
            if (countBy == 1){
                student[i].finalGrade = countMean(student[i].homework, countHomework) * 0.4 + student[i].exam * 0.6;
            }
            if (countBy == 2){
                student[i].finalGrade = findMedian(student[i].homework, countHomework) * 0.4 + student[i].exam * 0.6;
            }
        }
    }
    
    cout << "\n\n";
    if (countBy == 1){
    cout << "Vardas\t\tPavarde\t\tGalutinis (vid.)\n";
    }
    if (countBy == 2){
    cout << "Vardas\t\tPavarde\t\tGalutinis (med.)\n";
    }
    cout << "------------------------------------------------------\n";
    cout.precision(3);
    for (int i = 0; i < studentCount; i++){
        cout << student[i].name << "\t\t" << student[i].surname << "\t\t" << student[i].finalGrade << "\n";
    }
    return 0;

}