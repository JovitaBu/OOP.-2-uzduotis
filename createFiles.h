#pragma once

#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <random>
#include <list>

void generateFile(std::string fileName, int studentCount, int homeworkCount);
void writeFile(std::string fileName, std::vector<Data> student, int homeworkCount, std::string studentType);
void writeFile(std::string fileName, std::list<Data> student, int homeworkCount, std::string studentType);
