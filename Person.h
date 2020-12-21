#pragma once

#include <iostream>
#include <string>

class Person {
    protected:
        std::string name_;
        std::string surname_;
    public:
        //konstruktorius
        Person();

        //kopijavimo konstruktorius
        Person (const Person &p);

        //kopijavimo priskirties operatorius
        Person& operator= (const Person& p);

        //išvedimo operatorius
        friend std::ostream& operator<< (std::ostream& o, const Person &p);

        //getter'iai
        std::string getName();
        std::string getSurname();

        //setter'is
        void setData(std::string name, std::string surname);

        //pure virtual function, klasė tampa abstrakčia
        virtual std::string statusas() = 0;


        ~Person(){};
};

