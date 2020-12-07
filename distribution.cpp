#include "distribution.h"

//skirsto studentus pagal pažymius
void distribute(std::vector<Student> &student, std::vector<Student> &bad){

    int n = student.size();
    bad.reserve(n);

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //studentai, kurių vidurkis <5, nukopijuojami į atskirą vektorių ir tada ištrinami
    std::copy_if(student.begin(), student.end(), std::back_inserter(bad), [](Student s){return s.getFinalGradeMean() < 5;});
    student.erase(std::remove_if(student.begin(), student.end(), [](Student s){return s.getFinalGradeMean() < 5;}), student.end());

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << n << " studentu suskirstyti per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;

}

