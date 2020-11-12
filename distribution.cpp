#include "distribution.h"

void distribute(std::vector<Data> student, std::vector<Data> &good, std::vector<Data> &bad){

    //vektoriams paskiriama pusė viso studentų vektoriaus dydžio
    good.reserve(student.size()/2);
    bad.reserve(student.size()/2);

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //skirstomi studentai
    for (int i = 0; i < student.size(); i++){
        if (student[i].finalGradeMean < 5.00){
            bad.push_back(student[i]);
        }
        else{
            good.push_back(student[i]);
        }
    }

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << student.size() << " studentu suskirstyti pagal vidurki per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;
}

void distribute(std::list<Data> student, std::list<Data> &good, std::list<Data> &bad){

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //skirstomi studentai
    for (Data s : student){
        if (s.finalGradeMean < 5.00){
            bad.push_back(s);
        }
        else{
            good.push_back(s);
        }
    }

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << student.size() << " studentu suskirstyti pagal vidurki per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;
}
