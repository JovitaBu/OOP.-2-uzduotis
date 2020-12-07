#pragma once

#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <random>


void generateFile(std::string fileName, int studentCount, int homeworkCount);
void writeFile(std::string fileName, std::vector<Student> student, int homeworkCount, std::string studentType);
void readFile(std::vector<Student> &student, int studentCount, int homeworkCount, std::string fileName);