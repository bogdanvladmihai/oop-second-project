//
// Created by vbogd on 5/3/2023.
//

#include "../headers/Angajat.h"

Angajat::Angajat(const std::string &nume_, int salariu_) : nume(nume_), salariu(salariu_) {}

int Angajat::getSalariu() const {
    return salariu;
}

void Angajat::setSalariu(const int salariu_) {
    salariu = salariu_;
}

bool Angajat::operator<(const Angajat &other) const {
    return salariu < other.salariu;
}

const std::string Angajat::get_nume() const {
    return nume;
}

std::ostream& operator << (std::ostream &out, const Angajat &A) {
    out << "Angajatul " << A.nume << " are salariu " << A.salariu << "\n";
    return out;
}

std::shared_ptr<Angajat> Angajat_Factory::Barman() {
    return std::make_shared<Angajat>(Angajat("Sergiu Lazar", 1800));
}
std::shared_ptr<Angajat> Angajat_Factory::Ospatar() {
    return std::make_shared<Angajat>(Angajat("Antonia Culea", 450));
}
std::shared_ptr<Angajat> Angajat_Factory::Bucatar() {
    return std::make_shared<Angajat>(Angajat("Bogdan Popa", 2500));
}
std::shared_ptr<Angajat> Angajat_Factory::Ajutor_Bucatarie() {
    return std::make_shared<Angajat>(Angajat("Sebastian Visan", 850));
}