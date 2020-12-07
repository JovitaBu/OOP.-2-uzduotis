#pragma once

#include "Student.h"

#include <vector>
#include <iomanip>
#include <chrono>
#include <random>

void inputData(std::vector<Student> &student, int doRandom, int studentCount, int countBy);
void results(std::vector<Student> student, int countBy);