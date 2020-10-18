#include "final.h"

void final(Data &student, int countBy){

    //jei reikia abiejų galutinio balo versijų
    if (countBy == 0){
        student.finalGradeMean = finalByMean(student);
        student.finalGradeMedian = finalByMedian(student);
    }

    //jei skaičiuojama pagal namų darbų vidurkį
    if (countBy == 1){
        student.finalGradeMean = finalByMean(student);
    }

    //jei skaičiuojama pagal namų darbų medianą
    if (countBy == 2){
        student.finalGradeMedian = finalByMedian(student);
    }
}

float finalByMean(Data student){

    //skaičiuojama visų namų darbų pažymių suma
    float sum = 0;
    for (int i = 0; i < student.homework.size(); i++){
        sum += student.homework[i];
    }

    //grąžina galutinio balo reikšmę
    return sum / student.homework.size() * 0.4 + student.exam * 0.6;
}

float finalByMedian(Data student){

    //namų darbai surūšiuojami nemažėjimo tvarka (surašomi į variacinę eilutę)
    sort(student.homework.begin(), student.homework.end());

    //namų darbų skaičius
    int size = student.homework.size();


    //grąžina galutinio balo reikšmę, jei mediana - dviejų narių suma 
    if (size % 2 == 0){
        return (student.homework[size / 2] + student.homework[size / 2 - 1]) * 1.0 / 2 * 0.4 + student.exam * 0.6;
    }
    
    //grąžina galutinio balo reikšmę, jei mediana - vidurinė reikšmė 
    else {
        return student.homework[size / 2] * 0.4 + student.exam * 0.6;
    }
}
