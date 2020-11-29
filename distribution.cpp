#include "distribution.h"

void distribute(std::vector<Data> &student, std::vector<Data> &bad){
    
    int n = student.size();
    bad.reserve(n);

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //studentai, kurių vidurkis <5, nukopijuojami į atskirą vektorių ir tada ištrinami
    std::copy_if(student.begin(), student.end(), std::back_inserter(bad), [](Data s){return s.finalGradeMean < 5;});
    student.erase(std::remove_if(student.begin(), student.end(), [](Data s){return s.finalGradeMean < 5;}), student.end());

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << n << " studentu suskirstyti per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;

}

void distribute(std::list<Data> &student, std::list<Data> &bad){
        
    int n = student.size();

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //studentai, kurių vidurkis <5, nukopijuojami į atskirą sąrašą ir tada ištrinami
    std::copy_if(student.begin(), student.end(), std::back_inserter(bad), [](Data s){return s.finalGradeMean < 5;});
    student.erase(std::remove_if(student.begin(), student.end(), [](Data s){return s.finalGradeMean < 5;}), student.end());

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << n << " studentu suskirstyti per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;

}
