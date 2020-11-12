#include "createFiles.h"

using std::left;
using std::setw;

void generateFile(std::string fileName, int studentCount, int homeworkCount){

    //reikalinga pažymių generavimui
    std::mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();

    //atidaromas failas
    std::ofstream file (fileName);

    //išspausdinama pirma eilutė
    file << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde";
    for (int i = 0; i < homeworkCount; i++){
        file << left << setw(7) << "ND" + std::to_string(i+1);
    }
    file << left << setw(10) << "Egzaminas" << std::endl;

    //spausdinami vardai, pavardės, sugeneruoti namų darbai ir egzaminas
    for (int i = 0; i < studentCount; i++){
        file << left << setw(15) << "Vardas" + std::to_string(i+1) << left << setw(15) << "Pavarde" + std::to_string(i+1);
        for (int j = 0; j < homeworkCount; j++){
            file << left << setw(7) << dist(mt);
        }
        file << left << setw(10) << dist(mt) << std::endl;
    }

    //uždaromas failas
    file.close();

    //sustabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << "Failas su " << studentCount << " studentu duomenimis sukurtas per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;;
}

void writeFile(std::string fileName, std::vector<Data> student, int homeworkCount, std::string studentType){
    
    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream file (fileName);

    //pirma failo eilutė
    file << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(10) << "Galutinis" << std::endl;

    //įrašomi studentų duomenys, vardai, pavardės, galutiniai balai
    for (int i = 0; i < student.size(); i++){
        file << left << setw(15) << student[i].name << left << setw(15) << student[i].surname << left << setw(10) << student[i].finalGradeMean << std::endl;
    }

    //uždaromas failas
    file.close();

    //sustabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << studentType << " failas su " << student.size() << " studentu duomenimis sukurtas per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;
}

void writeFile(std::string fileName, std::list<Data> student, int homeworkCount, std::string studentType){
    
    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream file (fileName);

    //pirma failo eilutė
    file << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(10) << "Galutinis" << std::endl;

    //įrašomi studentų duomenys, vardai, pavardės, galutiniai balai
    for (Data s : student){
        file << left << setw(15) << s.name << left << setw(15) << s.surname << left << setw(10) << s.finalGradeMean << std::endl;
    }

    //uždaromas failas
    file.close();

    //sustabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << studentType << " failas su " << student.size() << " studentu duomenimis sukurtas per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;
}
