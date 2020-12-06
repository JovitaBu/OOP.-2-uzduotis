#include "comparator.h"
#include "final.h"
#include "check.h"
#include "createFiles.h"
#include "reading.h"
#include "distribution.h"
#include "output.h"

#include <iostream>
#include <fstream>
#include <iomanip>


/*#include "comparator.cpp"
#include "check.cpp"
#include "createFiles.cpp"
#include "reading.cpp"
#include "distribution.cpp"
#include "output.cpp"*/

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

int main() {

    //kintamieji pasirinkimui, ar atlikti failų generavimą ir kokį tipą duomenų saugojimui naudoti
    int doGeneration;
    int type;

    //vartotojas pasirenka, ar atlikti failų generavimą ir kokį konteinerį naudoti
    cout << "Ar norite atlikti visu duomenu generavima (sukuriami penki failai)?\n(1) taip;\n(2) ne: ";
    checkChoice(doGeneration);
    cout <<"\nNaudoti\n(1) vektorius;\n(2) sarasus: ";
    checkChoice(type);

    //jei atliekamas failų generavimas
    if(doGeneration == 1){

        //jei naudojami vektoriai
        if (type == 1){

            //vektoriuje student bus saugomi visų studentų duomenys, o temporary naudojamas duomenų nuskaitymui
            vector<Data> student;
            Data temporary;

            //kintamasis namų darbų kiekiui, kurį įveda vartotojas, vektorius good - studentams, kurių vidurkiai >= 5, ir bad - kurių vidurkiai < 5
            int homeworkCount;
            vector<Data> bad;

            //vartotojas įveda namų darbų kiekį
            cout << "\nIveskite, po kiek namu darbu generuoti: ";
            checkCount(homeworkCount);
            cout << endl;

            //sukamas ciklas sukurti keliams failams
            for (int studentCount = 1000; studentCount <= 10000000; studentCount *= 10){
                
                //pradedamas skaičiuoti laikas
                auto start = std::chrono::high_resolution_clock::now();

                //iš karto sukuriamas failo pavadinimas, kad to nereiktų daryti kitose funkcijose
                string fileName = "student" + std::to_string(studentCount) + ".txt";

                //sugeneruojamas failas
                generateFile(fileName, studentCount, homeworkCount);

                //nuskaitomas failas į student vektorių
                readFile(student, studentCount, homeworkCount, fileName);

                //studentai suskirstomi pagal vidurkį
                distribute(student, bad);
                
                //suskirstyti studentai įrašomi į atskirus failus, vektoriai ištrinami ir panaikinama jų užimama atmintis
                writeFile("kietuoliai" + std::to_string(studentCount) + ".txt", student, homeworkCount, "Kietuoliu");
                writeFile("vargsiukai" + std::to_string(studentCount) + ".txt", bad, homeworkCount, "Vargsiuku");
                bad.clear();
                vector<Data>().swap(bad);
                student.clear();
                vector<Data>().swap(student);


                //sustabdomas laiko skaičiavimas
                auto end = std::chrono::high_resolution_clock::now();

                //išvedamas sugaištas laikas
                std::cout << "Visas sugaistas laikas " << studentCount << " studentu duomenims: " << std::chrono::duration<double>(end - start).count() << " s." << endl;
                cout << endl;
            }
        }

        //jei naudojamas list
        if (type == 2){

            //sąraše studentList bus saugomi visų studentų duomenys, o temporary naudojamas duomenų nuskaitymui
            list<Data> studentList;
            Data temporary;
            //kintamasis namų darbų kiekiui, kurį įveda vartotojas, vektorius good - studentams, kurių vidurkiai >= 5, ir bad - kurių vidurkiai < 5
            int homeworkCount;
            list<Data> bad;

            //vartotojas įveda namų darbų kiekį
            cout << "\nIveskite, po kiek namu darbu generuoti: ";
            checkCount(homeworkCount);
            cout << endl;

            //sukamas ciklas dirbti su keliais failais
            for (int studentCount = 1000; studentCount <= 10000000; studentCount *= 10){
                
                //pradedamas skaičiuoti laikas
                auto start = std::chrono::high_resolution_clock::now();

                //iš karto sukuriamas failo pavadinimas, kad to nereiktų daryti kitose funkcijose
                string fileName = "student" + std::to_string(studentCount) + ".txt";

                //sugeneruojamas failas
                generateFile(fileName, studentCount, homeworkCount);

                //nuskaitomas failas į student vektorių
                readFile(studentList, studentCount, homeworkCount, fileName);

                //studentai suskirstomi pagal vidurkį
                distribute(studentList, bad);

                //suskirstyti studentai įrašomi į atskirus failus, sąrašai ištrinami
                writeFile("kietuoliai" + std::to_string(studentCount) + ".txt", studentList, homeworkCount, "Kietuoliu");
                writeFile("vargsiukai" + std::to_string(studentCount) + ".txt", bad, homeworkCount, "Vargsiuku");
                studentList.clear();
                bad.clear();

                //sustabdomas laiko skaičiavimas
                auto end = std::chrono::high_resolution_clock::now();

                //išvedamas sugaištas laikas
                std::cout << "Visas sugaistas laikas " << studentCount << " studentu duomenims: " << std::chrono::duration<double>(end - start).count() << " s." << endl;
                cout << endl;
            }
        }
    }

    //jei vartotojas pats įveda duomenis
    if (doGeneration == 2){

        //vektoriuje student bus saugomi visų studentų duomenys, o temporary naudojamas duomenų nuskaitymui
        vector<Data> student;
        Data temporary;

        //kintamasis studentų kiekiui, įveda vartotojas
        int studentCount;

        //kintamasis, ar nuskaityti duomenis iš kursiokai.txt
        int readData;

        //vartotojas pasirenka, ar duomenis įvesti, ar nuskaityt
        cout << "\nPasirinkite:\n(1) duomenis ivesti;\n(2) duomenis nuskaityti is kursiokai.txt failo: ";
        checkChoice(readData);

        //jei duomenis veda vartotojas
        if (readData == 1){

            //kintamieji pasirinkimui, ar skaičiuoti galutinį pagal vidurkį ar medianą bei ar generuoti namų darbų ir egzamino pažymius
            int countBy;
            int doRandom;
            
            //vartotojas pasirenka, kaip skaičiuoti galutinį balą, ar generuoti pažymius, įveda studentų skaičių
            cout << "\nPasirinkite:\n(1) skaiciuoti pagal namu darbu vidurki;\n(2) skaiciuoti pagal namu darbu mediana: ";
            checkChoice(countBy);
            cout << "\nAr norite egzamino ir namu darbo pazymius generuoti atsitiktinai?\n(1) taip;\n(2) ne: ";
            checkChoice(doRandom);
            cout << "\nIveskite studentu skaiciu: ";
            checkCount(studentCount);
            cout << "\n";
            
            //jei visus duomenis veda vartotojas
            if (doRandom == 2){

                //kintamasis namų darbų nuskaitymui
                float temp;

                //sukamas ciklas, kol įvedami visų studentų duomenys
                for (int i = 0; i < studentCount; i++){

                    //vartotojas įveda vardą, pavardę, egzamino pažymį
                    cout << "\nIveskite studento varda, pavarde, egzamino ivertinima ir namu darbus (spauskite enter): ";
                    cin >> temporary.name >> temporary.surname;
                    checkGrade(temporary.exam);

                    //vartotojas įveda namų darbus 
                    while (cin.peek() != '\n'){
                        checkGrade(temp);
                        temporary.homework.push_back(temp);
                    }
                    
                    //suskaičiuojamas galutinis balas pagal vartotojo pasirinkimą
                    final(temporary, countBy);
                    
                    //nuskaityti duomenys įrašomi į student vektorių, ištrinami namų darbai temporary, kad būtų galima naudoti tolimesniam duomenų nuskaitymui
                    student.push_back(temporary);
                    temporary.homework.clear();
                }
            }

            //jei pažymiai generuojami
            if (doRandom == 1){

                //sukamas ciklas, kol vartotojas įveda visus vardu ir pavardes, o pažymiai sugeneruojami
                for (int i = 0; i < studentCount; i++){

                    //vartotojas įveda studento vardą ir pavardę
                    cout << "\nIveskite studento varda ir pavarde: ";
                    cin >> temporary.name >> temporary.surname;

                    //namų darbų kiekiui ir pažymių generavimui
                    std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
                    std::uniform_int_distribution<int> distGrade(1, 10);
                    std::uniform_int_distribution<int> distCount(1, 20);

                    //sugeneruojamas egzamino pažymys
                    temporary.exam = distGrade(mt);

                    //sugeneruojami namų darbų pažymiai
                    for (int j = 0; j < distCount(mt); j++){
                        temporary.homework.push_back(distGrade(mt));
                    }

                    //suskaičiuojamas galutinis balas pagal vartotojo pasirinkimą
                    final(temporary, countBy);

                    //duomenys įrašomi į student vektorių, ištrinami namų darbai temporary, kad būtų galima naudoti tolimesniam duomenų nuskaitymui
                    student.push_back(temporary);
                    temporary.homework.clear();
                }
            }

            cout << endl;
            cout << endl;
            
            //išvedami rezultatai
            results(student, countBy);

        }


        //jei duomenys nuskaitomi iš kursiokai.txt
        if (readData == 2){

            //atidaromas failas
            std::ifstream dataFile("kursiokai.txt");

            //nuskaitoma pirma eilutė
            string firstLine;
            getline(dataFile, firstLine);

            //kintamasis namų darbų nuskaitymui
            float temp;

            //sukamas ciklas, kol baigiasi failas
            while (!dataFile.eof()){

                //nuskaitomi vardas ir pavardė
                dataFile >> temporary.name >> temporary.surname;

                //nuskaitomi 5 namų darbai ir egzaminas
                for (int i = 0; i < 5; i++){
                    dataFile >> temp;
                    temporary.homework.push_back(temp);
                }
                dataFile >> temporary.exam;

                //suskaičiuojami vidurkiai abiem būdais
                temporary.finalGradeMean = finalByMean(temporary);
                temporary.finalGradeMedian = finalByMedian(temporary);
            
                //nuskaityti duomenys įrašomi į student vektorių, ištrinami namų darbai temporary, kad būtų galima naudoti tolimesniam duomenų nuskaitymui
                student.push_back(temporary);
                temporary.homework.clear();
            }

            //uždaromas failas
            dataFile.close();

            //surūšiuojamas studentų sąrašas (vektorius)
            sort(student.begin(), student.end(), compareNames);

            cout << endl;
            cout << endl;

            results(student, 0);
        }
    }

        return 0;
}
