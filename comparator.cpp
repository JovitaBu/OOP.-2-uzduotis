#include "comparator.h"

bool compareNames(Data firstStudent, Data secondStudent){
    
    if (firstStudent.name != secondStudent.name){
        return firstStudent.name < secondStudent.name;
    }

    else{
        return firstStudent.surname < secondStudent.surname;
    }
}