//
// Created by vbogd on 5/1/2023.
//

#ifndef OOP_MENIU_H
#define OOP_MENIU_H

#include <vector>
#include <utility>
#include "Fel.h"

class Meniu {
private:
    std::vector<std::shared_ptr<Fel>> feluri_mancare;
public:
    Meniu();
    void adaugaFel(const std::shared_ptr<Fel> &fel);
    double pretMeniu() const;
};

#endif //OOP_MENIU_H
