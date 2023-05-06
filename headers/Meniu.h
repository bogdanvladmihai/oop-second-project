//
// Created by vbogd on 5/1/2023.
//

#ifndef OOP_MENIU_H
#define OOP_MENIU_H

#include <iostream>
#include <vector>
#include <utility>
#include "Fel.h"

class Meniu {
private:
    std::vector<std::shared_ptr<Fel>> feluri_mancare;
    static const size_t MAX_FELURI;
public:
    Meniu();
    Meniu(const Meniu &other);
    void clear();
    void adaugaFel(const std::shared_ptr<Fel> &fel);
    void stergeFel(const size_t pos);
    double pretMeniu() const;
    friend std::ostream& operator << (std::ostream &out, const Meniu &M);
};

#endif //OOP_MENIU_H
