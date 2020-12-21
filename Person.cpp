#include "Person.h"

Person::Person() {
    name_ = "";
    surname_ = "";
}

Person::Person(const Person &p) {
    name_ = p.name_;
    surname_ = p.surname_;
}

Person & Person::operator=(const Person &p) {
    name_ = p.name_;
    surname_ = p.surname_;
    return *this;
}

std::ostream& operator<< (std::ostream& ostr, const Person &p){
    ostr << "Vardas: " << p.name_ <<  "\nPavarde: " << p.surname_ << "\n";
    return ostr;
}

std::string Person::getName() {
    return name_;
}

std::string Person::getSurname() {
    return surname_;
}

void Person::setData(std::string name, std::string surname) {
    name_ = name;
    surname_ = surname;
}