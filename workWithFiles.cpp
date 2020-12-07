#include "workWithFiles.h"

using std::left;
using std::setw;

//automatiškai sugeneruojamas failas
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

//studentų duomenys įrašomi į failą
void writeFile(std::string fileName, std::vector<Student> student, int homeworkCount, std::string studentType){

    //pradedamas skaičiuoti laikas
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream file (fileName);

    //pirma failo eilutė
    file << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw(10) << "Galutinis" << std::endl;

    //įrašomi studentų duomenys, vardai, pavardės, galutiniai balai
    for (int i = 0; i < student.size(); i++){
        file << left << setw(15) << student[i].getName() << left << setw(15) << student[i].getSurname() << left << setw(10) << student[i].getFinalGradeMean() << std::endl;
    }

    //uždaromas failas
    file.close();

    //sustabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << studentType << " failas su " << student.size() << " studentu duomenimis sukurtas per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;
}

//nuskaitomas failas
void readFile(std::vector<Student> &student, int studentCount, int homeworkCount, std::string fileName){

    //vektoriui paskiriamas dydis, kintamieji duomenų nuskaitymui
    student.reserve(studentCount + 1);
    std::string name, surname;
    float exam;
    std::vector<float> homework;
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
        file >> name >> surname;
        for (int j = 0; j < homeworkCount; j++){
            file >> temp;
            homework.push_back(temp);
        }
        file >> exam;
        
        student[i].setData(name, surname, homework, exam);
        student[i].setFinalGradeMean(finalByMean(student[i]));

        homework.clear();
    }

    //uždaromas failas
    file.close();

    //stabdomas laiko skaičiavimas
    auto end = std::chrono::high_resolution_clock::now();

    //išvedamas laiko skaičiavimo rezultatas
    std::cout << "Failas su " << studentCount << " studentu duomenimis nuskaitytas ir ju vidurkiai suskaiciouti per " << std::chrono::duration<double>(end - start).count() << " s." << std::endl;;

}

