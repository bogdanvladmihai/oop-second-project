//
// Created by vbogd on 5/1/2023.
//

#include "Invitat.h"
#include <algorithm>

Invitat::Invitat(const Meniu &M_) : M(std::make_shared<Meniu>(M_)) {}

inline bool Invitat::trebuie_impreuna(const std::shared_ptr<Invitat> &I) {
    return std::find(impreuna.begin(), impreuna.end(), I) != impreuna.end();
}

inline bool Invitat::trebuie_separat(const std::shared_ptr<Invitat> &I) {
    return std::find(separat.begin(), separat.end(), I) != separat.end();
}