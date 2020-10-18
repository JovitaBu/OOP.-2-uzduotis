#pragma once

#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <random>

void generateFile(std::string fileName, int studentCount, int homeworkCount);
void writeFile(std::string fileName, std::vector<Data> student, int homeworkCount, std::string studentType);