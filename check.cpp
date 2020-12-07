#include "check.h"

using std::cin;
using std::cout;

//tikrina, ar pasirinkimas lygus 1 arba 2
void checkChoice(int &a){
    cin >> a;
    do{
        try{
            if (cin.fail() || (a!=1 && a!=2)){
                throw std::runtime_error("\nNetinkamas pasirinkimas. ");
            }
        }
        catch(const std::runtime_error& e){
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Pasirinkite is naujo: ";
            cin >> a;
        }
    } while (cin.fail() || (a!=1 && a!=2));
}

//tikrina, ar įvestas skaičius yra teigiamas (>0)
void checkCount(int &a){
    cin >> a;
    do{
        try{
            if (cin.fail() || a < 1){
                throw std::runtime_error("\nNeteisingai ivestas kiekis. ");
            }
        }
        catch(const std::runtime_error& e){
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite is naujo: ";
            cin >> a;
        }
    } while (cin.fail() || a < 1);
}

//tikrina, ar įvestas skaičius yra iš intervalo 0-10 (tik sveikieji)
void checkGrade(float &a){
    cin >> a;
    do{
        try{
            if (cin.fail() || (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8 && a != 9 && a != 10)){
                throw std::runtime_error("\nKlaida pazymiuose. ");
            }
        }
        catch(const std::runtime_error& e){
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite egzamino ir namu darbu ivertinimus is naujo: ";
            cin >> a;
        }
    } while (cin.fail() || (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7 && a != 8 && a != 9 && a != 10));
}
