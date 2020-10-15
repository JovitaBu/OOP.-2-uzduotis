#include "final.h"

float finalByMean(Data student){

    float sum = 0;

    for (int i = 0; i < student.homework.size(); i++){
        sum += student.homework[i];
    }

    return sum / student.homework.size() * 0.4 + student.exam * 0.6;
}

float finalByMedian(Data student){

    sort(student.homework.begin(), student.homework.end());

    int size = student.homework.size();

    if (size % 2 == 0){
        return (student.homework[size / 2] + student.homework[size / 2 - 1]) * 1.0 / 2 * 0.4 + student.exam * 0.6;
    }
    
    else {
        return student.homework[size / 2] * 0.4 + student.exam * 0.6;
    }
}