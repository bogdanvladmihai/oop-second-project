//
// Created by vbogd on 5/1/2023.
//

#ifndef OOP_INVITAT_H
#define OOP_INVITAT_H

#include "Meniu.h"

class Invitat {
private:
    std::shared_ptr<Meniu> M;
    std::vector<std::shared_ptr<Invitat>> impreuna, separat;
public:
    Invitat(const Meniu &M_);
    inline bool trebuie_separat(const std::shared_ptr<Invitat> &I);
    inline bool trebuie_impreuna(const std::shared_ptr<Invitat> &I);
};

#endif //OOP_INVITAT_H
