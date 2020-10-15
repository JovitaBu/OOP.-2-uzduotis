#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Data {
    std::string name, surname;
    float exam , finalGradeMean, finalGradeMedian;
    std::vector<float> homework;
};