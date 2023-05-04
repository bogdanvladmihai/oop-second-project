//
// Created by vbogd on 5/3/2023.
//

#ifndef OOP_ERORI_H
#define OOP_ERORI_H

#include <stdexcept>

class Eroare_Update_Masa : public std::logic_error {
public:
    Eroare_Update_Masa(const std::string &err) noexcept;
};

#endif //OOP_ERORI_H
