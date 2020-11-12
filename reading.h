#pragma once

#include "Data.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <list>

void readFile(std::vector<Data> &student, int studentCount, int homeworkCount, std::string fileName);
void readFile(std::list<Data> &student, int studentCount, int homeworkCount, std::string fileName);
