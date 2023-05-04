//
// Created by vbogd on 5/1/2023.
//

#ifndef OOP_INVITAT_H
#define OOP_INVITAT_H

#include "Meniu.h"
#include <iostream>

class Invitat {
private:
    std::string nume;
    std::shared_ptr<Meniu> M;
    std::vector<std::shared_ptr<Invitat>> impreuna, separat;
public:
    Invitat(const Meniu &M_, const std::string &nume_);
    const std::string get_nume() const;
    double get_cost() const;
    bool trebuie_separat(const std::shared_ptr<Invitat> &I);
    bool trebuie_impreuna(const std::shared_ptr<Invitat> &I);
    friend std::ostream& operator << (std::ostream&, const Invitat &I);
};

#endif //OOP_INVITAT_H
