#include "workWithScreen.h"
#include "check.h"

using std::cout;
using std::cin;
using std::left;
using std::setw;

//duomenų įvedimas/generavimas
void inputData(std::vector<Student> &student, int doRandom, int studentCount, int countBy) {

    //kintamieji studentų duomenų nuskaitymui
    std::string name, surname;
    float exam, temp; //temp - namų darbų nuskaitymui
    std::vector<float> homework;

    //sukamas ciklas, kol įvedami visų studentų duomenys
    for (int i = 0; i < studentCount; i++){

        //jei pažymiai generuojami
        if (doRandom == 1) {

            //vartotojas įveda studento vardą ir pavardę
            cout << "\nIveskite studento varda ir pavarde: ";
            cin >> name >> surname;

            //namų darbų kiekiui ir pažymių generavimui
            std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
            std::uniform_int_distribution<int> distGrade(1, 10);
            std::uniform_int_distribution<int> distCount(1, 20); //namų darbų kiekis: 1-20

            //sugeneruojamas egzamino pažymys
            exam = distGrade(mt);

            //sugeneruojami namų darbų pažymiai
            for (int j = 0; j < distCount(mt); j++){
                homework.push_back(distGrade(mt));
            }
        }

        //jei visus duomenis suveda vartotojas
        if (doRandom == 2) {
        
            //vartotojas įveda vardą, pavardę, egzamino pažymį
            cout << "\nIveskite studento varda, pavarde, egzamino ivertinima ir namu darbus (spauskite enter): ";
            cin >> name >> surname;
            checkGrade(exam);

            //vartotojas įveda namų darbus 
            while (cin.peek() != '\n'){
                checkGrade(temp);
                homework.push_back(temp);
            }
        }

        //duomenys perkeliami į studentų vektorių, suskaičiuojamas atitinkamas galutinis balas
        student[i].setData(name, surname, homework, exam);
        final(student[i], countBy);

        //ištrinami namų darbai, kad būtų galima naudoti tolimesniam duomenų nuskaitymui
        homework.clear();
    }
}

//ekrane išvedami rezultata
void results(std::vector<Student> student, int countBy) {

    //kai reikia išvesti galutinį ir pagal vidurkį, ir pagal medianą
    if (countBy == 0){
        cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)";
        cout << "\n--------------------------------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < student.size(); i++){
            cout << left << setw(20) << student[i].getName() << setw(20) << student[i].getSurname() << setw(20) << student[i].getFinalGradeMean() << setw(20) << student[i].getFinalGradeMedian() << std::endl;
        }
    }

    //kai reikia išvesti galutinį pagal vidurkį
    if (countBy == 1){
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (vid.)";
        cout << "\n------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < student.size(); i++){
            cout << left << setw(20) << student[i].getName() << setw(20) << student[i].getSurname() << setw(20) << student[i].getFinalGradeMean() << std::endl;
        }
    }

    //kai reikia išvesti galutinį pagal medianą
    if (countBy == 2){
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (med.)";
        cout << "\n------------------------------------------------------\n";
        cout.precision(3);
        for (int i = 0; i < student.size(); i++){
            cout << left << setw(20) << student[i].getName() << setw(20) << student[i].getSurname() << setw(20) << student[i].getFinalGradeMedian() << std::endl;
        }
    }
}