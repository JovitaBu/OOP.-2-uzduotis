#include "workWithScreen.h"
#include "check.h"
#include "distribution.h"
#include "Student.h"
#include "workWithFiles.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

    //vartotojas pasirenka, ar atlikti failų generavimą, sukuriamas atitinkamas kintamasis
    int doGeneration;
    cout << "Ar norite atlikti visu duomenu generavima (sukuriami penki failai)?\n(1) taip;\n(2) ne: ";
    checkChoice(doGeneration);

    //jei atliekamas failų generavimas
    if(doGeneration == 1){

        //vartotojas įveda namų darbų kiekį, tam atitinkamas kintamasis
        int homeworkCount;
        cout << "\nIveskite, po kiek namu darbu generuoti: ";
        checkCount(homeworkCount);
        cout << endl;

        //vektorius bad - studentams, kurių vidurkiai < 5
        vector<Student> bad;

        //sukamas ciklas sukurti keliams failams
        for (int studentCount = 1000; studentCount <= 10000000; studentCount *= 10){
            
            //pradedamas skaičiuoti laikas
            auto start = std::chrono::high_resolution_clock::now();

            //vektorius visiems studentams saugoti, po skirtymo lieka tik studentai, kurių vidurkiai >= 5
            vector<Student> student(studentCount);

            //iš karto sukuriamas failo pavadinimas, kad to nereiktų daryti kitose funkcijose
            string fileName = "student" + std::to_string(studentCount) + ".txt";

            //sugeneruojamas failas
            generateFile(fileName, studentCount, homeworkCount);

            //nuskaitomas failas į student vektorių
            readFile(student, studentCount, homeworkCount, fileName);

            //studentai suskirstomi pagal vidurkį
            distribute(student, bad);

            //suskirstyti studentai įrašomi į atskirus failus
            writeFile("kietuoliai" + std::to_string(studentCount) + ".txt", student, homeworkCount, "Kietuoliu");
            writeFile("vargsiukai" + std::to_string(studentCount) + ".txt", bad, homeworkCount, "Vargsiuku");

            //vektoriai ištrinami ir panaikinama jų užimama atmintis
            bad.clear();
            vector<Student>().swap(bad);
            student.clear();
            vector<Student>().swap(student);

            //sustabdomas laiko skaičiavimas
            auto end = std::chrono::high_resolution_clock::now();

            //išvedamas sugaištas laikas
            std::cout << "Visas sugaistas laikas " << studentCount << " studentu duomenims: " << std::chrono::duration<double>(end - start).count() << " s." << endl;
            cout << endl;
        }
    }

    //jei failai negeneruojami
    if (doGeneration == 2){

        //kintamasis pasirinkimui, ar nuskaityti duomenis iš kursiokai.txt
        int readData;

        //vartotojas pasirenka, ar duomenis įvesti, ar nuskaityti
        cout << "\nPasirinkite:\n(1) duomenis ivesti;\n(2) duomenis nuskaityti is kursiokai.txt failo: ";
        checkChoice(readData);

        //jei duomenis veda vartotojas
        if (readData == 1){

            //kintamieji pasirinkimui, ar skaičiuoti galutinį pagal vidurkį ar medianą;
            //ar generuoti namų darbų ir egzamino pažymius ir kintamasis studentų skaičiui
            int countBy, doRandom, studentCount;
            
            //vartotojas pasirenka, kaip skaičiuoti galutinį balą, ar generuoti pažymius, įveda studentų skaičių
            cout << "\nPasirinkite:\n(1) skaiciuoti pagal namu darbu vidurki;\n(2) skaiciuoti pagal namu darbu mediana: ";
            checkChoice(countBy);
            cout << "\nAr norite egzamino ir namu darbo pazymius generuoti atsitiktinai?\n(1) taip;\n(2) ne: ";
            checkChoice(doRandom);
            cout << "\nIveskite studentu skaiciu: ";
            checkCount(studentCount);
            cout << "\n";

            //vektorius studentų duomenims saugoti
            vector<Student> student(studentCount);

            //nuskaitomi/generuojami duomenys
            inputData(student, doRandom, studentCount, countBy);

            cout << endl;
            cout << endl;

            //išvedami rezultatai
            results(student, countBy);

        }

        //jei duomenys nuskaitomi iš kursiokai.txt
        if (readData == 2){

            //kintamieji studentų duomenų nuskaitymui
            std::string name, surname;
            float exam, temp; //temp - namų darbų nuskaitymui
            std::vector<float> homework;

            //vektorius studentų duomenims saugoti, temporary - duomenų nuskaitymui
            vector<Student> student;
            Student temporary;

            //atidaromas failas
            std::ifstream dataFile("kursiokai.txt");

            //nuskaitoma pirma eilutė, suskirstoma, įkeliama į vektorių, sužinomas namų darbų skaičius
            string firstLine;
            getline(dataFile, firstLine);
            std::istringstream iss(firstLine);
            vector<string> line;
            do {
                std::string parts;
                iss >> parts;
                line.push_back(parts);
            } while (iss);
            int homeworkCount = line.size() - 4;

            //sukamas ciklas, kol baigiasi failas
            while (!dataFile.eof()){

                //nuskaitomi vardas ir pavardė
                dataFile >> name >> surname;

                //nuskaitomi namų darbai ir egzaminas
                for (int i = 0; i < homeworkCount; i++){
                    dataFile >> temp;
                    homework.push_back(temp);
                }
                dataFile >> exam;

                //priskiriami duomenys, suskaičiuojami vidurkiai abiem būdais,viskas įrašoma į student vektorių
                temporary.setData(name, surname, homework, exam);
                temporary.setFinalGradeMean(finalByMean(temporary));
                temporary.setFinalGradeMedian(finalByMedian(temporary));
                student.push_back(temporary);

                //ištrinami namų darbai, kad būtų galima naudoti tolimesniam duomenų nuskaitymui
                homework.clear();
            }

            //uždaromas failas
            dataFile.close();

            //surūšiuojamas studentų sąrašas (vektorius) pagal vardus
            sort(student.begin(), student.end(), compareNames);

            cout << endl;
            cout << endl;

            results(student, 0);
        }
    }
    return 0;
}
