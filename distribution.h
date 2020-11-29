#pragma once 

#include "Data.h"

#include <chrono>
#include <algorithm>
#include <iterator>
#include <numeric>

void distribute(std::vector<Data> &student, std::vector<Data> &bad);
void distribute(std::list<Data> &student, std::list<Data> &bad);
