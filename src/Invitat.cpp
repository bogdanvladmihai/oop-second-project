//
// Created by vbogd on 5/1/2023.
//

#include "../headers/Invitat.h"
#include <algorithm>

Invitat::Invitat(const Meniu &M_, const std::string &nume_) : nume(nume_), M(std::make_shared<Meniu>(M_)) {}

Invitat::Invitat(const Invitat &other) : nume(other.nume), M(std::make_shared<Meniu>(*other.M)) {}

void Invitat::modif_meniu(const Meniu &men) {
    M = std::make_shared<Meniu>(men);
}

double Invitat::get_cost() const {
    return M -> pretMeniu();
}

std::ostream& operator << (std::ostream &out, const Invitat &I) {
    out << "Invitatul " << I.nume << " are meniul urmator\n " << I.M << "\n";
    return out;
}

void Invitat::add_fel(std::shared_ptr<Fel> F) {
    M ->adaugaFel(F);
}

void Invitat::del_fel(const size_t pos) {
    M ->stergeFel(pos);
}