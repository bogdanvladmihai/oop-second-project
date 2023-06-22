//
// Created by vbogd on 5/1/2023.
//

#ifndef OOP_INVITAT_H
#define OOP_INVITAT_H

#include "Meniu.h"
#include <iostream>
#include <fstream>

class Invitat {
private:
    std::string nume;
    std::shared_ptr<Meniu> M;
public:
    Invitat(const Meniu &M_, const std::string &nume_);
    Invitat(const Invitat &other);
    void modif_meniu(const Meniu &men);
    double get_cost() const;
    friend std::ostream& operator << (std::ostream&, const Invitat &I);
    void add_fel(std::shared_ptr<Fel> F);
    void del_fel(const size_t pos);
    void writeData(std::ofstream &out);
};

#endif //OOP_INVITAT_H
