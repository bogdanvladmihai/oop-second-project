//
// Created by vbogd on 5/3/2023.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <iostream>
#include <string>
#include <memory>
#include <fstream>

class Angajat {
private:
    std::string nume;
    int salariu;
public:
    Angajat(const std::string &nume_, int salariu_);
    Angajat(const Angajat &other);
    int getSalariu() const;
    void setSalariu(const int salariu_);
    bool operator < (const Angajat &other) const;
    friend std::ostream& operator << (std::ostream &out, const Angajat &A);
    void writeData(std::ofstream &out);
};

class Angajat_Factory {
public:
    static std::shared_ptr<Angajat> Barman();
    static std::shared_ptr<Angajat> Ospatar();
    static std::shared_ptr<Angajat> Bucatar();
    static std::shared_ptr<Angajat> Ajutor_Bucatarie();
};


#endif //OOP_ANGAJAT_H
