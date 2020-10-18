#include "reading.h"
#include "final.h"
#include "final.cpp"


void readFile(std::vector<Data> &student, int studentCount, int homeworkCount, std::string fileName){

    //vektoriui paskiriamas dydis, kintamieji duomenų nuskaitymui
    student.reserve(studentCount + 1);
    Data temporary;
    float temp;

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //atidaromas failas
    std::ifstream file(fileName);

    //nuskaitoma pirma eilutė
    std::string firstLine;
    getline(file, firstLine);

    //nuskaitomi studentų duomenys, suskaičiuojamas galutinis balas
    for (int i = 0; i < studentCount; i++){
        file >> temporary.name >> temporary.surname;
        for (int j = 0; j < homeworkCount; j++){
            file >> temp;
            temporary.homework.push_back(temp);
        }
        file >> temporary.exam;
        temporary.finalGradeMean = finalByMean(temporary);

        //duomenys įrašomi į student vektorių, ištrinami namų darbai temporary, kad būtų galima naudoti tolimesniam duomenų nuskaitymui
        student.push_back(temporary);
        temporary.homework.clear();
    }

    //uždaromas failas
    file.close();

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << "Failas su " << studentCount << " studentu duomenimis nuskaitytas ir ju vidurkiai suskaiciouti per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;;

}