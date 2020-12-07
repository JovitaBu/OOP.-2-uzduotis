#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Student{
    private:
        std::string name_;
        std::string surname_;
        float exam_;
        float finalGradeMean_;
        float finalGradeMedian_;
        std::vector<float> homework_;
    public:
        //konstruktorius
        Student();

        //getter'iai
        std::string getName();
        std::string getSurname();
        float getExam();
        float getFinalGradeMean();
        float getFinalGradeMedian();
        std::vector<float> getHomework();

        //setter'iai
        void setFinalGradeMean(float f);
        void setFinalGradeMedian(float f);
        void setData(std::string name, std::string surname, std::vector<float> homework, float exam);
        
};

//lygina vardus
bool compareNames(Student &first, Student &second);
//skaičiuoja galutinius balus
void final(Student &student, int countBy);
//skaičiuoja galutinį balą pagal vidurkį
float finalByMean(Student student);
//skaičiuoja galutinį balą pagal medianą
float finalByMedian(Student student);