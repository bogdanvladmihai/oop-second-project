//
// Created by vbogd on 5/4/2023.
//

#ifndef OOP_SALA_H
#define OOP_SALA_H

#include <vector>
#include "Erori.h"
#include "Masa.h"

class Sala {
private:
    static const size_t MAX_NUMAR_MESE;
    bool used;
    std::vector<std::shared_ptr<Masa>> mese;
public:
    Sala();
    bool isUsed() const;
    void use();
    void goleste_sala();
    void stopUsing();
    void addMasa(std::shared_ptr<Masa> masa);
    void removeMasa(std::shared_ptr<Masa> masa);
    friend std::ostream& operator << (std::ostream &out, const Sala &S);
    double get_pret() const;
};

class Sala_Pool {
private:
    static const int NUMAR_MAX_SALI = 5;
    std::vector<Sala> sali{NUMAR_MAX_SALI};
public:
    Sala& get_sala();
};


#endif //OOP_SALA_H
