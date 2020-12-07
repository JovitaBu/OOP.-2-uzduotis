#include "Student.h"

Student::Student() {
    name_ = "";
    surname_ = "";
    exam_ = 0;
    finalGradeMean_ = 0;
    finalGradeMedian_ = 0;
}
Student::Student (const Student &s) {
    name_ = s.name_;
    surname_ = s.surname_;
    exam_ = s.exam_;
    finalGradeMean_ = s.finalGradeMean_;
    finalGradeMedian_ = s.finalGradeMedian_;
    homework_ = s.homework_;
};
Student& Student::operator= (const Student& s) {
    name_ = s.name_;
    surname_ = s.surname_;
    exam_ = s.exam_;
    finalGradeMean_ = s.finalGradeMean_;
    finalGradeMedian_ = s.finalGradeMedian_;
    homework_ = s.homework_;
    return *this;
}
std::ostream& operator<< (std::ostream& ostr, const Student &s) {
    ostr << "Vardas: " << s.name_ <<  "\nPavarde: " << s.surname_ << "\nNamu darbai:";
    for (float h : s.homework_){
        ostr << " " << h;
    }
    ostr << "\nEgzaminas: " << s.exam_ << "\n";
    return ostr;
}

void Student::setData(std::string name, std::string surname, std::vector<float> homework, float exam) {
    name_ = name;
    surname_ = surname;
    exam_ = exam;
    homework_ = homework;
}
void Student::setFinalGradeMean(float f) {
    if (f > 0 && f <= 10){ finalGradeMean_ = f; }
    else{ return;}
}
void Student::setFinalGradeMedian(float f) {
    if (f > 0 && f <= 10){ finalGradeMedian_ = f; }
    else{ return; }
}

std::string Student::getName() { 
    return name_;
}
std::string Student::getSurname() {
    return surname_;
}
float Student::getExam() {
    return exam_;
}
float Student::getFinalGradeMean() {
    return finalGradeMean_;
}
float Student::getFinalGradeMedian() {
    return finalGradeMedian_;
    }
std::vector<float> Student::getHomework() {
    return homework_;
}

bool compareNames(Student &first, Student &second){

    if (first.getName() != second.getName()){
        return first.getName() < second.getName();
    }

    else{
        return first.getSurname() < second.getSurname();
    }
}

void final(Student &student, int countBy){

    //jei reikia abiejų galutinio balo versijų
    if (countBy == 0){
        student.setFinalGradeMean(finalByMean(student));
        student.setFinalGradeMedian(finalByMedian(student));
    }

    //jei skaičiuojama pagal namų darbų vidurkį
    if (countBy == 1){
        student.setFinalGradeMean(finalByMean(student));
    }

    //jei skaičiuojama pagal namų darbų medianą
    if (countBy == 2){
        student.setFinalGradeMedian(finalByMedian(student));
    }
}

float finalByMean(Student student){

    //skaičiuojama visų namų darbų pažymių suma
    float sum = 0;
    std::vector<float> homework = student.getHomework();
    for (int i = 0; i < homework.size(); i++){
        sum += homework[i];
    }

    //grąžina galutinio balo reikšmę
    return sum / homework.size() * 0.4 + student.getExam() * 0.6;
}

float finalByMedian(Student student){

    //namų darbai surūšiuojami nemažėjimo tvarka (surašomi į variacinę eilutę)
    std::vector<float> homework = student.getHomework();
    sort(homework.begin(), homework.end());

    //namų darbų skaičius
    int size = homework.size();


    //grąžina galutinio balo reikšmę, jei mediana - dviejų narių suma 
    if (size % 2 == 0){
        return (homework[size / 2] + homework[size / 2 - 1]) * 1.0 / 2 * 0.4 + student.getExam() * 0.6;
    }

        //grąžina galutinio balo reikšmę, jei mediana - vidurinė reikšmė
    else {
        return homework[size / 2] * 0.4 + student.getExam() * 0.6;
    }
}

