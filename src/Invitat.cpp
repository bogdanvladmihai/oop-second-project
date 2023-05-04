//
// Created by vbogd on 5/1/2023.
//

#include "../headers/Invitat.h"
#include <algorithm>

Invitat::Invitat(const Meniu &M_, const std::string &nume_) : nume(nume_), M(std::make_shared<Meniu>(M_)) {}

const std::string Invitat::get_nume() const {
    return nume;
}

double Invitat::get_cost() const {
    return M -> pretMeniu();
}

bool Invitat::trebuie_impreuna(const std::shared_ptr<Invitat> &I) {
    for (const auto &e : impreuna) {
        if (e -> nume == I -> nume) {
            return true;
        }
    }
    return false;
}

bool Invitat::trebuie_separat(const std::shared_ptr<Invitat> &I) {
    for (const auto &e : separat) {
        if (e -> nume == I -> nume) {
            return true;
        }
    }
    return false;
}

std::ostream& operator << (std::ostream &out, const Invitat &I) {
    out << "Invitatul " << I.nume << " are meniul urmator\n " << I.M << "\n";
    return out;
}